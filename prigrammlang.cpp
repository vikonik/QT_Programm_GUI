/*
Как установить выбор последней строки автоматически
Как применить изменения по нажатию Enter
Почему если вводить с клавиатуры, то иконка не определяется, а если скопировать и вставить текст из каого-нибудь элемента, то все нормально
*/
 
#include "prigrammlang.h"
#include "ui_prigrammlang.h"
#include <QListView>
    #include <QAbstractItemView>
#include <QMessageBox>

PrigrammLang::PrigrammLang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrigrammLang)
{
    ui->setupUi(this);
  //   list;// {"С++", "Python", "Java","C#", "PHP", "JavaScript"};
    list.append("С++");
    list.append("Python");
    list.append("Java");
    list.append("C#");
    list.append("PHP");
    list.append("JavaScript");

    model = new QStandardItemModel(list.size(),1,this);
    updateList(list);

//    ui->listView->setViewMode(QListView::IconMode);

//    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked);
}

PrigrammLang::~PrigrammLang()
{
    delete ui;
}

/**/
void PrigrammLang::updateList(QStringList list){

    for(int i = 0; i < model->rowCount(); ++i){
        QModelIndex index = model->index(i,0);
        QString str = list[i];
        model->setData(index,str,Qt::DisplayRole);
        model->setData(index,"ToolTip for " + str, Qt::ToolTipRole);
        model->setData(index,QIcon("./Icons/" + str + ".png"),Qt::DecorationRole);
    }

    if(ui->checkBox->isChecked()){
        ui->listView->setViewMode(QListView::IconMode);
    }
    else ui->listView->setViewMode(QListView::ListMode);
        ui->listView->setModel(model);

}

/**/
void PrigrammLang::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
     ui->listView->setViewMode(QListView::IconMode);
    }
    else ui->listView->setViewMode(QListView::ListMode);

}

/*
Удалить
*/
void PrigrammLang::on_pushButton_3_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->removeRow(row);
    list.removeAt(row);

}

/*
Добавить
*/
void PrigrammLang::on_pushButton_2_clicked()
{
    model->insertRow(model->rowCount());
//    int row = ui->listView->currentIndex().row();
//    ui->listView->setCurrentIndex(model->index(row,0,QItemSelectionModel::NoUpdate);
//    updateList(list);
//     ui->listView->setModel(model);
//  QString str = ui->listView->currentIndex().data().toString();
//  list.append(str);
//  updateList(list);
}

/*
  Изменить текст
*/
void PrigrammLang::on_pushButton_clicked()
{

    QString str = ui->listView->currentIndex().data().toString();
    int row = ui->listView->currentIndex().row();
    list.removeAt(row);
    list.insert(row,str);
    updateList(list);

}

/*
переместить вверх
*/
void PrigrammLang::on_pushButton_4_clicked()
{
    QString str = ui->listView->currentIndex().data().toString();
    int row = ui->listView->currentIndex().row();
    if(row > 0){
        QString str_2 = list.at(row-1);
        list.removeAt(row-1);
        list.insert(row-1,str);

        list.removeAt(row);
        list.insert(row,str_2);
        updateList(list);
    }
}

/*
Переместить вниз
*/
void PrigrammLang::on_pushButton_5_clicked()
{

}
