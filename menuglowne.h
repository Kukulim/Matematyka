#ifndef MENUGLOWNE_H
#define MENUGLOWNE_H

#include <QMainWindow>
#include "dodawanie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuGlowne; }
QT_END_NAMESPACE

class MenuGlowne : public QMainWindow
{
    Q_OBJECT

public:
    MenuGlowne(QWidget *parent = nullptr);
    ~MenuGlowne();

private slots:
    void on_dodawanieButton_clicked();

    void on_odejmowanieButton_clicked();


    void on_mnozenieButton_clicked();

    void on_dzielenieButton_clicked();

private:
    Ui::MenuGlowne *ui;
    Dodawanie *mDodawanie;
};
#endif // MENUGLOWNE_H
