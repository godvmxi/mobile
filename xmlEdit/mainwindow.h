#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDomDocument>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
    class MainWindow;
}

typedef struct{
    //basic
    QString planName;
    QString position;


    quint64 start;
    quint64 end;
    quint64 block;
    quint64 fileSize;

    quint64 tempDevice;//0:

    quint64 fileNumber;
    quint64 tempPosition;//

}FLASH_INFO;
typedef struct{

    QString brand;
    QString model;
    quint64     flashSize;
    bool plan1;
    bool plan2;
    bool plan3;

}MOBILE_INFO;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDomDocument xml;
    FLASH_INFO plan1,plan2,plan3;
    MOBILE_INFO mobile;
    bool getParaInfo(void);
    bool calPlanData(int plan);
    bool generalCmdXml(FLASH_INFO *des,QDomElement *child,QDomElement *root);

private slots:
    void on_pushButton_para_check_clicked();
    void on_pushButton_build_xml_clicked();
    void enableALL(bool type);

};

#endif // MAINWINDOW_H
