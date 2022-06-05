#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCursor>

 



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    parseText = new ParseText();
    if (!parseText) close();

    listProgLang = new PrigrammLang();
    ui->verticalLayout_Task_2->addWidget(listProgLang);

    table = new Table();
    ui->verticalLayout_Task_3->addWidget(table);
}

MainWindow::~MainWindow()
{
    if (parseText) {
        delete parseText;
        parseText = NULL;//nullptr;
    }
    delete ui;
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString str = ui->plainTextEdit->toPlainText(); // получаем текст виджета
    if (parseText->change(str))                     // были ли примеры
    {
        ui->plainTextEdit->setPlainText(parseText->getText()); // заменяем текст примеры с результатами
        QTextCursor cursor = ui->plainTextEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->plainTextEdit->setTextCursor(cursor);
    }
}

void MainWindow::on_pushButton_1_clear_clicked()
{
    ui->plainTextEdit->clear();
}

