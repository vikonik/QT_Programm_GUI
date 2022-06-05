#include "table.h"
#include "ui_table.h"
 #include <QAbstractItemView>

 
Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
//    QStringList tableHheader;
//    tableHheader.append("№");
//    tableHheader.append("Имя компъютера");
//    tableHheader.append("IP");
//    tableHheader.append("MAC");
//    ui->tableWidget->setHorizontalHeaderLabels(tableHheader);
//    for(int i = 0; i < ui->tableWidget->rowCount();++i){
//        for(int j = 0; j < ui->tableWidget->columnCount(); ++j){
//            QTableWidgetItem *item = new QTableWidgetItem(QString("%1 %2").arg(tableHheader.at(0)).arg(tableHheader.at(1)));
//            ui->tableWidget->setItem(i,j,item);
//      }
//    }



//    ui->tableWidget->setRowCount(4);
//    ui->tableWidget->setColumnCount(6);
//    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"A"<<"B"<<"C"<<"D");


}

Table::~Table()
{
    delete ui;
}


