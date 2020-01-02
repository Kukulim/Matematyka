#ifndef DODAWANIE_H
#define DODAWANIE_H

#include <QDialog>

namespace Ui {
class Dodawanie;
}

class Dodawanie : public QDialog
{
    Q_OBJECT

public:
    explicit Dodawanie(QWidget *parent = nullptr);
    ~Dodawanie();

private:
    Ui::Dodawanie *ui;

public:
    int skladnikPierwszy=0;
    int skladnikDrogi=0;
    int skladnikTrzeci=0;
    int suma=0;

    int punkty=0;
    int zycia=5;
    int stopienTrudnosci=0;

    void zadajPytanie();
    void zadajPytanieTrudne();
    void sprawdzOdpowiedz();
    void sprawdzOdpowiedzTrudne();
    void ustawZycie();

    QString rodzajDzialania ="";

private slots:

    void on_sprawdzButton_clicked();
    void on_latweButton_clicked();
    void on_srednieButton_clicked();
    void on_trudneButton_clicked();
    void on_bardzoTrudneButton_clicked();
    void on_sprawdzTrudneButton_clicked();
};

#endif // DODAWANIE_H
