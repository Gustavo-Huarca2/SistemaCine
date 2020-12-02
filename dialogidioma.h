#ifndef DIALOGIDIOMA_H
#define DIALOGIDIOMA_H

#include <QDialog>

namespace Ui {
class DialogIdioma;
}

class DialogIdioma : public QDialog
{
    Q_OBJECT

public:
    explicit DialogIdioma(QWidget *parent = nullptr);
    ~DialogIdioma();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogIdioma *ui;
};

#endif // DIALOGIDIOMA_H
