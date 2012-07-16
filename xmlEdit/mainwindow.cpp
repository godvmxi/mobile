#include "mainwindow.h"
#include "ui_mainwindow.h"
#include


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_build_xml_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "./",
                                                    tr("XML files (*.xml);;all files (*.*)"));
    qDebug()<<fileName;
    QFile *file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly)){
        qDebug()<<"文件打开错误";
    }

    QDomElement root = this->xml.createElement("rootNode");
    this->xml.appendChild(root);
    QDomElement child = xml.createElement("bk_1");
    root.appendChild(child);
    QDomText text = xml.createTextNode("你好\\></\\/，kugou");
//    child.appendChild(text);
//    QDomAttr attr = xml.createAttributeNS("name","jiangjingliang");
//    child.appendChild(attr);
    QDomElement element = xml.createElement("cmd");
    child.appendChild(element);

//    QDomProcessingInstruction value =xml.createProcessingInstruction("id","LG");
//    QDomEntityReference entity = xml.createEntityReference("hello");
//    entity.setNodeValue("kugou");
    QDomAttr attr =xml.createAttribute("attr1");
    attr.setNodeValue("attrValue1");
    element.setAttributeNodeNS(attr);
    attr =xml.createAttribute("attr2");
    attr.setNodeValue("attrValue2");
    element.setAttributeNodeNS(attr);
    attr =xml.createAttribute("attr3");
    attr.setNodeValue("attrValue3");
    element.setAttributeNodeNS(attr);
//    QDomDocumentFragment fragment = xml.createDocumentFragment();
//    fragment.setNodeValue("hello");
//    child.appendChild(fragment);



    child = xml.createElement("bk_2");
    root.appendChild(child);
    QTextStream out(file);
    xml.save(out,4);
    file->close();

}

void MainWindow::on_pushButton_para_check_clicked()
{
    qDebug()<<"hello world";

}
