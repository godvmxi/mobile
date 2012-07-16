#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDomDocument>
#include <QFile>
#include <QFileDialog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDomDocument xml;

private slots:
    void on_pushButton_para_check_clicked();
    void on_pushButton_build_xml_clicked();
};

#endif // MAINWINDOW_H
