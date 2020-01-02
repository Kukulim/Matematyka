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
}

void MenuGlowne::on_odejmowanieButton_clicked()
{
    mOdejmowanie = new Odejmowanie(this);
    mOdejmowanie->show();
}
