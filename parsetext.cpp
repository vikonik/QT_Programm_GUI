#include "parsetext.h"
#include "ui_mainwindow.h"

#define MIN(a, b) (a < b) ? a : b
 
/**/
ParseText::ParseText()
{
    text = "";
    preText = "";
    pos = 0;
}

/**/
bool ParseText::change(QString istr)
{
    qint32 length = MIN(MIN(text.length(), istr.length()), pos);
qint32 _tmppos = 0;
    preText = "";
    for (qint32 i = 0; i < length; i++)
    {
        if (text[i] != istr[i])
        {
            pos = i;
            break;
        }
    }
    const QChar *arStr = istr.constData();
    qint32 ppos = 0, lastp = -1; // курсор на начало символа, с которого будет осуществлять происк
    // метку #@
    bool chg = false; // есть изменения текста?
qint32 fndHead;
    for ( fndHead = istr.indexOf("#@", pos); // поиск первого примера в тексте
         fndHead != -1 && lastp != pos; // -1 - означает, что в строке нет (больше)примеров
         fndHead = istr.indexOf("#@", pos)
         )
    {
        preText.insert(preText.length(), &arStr[ppos], fndHead); // копируем текст до примера
        lastp = pos;
        pos = fndHead;
        int r = istr.indexOf('@', fndHead+2);//если есть равенство, то пример завершен
        int space = istr.indexOf(' ', fndHead);
        if ((r < space || space == -1) && r != -1) // проверяем, что равно для текущего примера, а не следующего
        {
            QString exampl = "";
            exampl.insert(0, &arStr[fndHead + 2], r - fndHead - 2);
            QString rez = calc(exampl);
//            QString rez = "calc(exampl)";
            preText += rez;
           _tmppos = r + 1;
            pos +=  (1 + rez.size()) ;
            chg = true;
        }

        preText.insert(preText.length(), &arStr[pos], istr.length() - _tmppos); //дописываем оставшийся текст


    }
return chg;
}


/*
а_право
промилле
R
евро
руб
RUB
*/
QString ParseText::calc(QString example)
{

    QString str = "";

    if(example.indexOf("а_право",0) != -1){
        str = "\u00A9";
    }

    if(example.indexOf("промилле",0) != -1){
        str = "\u00AE";
    }

    if(example.indexOf("R",0) != -1){
        str = "\u2030";
    }

    if((example.indexOf("RUB",0) != -1) || (example.indexOf("руб",0) != -1)){
        str = "\u20BD";
    }

    if(example.indexOf("евро",0) != -1){
        str = "\u20AC";
    }

    return str;
}

/**/
QString ParseText::getText()
{
    text = preText;
    return  text;
}
