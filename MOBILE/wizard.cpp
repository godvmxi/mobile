#include "wizard.h"
#include "ui_wizard.h"

Wizard::Wizard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard)
{
    ui->setupUi(this);
}

Wizard::~Wizard()
{
    delete ui;
}
