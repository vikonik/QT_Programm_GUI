#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>

namespace Ui {
class Table;
}
 
class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = 0);
    ~Table();

private:
    Ui::Table *ui;
    QStandardItemModel *model;

};

#endif // TABLE_H
