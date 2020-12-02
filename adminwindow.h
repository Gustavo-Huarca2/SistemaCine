#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <Administrador.h>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSqlDatabase>

namespace Ui {
class AdminWindow;
}

class QSqlTableModel;
class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr, Administrador *ad=nullptr);
    ~AdminWindow();
    Administrador *admi;
    QVBoxLayout *listai;
    QPushButton **peliarr;
    int cp;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_options_clicked();

private:
    Ui::AdminWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // ADMINWINDOW_H
