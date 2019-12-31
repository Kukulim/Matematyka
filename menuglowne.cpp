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

