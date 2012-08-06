#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_build_xml->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_build_xml_clicked()
{
    QDomDocument xml;
    QDomElement root,child,element,plan,cmd,plan1;
    QDomAttr attr;

    xml.clear();
    root = xml.createElement("backupCmd");
    attr = xml.createAttribute("attribute");
    attr.setNodeValue(tr(""));
    root.setAttributeNodeNS(attr);

    attr = xml.createAttribute("backup_plan_num");
    int planNum  = 0;
    planNum = this->mobile.plan1 ? planNum+1 :planNum;
    planNum = this->mobile.plan2 ? planNum+1 :planNum;
    planNum = this->mobile.plan3 ? planNum+1 :planNum;
    QString tmp;
    tmp.sprintf("%d",planNum);
    attr.setNodeValue(tmp);

    root.setAttributeNodeNS(attr);

    attr = xml.createAttribute("default_plan_index");
    attr.setNodeValue(tr("1"));
    root.setAttributeNodeNS(attr);

    xml.appendChild(root);

    //root node set ok

    if(this->mobile.plan1){
        plan1 = xml.createElement("bk_1");

        attr = xml.createAttribute("name");
        attr.setNodeValue(tr("back_up_plan_1"));
        plan1.setAttributeNodeNS(attr);
        attr = xml.createAttribute("cmdlist");
        attr.setNodeValue(tr("0"));
        plan1.setAttributeNodeNS(attr);//creat plan
        generalCmdXml(&this->plan1,&plan1,&root);
        root.appendChild(plan1);
    }

    if(this->mobile.plan2){
        plan = xml.createElement("bk_2");
        attr = xml.createAttribute("name");
        attr.setNodeValue(tr("back_up_plan_2"));
        plan.setAttributeNodeNS(attr);
        attr = xml.createAttribute("cmdlist");
        attr.setNodeValue(tr("0"));
        plan.setAttributeNodeNS(attr);//creat plan
        generalCmdXml(&this->plan2,&plan,&root);
        root.appendChild(plan);
    }


    if(this->mobile.plan3){
        plan = xml.createElement("bk_3");

        attr = xml.createAttribute("name");
        attr.setNodeValue(tr("back_up_plan_3"));
        plan.setAttributeNodeNS(attr);
        attr = xml.createAttribute("cmdlist");
        attr.setNodeValue(tr("0"));
        plan.setAttributeNodeNS(attr);//creat plan
        generalCmdXml(&this->plan3,&plan,&root);
        root.appendChild(plan);
    }


    QString xmlName;
    xmlName.sprintf("./%s_%s.xml",this->mobile.brand.toLatin1().data(),this->mobile.model.toLatin1().data());

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    xmlName,
                                                    tr("XML files (*.xml);;all files (*.*)"));
    qDebug()<<fileName;
    QFile *file = new QFile(fileName);
    if(!file->open(QIODevice::ReadWrite|QIODevice::Truncate)){
        qDebug()<<"文件打开错误";
    }
 //   file->resize(0);
    QTextStream out(file);
    xml.save(out,4);
    file->close();
    delete(file);

}

void MainWindow::on_pushButton_para_check_clicked()
{
    static int state = 0;
    if(state == 0){
        ui->pushButton_build_xml->setEnabled(true);
        ui->pushButton_para_check->setText(tr("解锁参数"));
        if(getParaInfo()  == false )
            return;
        state = 1;
        enableALL(false);


    }
    else{
        ui->pushButton_build_xml->setEnabled(false);
        ui->pushButton_para_check->setText(tr("参数检查"));
        state = 0;
        enableALL(true);

    }
}
void MainWindow::enableALL(bool type){
    ui->checkBox_1->setEnabled(type);
    ui->checkBox_2->setEnabled(type);
    ui->checkBox_3->setEnabled(type);
    ui->comboBox_bs_plan_1->setEnabled(type);
    ui->comboBox_bs_plan_2->setEnabled(type);
    ui->comboBox_bs_plan_3->setEnabled(type);
    ui->comboBox_filesize_1->setEnabled(type);
    ui->comboBox_filesize_2->setEnabled(type);
    ui->comboBox_filesize_3->setEnabled(type);
    ui->lineEdit_start_plan_1->setEnabled(type);
    ui->lineEdit_start_plan_2->setEnabled(type);
    ui->lineEdit_start_plan_3->setEnabled(type);
    ui->lineEdit_stop_plan_1->setEnabled(type);
    ui->lineEdit_stop_plan_2->setEnabled(type);
    ui->lineEdit_stop_plan_3->setEnabled(type);
    ui->lineEdit_brand->setEnabled(type);
    ui->lineEdit_memory->setEnabled(type);
    ui->lineEdit_model->setEnabled(type);
}

bool MainWindow::getParaInfo(void){
    this->mobile.brand = ui->lineEdit_brand->text();
    this->mobile.model = ui->lineEdit_model->text();
    bool ok;
    this->mobile.flashSize = ui->lineEdit_memory->text().toULongLong(&ok,10);
    this->mobile.flashSize = this->mobile.flashSize*1024*1024;
    this->mobile.plan1 = ui->checkBox_1->checkState() == Qt::Checked ? true :false;
    this->mobile.plan2 = ui->checkBox_2->checkState() == Qt::Checked ? true :false;
    this->mobile.plan3 = ui->checkBox_3->checkState() == Qt::Checked ? true :false;

    if(this->mobile.plan1){
        this->plan1.start   =   ui->lineEdit_start_plan_1->text().toULongLong(0,10);
        this->plan1.end     =   ui->lineEdit_stop_plan_1->text().toULongLong(0,10);
        this->plan1.tempDevice = ui->comboBox_device_1->currentIndex();
        this->plan1.planName = QString(tr("plan_1"));
        switch(ui->comboBox_bs_plan_1->currentIndex()){
        case 0:
            this->plan1.block = 512;//0.5K
            break;
        case 1:
            this->plan1.block = 1024;//1k
            break;
        case 2:
            this->plan1.block = 10240;//10k
            break;
        case 3:
            this->plan1.block = 102400;//100k
            break;
        case 4:
            this->plan1.block = 1024000;//1M
            break;
        case 5:
            this->plan1.block = 10240000;//10M
            break;
        case 6:
            this->plan1.block = 102400000;//100M
            break;
        default :
            this->plan1.block = 1024;
        }
        switch(ui->comboBox_filesize_1->currentIndex()){
        case 0:
            this->plan1.fileSize = 1024*102400;//无限制
            break;
        case 1:
            this->plan1.fileSize = 1024000*64;//64M
            break;
        case 2:
            this->plan1.fileSize = 1024000*128;//128M
            break;
        case 3:
            this->plan1.fileSize = 1024000*256;//256M
            break;
        case 4:
            this->plan1.fileSize = 1024000*512;//
            break;
        case 5:
            this->plan1.fileSize = 1024000*1024;//
            break;

        default :
            this->plan1.fileSize = 1024000*256;//
            break;
        }
        if(!calPlanData(1))
            return false;
    }

    if(this->mobile.plan2){
        this->plan2.start   =   ui->lineEdit_start_plan_2->text().toInt(0,10);
        this->plan2.end     =   ui->lineEdit_stop_plan_2->text().toInt(0,10);
        this->plan2.tempDevice = ui->comboBox_device_2->currentIndex();
        this->plan2.planName = QString(tr("plan_2"));
        switch(ui->comboBox_bs_plan_2->currentIndex()){
        case 0:
            this->plan2.block = 512;//0.5K
            break;
        case 1:
            this->plan2.block = 1024;//1k
            break;
        case 2:
            this->plan2.block = 10240;//10k
            break;
        case 3:
            this->plan2.block = 102400;//100k
            break;
        case 4:
            this->plan2.block = 1024000;//1M
            break;
        case 5:
            this->plan2.block = 10240000;//10M
            break;
        case 6:
            this->plan2.block = 102400000;//100M
            break;
        default :
            this->plan2.block = 1024;
        }
        switch(ui->comboBox_filesize_2->currentIndex()){
        case 0:
            this->plan2.fileSize = 1024000*1024000;//无限制
            break;
        case 1:
            this->plan2.fileSize = 1024000*64;//64M
            break;
        case 2:
            this->plan2.fileSize = 1024000*128;//128M
            break;
        case 3:
            this->plan2.fileSize = 1024000*256;//256M
            break;
        case 4:
            this->plan2.fileSize = 1024000*512;//
            break;
        case 5:
            this->plan2.fileSize = 1024000*1024;//
            break;

        default :
            this->plan2.fileSize = 1024000*256;//
            break;
        }
        if(!calPlanData(2))
            return false;

    }

    if(this->mobile.plan3){
        this->plan3.start = ui->lineEdit_start_plan_3->text().toInt(0,10);
        this->plan3.end     =   ui->lineEdit_stop_plan_3->text().toInt(0,10);
        this->plan3.tempDevice = ui->comboBox_device_3->currentIndex();
        this->plan3.planName = QString(tr("plan_3"));
        switch(ui->comboBox_bs_plan_3->currentIndex()){
        case 0:
            this->plan3.block = 512;//0.5K
            break;
        case 1:
            this->plan3.block = 1024;//1k
            break;
        case 2:
            this->plan3.block = 10240;//10k
            break;
        case 3:
            this->plan3.block = 102400;//100k
            break;
        case 4:
            this->plan3.block = 1024000;//1M
            break;
        case 5:
            this->plan3.block = 10240000;//10M
            break;
        case 6:
            this->plan3.block = 102400000;//100M
            break;
        default :
            this->plan3.block = 1024;
        }
        switch(ui->comboBox_filesize_3->currentIndex()){
        case 0:
            this->plan3.fileSize = 1024000*1024000;//无限制
            break;
        case 1:
            this->plan3.fileSize = 1024000*64;//64M
            break;
        case 2:
            this->plan3.fileSize = 1024000*128;//128M
            break;
        case 3:
            this->plan3.fileSize = 1024000*256;//256M
            break;
        case 4:
            this->plan3.fileSize = 1024000*512;//
            break;
        case 5:
            this->plan3.fileSize = 1024000*1024;//
            break;

        default :
            this->plan3.fileSize = 1024000*256;//
            break;
        }
        if(!calPlanData(3)){
            qDebug()<<"plan3";
            return false;
        }
    }
    return true;
}

bool MainWindow::calPlanData(int plan)
{
    FLASH_INFO *des;

    switch(plan){
    case 1:
        des = &this->plan1;
        break;
    case 2:
        des = &this->plan2;
        break;
    case 3:
        des = &this->plan3;
        break;
    default:
        return false;
    }
    qDebug()<<des->planName;
    QMessageBox info;
    info.addButton(QMessageBox::Ok);
    info.setIcon(QMessageBox::Critical);
    info.setWindowTitle("错误");

//    info.addButton(QMessageBox::Ok|QMessageBox::Abort);
    //info.setText(tr("请重新输入密码、邮箱,选择对应的手机型号，如果找不到您的手机型号，请选择其他，并且你的其他中表示出的你的手机型号，功能加紧研发中，如果有特殊需求，请邮件联系godvmxi@gmail.com"));
//    info.exec();
    quint64 tmp;


    //if(a*b>c)
    if(((des->start) * (des->block)) >(this->mobile.flashSize))
    {
        info.setText("备份开始区域大于总flash大小，请重新设置");
        info.exec();
        return false;
    }
    if(des->end <= des->start){
        info.setText("开始地址必须大于结束地址，请重新设置");
        info.exec();
        return false;
    }
    if(des->start > this->mobile.flashSize)
    {
        info.setText("开始地址大于flash大小，请重新设置");
        info.exec();
        return false;
    }
    if(des->end == 0)
    {
        info.setText("结束地址设置错误");
        info.exec();
        return false;
    }

    //begin cal data
    des->fileNumber = (des->end - des->start)*des->block / des->fileSize;
    if((des->block*(des->end -  des->start))%des->fileSize != 0){
        des->fileNumber++;
    }
    qDebug()<<des->planName<<" : file number:"<<des->fileNumber;
    return true;
}
bool MainWindow::generalCmdXml(FLASH_INFO *des,QDomElement *child,QDomElement *root)
{
    QDomElement cmd;
    QDomAttr attr;
    ////add add cmd list
    cmd = xml.createElement("cmd");
    child->appendChild(cmd);
    attr = xml.createAttribute("type");
    attr.setNodeValue(tr("3"));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("errorCheckType");
    attr.setNodeValue(tr("0"));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("timeOut");
    attr.setNodeValue(tr("300"));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("errorString");
    attr.setNodeValue(tr(""));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("cmd");
    attr.setNodeValue(tr("请打开USB，并将手机连接到电脑，确保设备内存和SD卡有200M以上的空间\n"));
    cmd.setAttributeNodeNS(attr);
    ////end add a cmd list
    ////add add cmd list
    cmd = xml.createElement("cmd");
    child->appendChild(cmd);
    attr = xml.createAttribute("type");
    attr.setNodeValue(tr("1"));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("errorCheckType");
    attr.setNodeValue(tr("1"));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("timeOut");
    attr.setNodeValue(tr("300"));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("errorString");
    attr.setNodeValue(tr("error"));
    cmd.setAttributeNodeNS(attr);
    attr = xml.createAttribute("cmd");
    attr.setNodeValue(tr("adb wait-for-device"));
    cmd.setAttributeNodeNS(attr);
    ////end add a cmd list


//     plan.appendChild(cmd);
    QString adbCmd,copyCmd,clearCmd;
    QString fileName;
    QString tempDevice;
    QString desDir = des->planName;

    switch(des->tempDevice){
    case 0:
        tempDevice.sprintf("cache");
        break;
    case 1:
        tempDevice.sprintf("ex-sdcard");
        break;
    case 2:
        tempDevice.sprintf("sdcard");
        break;
    default :
        tempDevice.sprintf("sdcard");
        break;
    }

    quint64 block = des->block;
    quint64 index = 0 ;
    quint64 skip = des->start;
    quint64 fileSize = des->fileSize;
    quint64 count = fileSize / block;

    for(quint64 i = 0;i < des->fileNumber;i++){
//        qDebug()<<"current   "<<count <<"-->"<<skip;
        fileName.clear();
        fileName.sprintf("%s_%d.moorc",des->planName.toLatin1().data(),skip);
        adbCmd.clear();
        qDebug()<<"current   "<<count <<"-->"<<skip;
        QByteArray a=tempDevice.toLatin1();
        QByteArray b=fileName.toLatin1();
        adbCmd.sprintf("adb shell su -c \" dd if=/dev/block/mmcblk0 of=/%s/moorc/%s bs=%lld count=%lld skip=%lld\"",tempDevice.toLatin1().data(),b.data(),block,count,skip);
        qDebug()<<adbCmd;
        copyCmd.clear();
        copyCmd.sprintf("adb pull /%s/moorc/%s moorc/%s/%s",tempDevice.toLatin1().data(),fileName.toLatin1().data(),desDir.toLatin1().data(),fileName.toLatin1().data());
        qDebug()<<copyCmd;
        clearCmd.clear();
        clearCmd.sprintf("adb shell su -c \"rm -rf /%s/moorc/%s\"",tempDevice.toLatin1().data(),fileName.toLatin1().data());
        qDebug()<<clearCmd;
        skip += count;


        ////add add cmd list
        cmd = xml.createElement("cmd");
        child->appendChild(cmd);
        attr = xml.createAttribute("type");
        attr.setNodeValue(tr("1"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("errorCheckType");
        attr.setNodeValue(tr("1"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("timeOut");
        attr.setNodeValue(tr("300"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("errorString");
        attr.setNodeValue(tr("error"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("cmd");
        attr.setNodeValue(adbCmd);
        cmd.setAttributeNodeNS(attr);
        ////end add a cmd list
        ////add add cmd list
        cmd = xml.createElement("cmd");
        child->appendChild(cmd);
        attr = xml.createAttribute("type");
        attr.setNodeValue(tr("1"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("errorCheckType");
        attr.setNodeValue(tr("1"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("timeOut");
        attr.setNodeValue(tr("300"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("errorString");
        attr.setNodeValue(tr("error"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("cmd");
        attr.setNodeValue(copyCmd);
        cmd.setAttributeNodeNS(attr);
        ////end add a cmd list
        ////add add cmd list
        cmd = xml.createElement("cmd");
        child->appendChild(cmd);
        attr = xml.createAttribute("type");
        attr.setNodeValue(tr("1"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("errorCheckType");
        attr.setNodeValue(tr("1"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("timeOut");
        attr.setNodeValue(tr("300"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("errorString");
        attr.setNodeValue(tr("error"));
        cmd.setAttributeNodeNS(attr);
        attr = xml.createAttribute("cmd");
        attr.setNodeValue(clearCmd);
        cmd.setAttributeNodeNS(attr);
        ////end add a cmd list
    }
}
