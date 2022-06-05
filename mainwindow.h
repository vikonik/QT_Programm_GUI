#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "parsetext.h"
//#include "listprogrammlang.h"
#include "prigrammlang.h"
#include "table.h"
 
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_plainTextEdit_textChanged();

    void on_pushButton_1_clear_clicked();



private:
    Ui::MainWindow *ui;
    ParseText *parseText;                // наш класс
    PrigrammLang *listProgLang;
    Table *table;
};

#endif // MAINWINDOW_H
