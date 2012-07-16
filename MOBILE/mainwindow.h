#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDomDocument>
#include <QDomElement>
#include <QDomAttr>
#include <QStringList>
#include <QLabel>
#include <QMessageBox>
#include <QCloseEvent>

#include <QFile>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void display(void);
    void displayError(void);
    void initPara(void);
private:
    Ui::MainWindow *ui;
    QProcess *pointer;
    QLabel *statusBarLabel;
    QDomDocument backupDoc;
    QDomDocument userProfile;

    int checkUserProfile(QString profile);
    int execCmdList(QDomElement node);
    int checkError(int type,QString *check);

private slots:
    void on_pushButton_backup_clicked();
};


#endif // MAINWINDOW_H
