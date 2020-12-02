#ifndef DIALOGGENERO_H
#define DIALOGGENERO_H

#include <QDialog>

namespace Ui {
class DialogGenero;
}

class DialogGenero : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGenero(QWidget *parent = nullptr);
    ~DialogGenero();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogGenero *ui;
};

#endif // DIALOGGENERO_H
