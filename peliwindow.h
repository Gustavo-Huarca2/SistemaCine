#ifndef PELIWINDOW_H
#define PELIWINDOW_H

#include <QMainWindow>
#include "Cliente.h"

namespace Ui {
class PeliWindow;
}

class PeliWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PeliWindow(QWidget *parent = nullptr, Cliente *cl=nullptr);
    ~PeliWindow();

    Cliente *clie;

private slots:
    void on_options_clicked();

private:
    Ui::PeliWindow *ui;
};

#endif // PELIWINDOW_H
