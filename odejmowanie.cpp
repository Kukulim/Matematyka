#include "odejmowanie.h"
#include "ui_odejmowanie.h"

#include <QRandomGenerator>
#include <QMessageBox>

Odejmowanie::Odejmowanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Odejmowanie)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->menuPoziomTrudnosciOdejmowaniePage);
}

Odejmowanie::~Odejmowanie()
{
    delete ui;
}

void Odejmowanie::zadajPytanie()
{
    ui->punktyEdit->setText(QString::number(punkty));
    ui->zyciaEdit->setText(QString::number(zycia));
        do
        {
        skladnikPierwszy = QRandomGenerator::system()->bounded(stopienTrudnosci);
        skladnikDrogi = QRandomGenerator::system()->bounded(stopienTrudnosci);
        suma=skladnikPierwszy-skladnikDrogi;
        }
        while((suma<0)||(suma>stopienTrudnosci));


    ui->skladnikPierwszyEdit->setText(QString::number(skladnikPierwszy));
    ui->skladnikDrogiEdit->setText(QString::number(skladnikDrogi));
}

void Odejmowanie::zadajPytanieTrudne()
{
    ui->punktyEdit_2->setText(QString::number(punkty));
    ui->zyciaEdit_2->setText(QString::number(zycia));
    do
    {
    skladnikPierwszy = QRandomGenerator::system()->bounded(stopienTrudnosci);
    skladnikDrogi = QRandomGenerator::system()->bounded(stopienTrudnosci);
    skladnikTrzeci = QRandomGenerator::system()->bounded(stopienTrudnosci);
    suma=skladnikPierwszy-skladnikDrogi-skladnikTrzeci;
    }
    while((suma>50)||(suma<0));


ui->skladnikPierwszyEdit_2->setText(QString::number(skladnikPierwszy));
ui->skladnikDrogiEdit_2->setText(QString::number(skladnikDrogi));
ui->skladnikTrzeciEdit_2->setText(QString::number(skladnikTrzeci));
}


void Odejmowanie::sprawdzOdpowiedz()
{
    if (suma==ui->sumaEdit->text().toInt())
    {
        punkty++;
    }
    else
    {
        zycia--;
    }
    ui->punktyEdit->setText(QString::number(punkty));
    ui->zyciaEdit->setText(QString::number(zycia));
    ui->sumaEdit->clear();
    if(punkty==10)
    {
        QMessageBox::information(this,"WYGRANA","Gratulacje udało ci się, odpowiedzieć na wszystkie pytania");
    }
}

void Odejmowanie::sprawdzOdpowiedzTrudne()
{
    if (suma==ui->sumaEdit_2->text().toInt())
    {
        punkty++;
    }
    else
    {
        zycia--;
    }
    ui->punktyEdit_2->setText(QString::number(punkty));
    ui->zyciaEdit_2->setText(QString::number(zycia));
    ui->sumaEdit_2->clear();
    if(punkty==10)
    {
        QMessageBox::information(this,"WYGRANA","Gratulacje udało ci się, odpowiedzieć na wszystkie pytania");
    }
}

void Odejmowanie::on_latweButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->odejmowaniePage);
    stopienTrudnosci=10;
    zadajPytanie();
}

void Odejmowanie::on_srednieButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->odejmowaniePage);
    stopienTrudnosci=20;
    zadajPytanie();
}

void Odejmowanie::on_trudneButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->odejmowaniePage);
    stopienTrudnosci=100;
    zadajPytanie();
}

void Odejmowanie::on_bardzoTrudneButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->odejmowanieTrudnePage);
    stopienTrudnosci=100;
    zadajPytanieTrudne();
}

void Odejmowanie::on_sprawdzButton_clicked()
{
    sprawdzOdpowiedz();
    zadajPytanie();
}

void Odejmowanie::on_sprawdzButton_2_clicked()
{
    sprawdzOdpowiedzTrudne();
    zadajPytanieTrudne();
}
