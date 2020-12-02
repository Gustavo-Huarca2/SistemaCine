#include "login.h"
#include "ui_login.h"
#include "peliwindow.h"
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <adminwindow.h>
#include "Administrador.h"
#include "Cliente.h"
#include "QMessageBox"

using namespace  std;
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginbutton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql10.freesqldatabase.com");
    db.setDatabaseName("sql10352486");
    db.setUserName("sql10352486");
    db.setPassword("9BPgk6jrLt");
    if (!db.open()) {
        qDebug()<<"Error en base de datos";
        QMessageBox::warning(nullptr, tr("Error"), tr("No hay conexion a internet\t\t"),QMessageBox::Ok);
        return;
    }
    else qDebug()<<"Conectado";
    QString us=ui->user->text();
    QString pass=ui->pass->text();
    QSqlQuery query("SELECT * FROM Persona WHERE username='"+us+"' AND pass='"+pass+"'", db);
    if(query.size()==0){
        qDebug()<<"Usuarion no encontrado";
        QMessageBox::warning(nullptr, tr("Error"), tr("Ususario no encontrado\t\t"),QMessageBox::Ok);
    }else{
        query.next();
        if(query.value(3).toString().compare("1")==0){
            Administrador *ad=new Administrador(query.value(1).toString(), query.value(4).toString(), query.value(5).toString(), query.value(2).toInt(), query.value(3).toString());
            AdminWindow *adm=new AdminWindow(nullptr, ad);
            adm->show();
        }else{
            Cliente *cl=new Cliente(query.value(1).toString(), query.value(4).toString(), query.value(5).toString(), query.value(2).toInt(), query.value(3).toString(), query.value(6).toString());
            PeliWindow *ma=new PeliWindow(nullptr, cl);
            ma->show();
        }
        this->close();
    }

}
