#include "dodawanie.h"
#include "ui_dodawanie.h"

#include <QRandomGenerator64>
#include <QMessageBox>

Dodawanie::Dodawanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dodawanie)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->menuPoziomTrudnosciDodawaniePage);
}

Dodawanie::~Dodawanie()
{
    delete ui;
}

void Dodawanie::zadajPytanie()
{
    ui->punktyEdit->setText(QString::number(punkty));
    ui->zyciaEdit->setText(QString::number(zycia));
        do
        {
        skladnikPierwszy = QRandomGenerator::system()->bounded(stopienTrudnosci);
        skladnikDrogi = QRandomGenerator::system()->bounded(stopienTrudnosci);
        suma=skladnikPierwszy+skladnikDrogi;
        }
        while(suma>stopienTrudnosci);


    ui->skladnikPierwszyEdit->setText(QString::number(skladnikPierwszy));
    ui->skladnikDrogiEdit->setText(QString::number(skladnikDrogi));
}

void Dodawanie::zadajPytanieTrudne()
{
    ui->punktyEdit_2->setText(QString::number(punkty));
    ui->zyciaEdit_2->setText(QString::number(zycia));
    do
    {
    skladnikPierwszy = QRandomGenerator::system()->bounded(stopienTrudnosci);
    skladnikDrogi = QRandomGenerator::system()->bounded(stopienTrudnosci);
    skladnikTrzeci = QRandomGenerator::system()->bounded(stopienTrudnosci);
    suma=skladnikPierwszy+skladnikDrogi+skladnikTrzeci;
    }
    while(suma>50);


ui->skladnikPierwszyEdit_2->setText(QString::number(skladnikPierwszy));
ui->skladnikDrogiEdit_2->setText(QString::number(skladnikDrogi));
ui->skladnikTrzeciEdit_2->setText(QString::number(skladnikTrzeci));
}

void Dodawanie::sprawdzOdpowiedz()
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

void Dodawanie::sprawdzOdpowiedzTrudne()
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

void Dodawanie::on_sprawdzButton_clicked()
{
    sprawdzOdpowiedz();
    zadajPytanie();
}

void Dodawanie::on_latweButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dodawaniLatwePage);
    stopienTrudnosci=10;
    zadajPytanie();
}

void Dodawanie::on_srednieButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dodawaniLatwePage);
    stopienTrudnosci=20;
    zadajPytanie();
}

void Dodawanie::on_trudneButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dodawaniLatwePage);
    stopienTrudnosci=100;
    zadajPytanieTrudne();
}

void Dodawanie::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dodatanieTrudnePage);
    stopienTrudnosci=100;
    zadajPytanieTrudne();
}

void Dodawanie::on_sprawdzButton_2_clicked()
{
    sprawdzOdpowiedzTrudne();
    zadajPytanieTrudne();
}
