#ifndef ODEJMOWANIE_H
#define ODEJMOWANIE_H

#include <QDialog>

namespace Ui {
class Odejmowanie;
}

class Odejmowanie : public QDialog
{
    Q_OBJECT

public:
    explicit Odejmowanie(QWidget *parent = nullptr);
    ~Odejmowanie();

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

private slots:
    void on_latweButton_clicked();

    void on_srednieButton_clicked();

    void on_trudneButton_clicked();

    void on_bardzoTrudneButton_clicked();

    void on_sprawdzButton_clicked();

    void on_sprawdzButton_2_clicked();

private:
    Ui::Odejmowanie *ui;
};

#endif // ODEJMOWANIE_H
