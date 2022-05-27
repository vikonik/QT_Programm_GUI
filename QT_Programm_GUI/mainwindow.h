#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_calculateSQRT_clicked();

    void on_pushButton_calcTriangl_clicked();

    void on_pushButton_addText_clicked();

    void on_pushButton_replaseText_clicked();

    void on_pushButton_insertText_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
