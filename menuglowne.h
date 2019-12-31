#ifndef MENUGLOWNE_H
#define MENUGLOWNE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuGlowne; }
QT_END_NAMESPACE

class MenuGlowne : public QMainWindow
{
    Q_OBJECT

public:
    MenuGlowne(QWidget *parent = nullptr);
    ~MenuGlowne();

private:
    Ui::MenuGlowne *ui;
};
#endif // MENUGLOWNE_H
