#ifndef DIALOGADDMOVIE_H
#define DIALOGADDMOVIE_H

#include <QDialog>
#include <QCheckBox>

namespace Ui {
class DialogAddMovie;
}

class DialogAddMovie : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddMovie(QWidget *parent = nullptr);
    ~DialogAddMovie();
    QCheckBox **gearr;
    QString **idg;
    QCheckBox **idarr;
    QString **idi;
    int ci, cg;

private slots:
    void on_aceptar_clicked();

private:
    Ui::DialogAddMovie *ui;
};

#endif // DIALOGADDMOVIE_H
