#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMath.h>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
Решение квадратного уравнения
*/
void MainWindow::on_pushButton_calculateSQRT_clicked()
{
    int x1 = 0;
    int x2 = 0;
    QString s_x1;
    QString s_x2;

    int a = ui->spinBox_a->value();
    int b = ui->spinBox_b->value();
    int c = ui->spinBox_c->value();
    int D = qPow(b,2)-4*a*c;

    if(a !=0){
        if(D > 0){
            x1 = (-b - qSqrt(D))/2*a;
            x2 = (-b + qSqrt(D))/2*a;
            s_x1 = QString::number(x1);
            s_x2 = QString::number(x2);
            ui->label_resultSQRT->setText(tr("X1 = %1, X2 = %2").arg(s_x1).arg(s_x2));
        }

        if(D == 0){
            x1 = -b/2*a;
            s_x1 = QString::number(x1);
            ui->label_resultSQRT->setText(tr("X1 = X2 = %1").arg(s_x1));

        }

        if(D < 0){
            ui->label_resultSQRT->setText(("Корней нет"));

        }
    }
    else{
        x1 = -c/b;
        s_x1 = QString::number(x1);
        ui->label_resultSQRT->setText(tr("X1 = %1").arg(s_x1));

    }

}

/*
Вычисление стороны треугольника
*/
void MainWindow::on_pushButton_calcTriangl_clicked()
{
 //c = qSqrt(pow(a,2) + pow(b,2) + 2*a*b*qCos(C))
    int a = ui->spinBox_triangl_a->value();
    int b = ui->spinBox_triangl_b->value();
    double c = 0.0;
    double C = 0.0;

    if(ui->radioButton_rad->isChecked()) C = ui->doubleSpinBox_angl->value();
    else C = (ui->doubleSpinBox_angl->value()*M_PI)/180;

    int tmpA = pow(a,2);
    int tmpB = pow(b,2);
    double tmpC = qCos(C) * 1.0;
    double tmp = 2*a*b*tmpC * 1.0;
    c = qSqrt(tmpA + tmpB + tmp);
    //c = qSqrt(pow(a,2) + pow(b,2) + 2*a*b*qCos(C));
    ui->label_trianglRes->setText(tr("Сторона с = %1").arg(QString::number(c)));
}


/*
Строки
*/
void MainWindow::on_pushButton_addText_clicked()
{
    ui->plainTextEdit_2->appendPlainText(ui->plainTextEdit->toPlainText());
}

void MainWindow::on_pushButton_replaseText_clicked()
{
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText());
}

void MainWindow::on_pushButton_insertText_clicked()
{
    QString str = tr("<font color='red'>%1</font>").arg(ui->plainTextEdit->toPlainText());
    ui->plainTextEdit_2->appendHtml(str);
}
