#include "menuglowne.h"
#include "ui_menuglowne.h"


MenuGlowne::MenuGlowne(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuGlowne)
{
    ui->setupUi(this);
}

MenuGlowne::~MenuGlowne()
{
    delete ui;
}


void MenuGlowne::on_dodawanieButton_clicked()
{
    mDodawanie = new Dodawanie(this);
    mDodawanie->show();
    mDodawanie->rodzajDzialania="dodawanie";
}

void MenuGlowne::on_odejmowanieButton_clicked()
{
    mDodawanie = new Dodawanie(this);
    mDodawanie->show();
    mDodawanie->rodzajDzialania="odejmowanie";
}

void MenuGlowne::on_mnozenieButton_clicked()
{
    mDodawanie = new Dodawanie(this);
    mDodawanie->show();
    mDodawanie->rodzajDzialania="mnozenie";
}

void MenuGlowne::on_dzielenieButton_clicked()
{
    mDodawanie = new Dodawanie(this);
    mDodawanie->show();
    mDodawanie->rodzajDzialania="dzielenie";
}

