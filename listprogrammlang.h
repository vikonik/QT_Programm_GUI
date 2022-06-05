#ifndef LISTPROGRAMMLANG_H
#define LISTPROGRAMMLANG_H

#include <QWidget>
 
namespace Ui {
class ListProgrammLang;
}

class ListProgrammLang : public QWidget
{
    Q_OBJECT

public:
    explicit ListProgrammLang(QWidget *parent = 0);
    ~ListProgrammLang();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListProgrammLang *ui;
};

#endif // LISTPROGRAMMLANG_H
