#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString data)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mess=data;
    ui->username->setText(data);

}

MainWindow::~MainWindow()
{
    delete ui;
}

