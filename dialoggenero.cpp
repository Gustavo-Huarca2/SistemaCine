#include "dialoggenero.h"
#include "ui_dialoggenero.h"
#include "QSqlDatabase"
#include "QDebug"
#include "QSqlQuery"

DialogGenero::DialogGenero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGenero)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql10.freesqldatabase.com");
    db.setDatabaseName("sql10352486");
    db.setUserName("sql10352486");
    db.setPassword("9BPgk6jrLt");
    if (!db.open()) qDebug()<<"Error en base de datos";
    else qDebug()<<"Conectado Generos";
    QSqlQuery query("SELECT * FROM Genero ", db);
    if(query.size()==0){
        qDebug()<<"Vacio";
    }else{
        while(query.next()){
            QString gen=query.value(1).toString();
            ui->listagenero->addItem(gen);
        }
    }
}

DialogGenero::~DialogGenero()
{
    delete ui;
}

void DialogGenero::on_pushButton_clicked()
{
    QString genero=ui->newGenero->text();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql10.freesqldatabase.com");
    db.setDatabaseName("sql10352486");
    db.setUserName("sql10352486");
    db.setPassword("9BPgk6jrLt");
    if (!db.open()) qDebug()<<"Error en base de datos";
    else qDebug()<<"Conectado Generos";
    QSqlQuery query;
    query.prepare("INSERT INTO Genero (nombre) VALUES ('"+genero+"')");
    if(query.exec()){
        qDebug()<<"Insertado";
        ui->listagenero->addItem(genero);
        ui->newGenero->setText("");
    }else
        qDebug()<<"error";
}
