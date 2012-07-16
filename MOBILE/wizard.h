#ifndef WIZARD_H
#define WIZARD_H

#include <QDialog>

namespace Ui {
    class Wizard;
}

class Wizard : public QDialog
{
    Q_OBJECT

public:
    explicit Wizard(QWidget *parent = 0);
    ~Wizard();

private:
    Ui::Wizard *ui;
};

#endif // WIZARD_H
