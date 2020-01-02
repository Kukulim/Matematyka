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
    ui->sumaEdit->setPlaceholderText("?");
    if(rodzajDzialania=="dodawanie")
    {
        ui->plusEdit->setText("+");
        ui->punktyEdit->setText(QString::number(punkty));
        ustawZycie();
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
    if(rodzajDzialania=="odejmowanie")
    {
        ui->plusEdit->setText("-");
        ui->punktyEdit->setText(QString::number(punkty));
        ustawZycie();
        do
        {
            skladnikPierwszy = QRandomGenerator::system()->bounded(stopienTrudnosci);
            skladnikDrogi = QRandomGenerator::system()->bounded(stopienTrudnosci);
            suma=skladnikPierwszy-skladnikDrogi;
        }
        while(suma>stopienTrudnosci||suma<0);


        ui->skladnikPierwszyEdit->setText(QString::number(skladnikPierwszy));
        ui->skladnikDrogiEdit->setText(QString::number(skladnikDrogi));
    }
    if(rodzajDzialania=="mnozenie")
    {
        ui->plusEdit->setText("*");
        ui->punktyEdit->setText(QString::number(punkty));
        ustawZycie();
        do
        {
            skladnikPierwszy = QRandomGenerator::system()->bounded(10);
            skladnikDrogi = QRandomGenerator::system()->bounded(10);
            suma=skladnikPierwszy*skladnikDrogi;
        }
        while(suma>stopienTrudnosci);


        ui->skladnikPierwszyEdit->setText(QString::number(skladnikPierwszy));
        ui->skladnikDrogiEdit->setText(QString::number(skladnikDrogi));
    }
    if(rodzajDzialania=="dzielenie")
    {
        ui->plusEdit->setText("/");
        ui->punktyEdit->setText(QString::number(punkty));
        ustawZycie();
        do
        {
            skladnikPierwszy = QRandomGenerator::system()->bounded(20);
            skladnikDrogi = QRandomGenerator::system()->bounded(5)+1;
            skladnikPierwszy= skladnikDrogi*skladnikPierwszy;
            suma=skladnikPierwszy/skladnikDrogi;
        }
        while(suma>stopienTrudnosci);


        ui->skladnikPierwszyEdit->setText(QString::number(skladnikPierwszy));
        ui->skladnikDrogiEdit->setText(QString::number(skladnikDrogi));
    }
}

void Dodawanie::zadajPytanieTrudne()
{
    ui->sumaEdit_2->setPlaceholderText("?");
    if(rodzajDzialania=="dodawanie")
    {
        ui->plusTrudneEdit->setText("+");
        ui->plusDwaTrudneEdit->setText("+");
        ui->punktyEdit_2->setText(QString::number(punkty));
        ustawZycie();
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
    if(rodzajDzialania=="odejmowanie")
    {

        {
            ui->plusTrudneEdit->setText("-");
            ui->plusDwaTrudneEdit->setText("-");
            ui->punktyEdit_2->setText(QString::number(punkty));
            ustawZycie();
            do
            {
                skladnikPierwszy = QRandomGenerator::system()->bounded(stopienTrudnosci);
                skladnikDrogi = QRandomGenerator::system()->bounded(stopienTrudnosci);
                skladnikTrzeci = QRandomGenerator::system()->bounded(stopienTrudnosci);
                suma=skladnikPierwszy-skladnikDrogi-skladnikTrzeci;
            }
            while(suma>stopienTrudnosci||suma<0);


            ui->skladnikPierwszyEdit_2->setText(QString::number(skladnikPierwszy));
            ui->skladnikDrogiEdit_2->setText(QString::number(skladnikDrogi));
            ui->skladnikTrzeciEdit_2->setText(QString::number(skladnikTrzeci));
        }
    }
    if(rodzajDzialania=="mnozenie")
    {

        {
            ui->plusTrudneEdit->setText("*");
            ui->plusDwaTrudneEdit->setText("*");
            ui->punktyEdit_2->setText(QString::number(punkty));
            ustawZycie();
            do
            {
                skladnikPierwszy = QRandomGenerator::system()->bounded(10);
                skladnikDrogi = QRandomGenerator::system()->bounded(10);
                skladnikTrzeci = QRandomGenerator::system()->bounded(10);
                suma=skladnikPierwszy*skladnikDrogi*skladnikTrzeci;
            }
            while(suma>stopienTrudnosci||suma>100);


            ui->skladnikPierwszyEdit_2->setText(QString::number(skladnikPierwszy));
            ui->skladnikDrogiEdit_2->setText(QString::number(skladnikDrogi));
            ui->skladnikTrzeciEdit_2->setText(QString::number(skladnikTrzeci));
        }
    }
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
    ustawZycie();
    ui->sumaEdit->clear();
    ui->sumaEdit->setPlaceholderText("?");
    if(punkty==10)
    {
        QMessageBox::StandardButton odpowiedz;
        odpowiedz = QMessageBox::information(this,"WYGRANA","Gratulacje udało ci się, odpowiedzieć na wszystkie pytania",QMessageBox::Yes | QMessageBox::No);
        if(odpowiedz==QMessageBox::Yes)
        {
            zycia=5;
            punkty=0;
        }
        if(odpowiedz==QMessageBox::No)
        {

        }

    }
    if(zycia==0)
    {
    QMessageBox::StandardButton odpowiedz;
    odpowiedz = QMessageBox::information(this,"PRZEGRAŁAŚ","PRZEGRAŁAŚ, spróbuj jeszcze raz.",QMessageBox::Yes | QMessageBox::No );

    if(odpowiedz==QMessageBox::Yes)
    {
        zycia=5;
        punkty=0;
    }
    if(odpowiedz==QMessageBox::No)
    {

    }

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
    ustawZycie();
    ui->sumaEdit_2->clear();
    if(punkty==10)
    {
        QMessageBox::StandardButton odpowiedz;
        odpowiedz = QMessageBox::information(this,"WYGRANA","Gratulacje udało ci się, odpowiedzieć na wszystkie pytania",QMessageBox::Yes);
        if(odpowiedz==QMessageBox::Yes)
        {
            zycia=5;
            punkty=0;
        }

    }
    if(zycia==0)
    {
    QMessageBox::StandardButton odpowiedz;
    odpowiedz = QMessageBox::information(this,"PRZEGRAŁAŚ","PRZEGRAŁAŚ, spróbuj jeszcze raz.",QMessageBox::Yes);

    if(odpowiedz==QMessageBox::Yes)
    {
        zycia=5;
        punkty=0;
    }
}
}

void Dodawanie::ustawZycie()
{

    QPixmap zycie5(":/img/5zyc");
    QPixmap zycie4(":/img/4zyc");
    QPixmap zycie3(":/img/3zyc");
    QPixmap zycie2(":/img/2zyc");
    QPixmap zycie1(":/img/1zyc");
    QPixmap zycie0(":/img/0zyc");
    if (zycia==5)
    {
        ui->zycieGrafikaView->setPixmap(zycie5);
        ui->zycieTrudneGrafikaView->setPixmap(zycie5);
    }
    if (zycia==4)
    {
        ui->zycieGrafikaView->setPixmap(zycie4);
        ui->zycieTrudneGrafikaView->setPixmap(zycie4);
    }
    if (zycia==3)
    {
        ui->zycieGrafikaView->setPixmap(zycie3);
        ui->zycieTrudneGrafikaView->setPixmap(zycie3);
    }
    if (zycia==2)
    {
        ui->zycieGrafikaView->setPixmap(zycie2);
        ui->zycieTrudneGrafikaView->setPixmap(zycie2);
    }
    if (zycia==1)
    {
        ui->zycieGrafikaView->setPixmap(zycie1);
        ui->zycieTrudneGrafikaView->setPixmap(zycie1);
    }
    if (zycia==0)
    {
        ui->zycieGrafikaView->setPixmap(zycie0);
        ui->zycieTrudneGrafikaView->setPixmap(zycie0);
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

void Dodawanie::on_trudneButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->dodawaniLatwePage);
    stopienTrudnosci=100;
    zadajPytanie();
}

void Dodawanie::on_bardzoTrudneButton_clicked()
{
    if(rodzajDzialania=="dzielenie")
    {
        ui->stackedWidget->setCurrentWidget(ui->dodawaniLatwePage);
        zadajPytanie();
        stopienTrudnosci=400;
    }
    else
    ui->stackedWidget->setCurrentWidget(ui->dodatanieTrudnePage);
    stopienTrudnosci=100;
    zadajPytanieTrudne();
}

void Dodawanie::on_sprawdzTrudneButton_clicked()
{
    sprawdzOdpowiedzTrudne();
    zadajPytanieTrudne();
}
