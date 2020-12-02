#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "genero.h"
#include "idiomawindow.h"
#include "dialogaddmovie.h"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QDebug"
#include "login.h"
#include "QSqlTableModel"
#include "dialoggenero.h"
#include "dialogidioma.h"

AdminWindow::AdminWindow(QWidget *parent, Administrador *per) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    admi=per;
    ui->userbutton->setText(per->obtener_usuario());
    listai=new QVBoxLayout();
    db = QSqlDatabase::addDatabase("QMYSQL");
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
        /*
        peliarr=new QPushButton*[query.size()];
        cp=0;
        while(query.next()){
            QPushButton *item=new QPushButton();
            item->setText(query.value(1).toString());
            item->setFlat(true);
            listai->addWidget(item);
            peliarr[cp]=item;
            cp++;
        }*/
    }
    //listai->addWidget(new QFrame());
       model=new QSqlTableModel(this);
       model->setTable("Pelicula");
       model->setEditStrategy(QSqlTableModel::OnManualSubmit);
       model->select();
       model->setHeaderData(1, Qt::Horizontal, tr("Nombre"));
    ui->pelitable->setModel(model);
    ui->pelitable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pelitable->hideColumn(0);

}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_3_clicked()
{
    DialogGenero generowindow;
    generowindow.setModal(true);
    generowindow.exec();
    model->select();
}

void AdminWindow::on_pushButton_2_clicked()
{
    DialogIdioma idiomawindow;
    idiomawindow.setModal(true);
    idiomawindow.exec();
    model->select();
}

void AdminWindow::on_pushButton_clicked()
{
    DialogAddMovie peliwindow;
    peliwindow.setModal(true);
    peliwindow.exec();
    model->select();
}

void AdminWindow::on_options_clicked()
{
    Login *l=new Login();
    l->show();
    this->close();
}
/*
void AdminWindow::on_actualizar_clicked()
{
    QLayout *listala;
    listala=ui->PeliContents->layout();
    for(int i=0;i<cp;i++){
        listai->removeWidget(peliarr[i]);
    }

    QSqlQuery query("SELECT * FROM Pelicula ", db);
    if(query.size()==0){
        qDebug()<<"VAcio";
    }else{
        while(query.next()){
            QPushButton *item=new QPushButton();
            item->setText(query.value(1).toString());
            item->setFlat(true);
            //listai->addWidget(item);
        }
    }
    listai->addWidget(new QFrame());
    ui->PeliContents->setLayout(listai);
    ui->PeliContents->repaint();
}*/
