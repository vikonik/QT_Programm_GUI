#include "listprogrammlang.h"
#include "ui_listprogrammlang.h"
#include <QMessageBox>

ListProgrammLang::ListProgrammLang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListProgrammLang)
{ 
    ui->setupUi(this);

    //списки
    ui->listWidget->addItem("qwrerqew");
    ui->listWidget->addItem("sssss");
    ui->listWidget->addItem("dsfgdsfh");

    //таблицы
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"A"<<"B"<<"C"<<"D");
    for(int i = 0; i < ui->tableWidget->rowCount();++i){
        for(int j = 0; j < ui->tableWidget->columnCount(); ++j){
            QTableWidgetItem *item = new QTableWidgetItem(QString("Ячейка № %1 %2").arg(i).arg(j));
            ui->tableWidget->setItem(i,j,item);
      }
    }
//деревья
    ui->treeWidget->setHeaderLabel("Объекты");
    ui->treeWidget->setColumnCount(1);
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,"Объект 1");
    QTreeWidgetItem *child_1 = new QTreeWidgetItem();
    child_1->setText(0,"Объект 1.1");
    item->addChild(child_1);
    QTreeWidgetItem *child_2 = new QTreeWidgetItem();
    child_2->setText(0,"Объект 1.2");
    item->addChild(child_2);
    ui->treeWidget->addTopLevelItem(item);

}

ListProgrammLang::~ListProgrammLang()
{
    delete ui;
}

void ListProgrammLang::on_pushButton_clicked()
{
    QString str =   ui->tableWidget->currentItem()->text();
    QMessageBox::information(this,"INFO",str);
}
