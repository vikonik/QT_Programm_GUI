#ifndef PRIGRAMMLANG_H
#define PRIGRAMMLANG_H

#include <QWidget>
#include <QStandardItemModel>
namespace Ui {
class PrigrammLang;
}
 
class PrigrammLang : public QWidget
{
    Q_OBJECT

public:
    explicit PrigrammLang(QWidget *parent = 0);
    ~PrigrammLang();

private slots:
    void updateList(QStringList list);

    void on_checkBox_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::PrigrammLang *ui;
    QStandardItemModel *model;
    QStringList list;
};

#endif // PRIGRAMMLANG_H
