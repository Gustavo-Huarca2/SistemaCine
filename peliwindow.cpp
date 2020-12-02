#include "peliwindow.h"
#include "ui_peliwindow.h"
#include "QGridLayout"
#include "QPushButton"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QDebug"
#include "login.h"

PeliWindow::PeliWindow(QWidget *parent, Cliente *cl) :
    QMainWindow(parent),
    ui(new Ui::PeliWindow)
{
    ui->setupUi(this);
    clie=cl;
    ui->userbutton->setText(clie->obtener_usuario());
    /*QMenu *menuuser=new QMenu();
    menuuser->addAction("salir");
    ui->options->setMenu(menuuser);*/
    clie=cl;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql10.freesqldatabase.com");
    db.setDatabaseName("sql10352486");
    db.setUserName("sql10352486");
    db.setPassword("9BPgk6jrLt");
    if (!db.open()) qDebug()<<"Error en base de datos";
    else qDebug()<<"Conectado";
    QSqlQuery query("SELECT * FROM Pelicula ", db);
    if(query.size()==0){
        qDebug()<<"VAcio";
    }else{
        QGridLayout *ele=new QGridLayout(this);
        int i=0;
        for(int j=0;j<3&&query.next();j++){
            QString nom=query.value(1).toString();
            QPushButton *but=new QPushButton(nom);
            but->setMinimumSize(20, 200);
            QString qss = "background-color: #0db2f8;";
            but->setStyleSheet(qss);
            ele->addWidget(but, i, j);
            if(j==2) {
                i++;
                j=-1;
            }
        }

        ui->peli_lista->setLayout(ele);
        //QSqlQuery query2("SELECT * FROM Generos ", db);

    }
}

PeliWindow::~PeliWindow()
{
    delete ui;
}

void PeliWindow::on_options_clicked()
{
    Login *l=new Login();
    l->show();
    this->close();
}
