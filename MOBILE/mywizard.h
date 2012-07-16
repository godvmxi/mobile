#ifndef MYWIZARD_H
#define MYWIZARD_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDomDocument>
#include <QDomElement>
#include <QDomAttr>
#include <QStringList>
#include <QLabel>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTextCodec>

#include <QFile>

namespace Ui {
    class myWizard;
}

class myWizard : public QDialog
{
    Q_OBJECT

public:
    explicit myWizard(QWidget *parent = 0);
    ~myWizard();
    void registerFunc(void);
    void initSystem(void);

private:
    Ui::myWizard *ui;
    QDomDocument phoneDoc;

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_register_clicked();
    void on_pushButton_exit_clicked();
    void getPhoneModel(int index);
    void registerUser(void);
    void loginInUser(void);
};

#endif // MYWIZARD_H
