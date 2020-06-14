#include "windows.h"
#include "ui_windows.h"

windows::windows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windows)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("主界面"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(1920,1000);
    this->setMinimumSize(1920,1000);

    //背景
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix2/bg1.jpg"))));
    this->setPalette(pal);

    //上
    wProgressBar = new QProgressBar();
    wProgressBar->setOrientation(Qt::Horizontal);  // 水平方向
    wProgressBar->setMinimum(0);  // 最小值
    wProgressBar->setMaximum(4800);  // 最大值
    wProgressBar->setValue(2000);  // 当前进度
    wProgressBar->setFormat("温度");
    wProgressBar->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);  // 对齐方式

    sProgressBar = new QProgressBar();
    sProgressBar->setOrientation(Qt::Horizontal);  // 水平方向
    sProgressBar->setMinimum(0);  // 最小值
    sProgressBar->setMaximum(4800);  // 最大值
    sProgressBar->setValue(1500);  // 当前进度
    sProgressBar->setFormat("湿度");
    sProgressBar->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);  // 对齐方式

    wsLay = new QHBoxLayout;
    wsLay->addStretch();
    wsLay->addWidget(wProgressBar);
    wsLay->addWidget(sProgressBar);
    wsLay->addStretch();

    //中
    clzk =  new QPushButton();
    clzk->setStyleSheet("border:none");
    clzk->setMaximumSize(180,68);
    clzk->setMinimumSize(180,68);
    clzk->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/chuanglianzuokai.png);}");

    clzg =  new QPushButton();
    clzg->setStyleSheet("border:none");
    clzg->setMaximumSize(180,68);
    clzg->setMinimumSize(180,68);
    clzg->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/chuanglianzuoguan.png);}");

    clyk =  new QPushButton();
    clyk->setStyleSheet("border:none");
    clyk->setMaximumSize(180,68);
    clyk->setMinimumSize(180,68);
    clyk->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/chuanglianyoukai.png);}");

    clyg =  new QPushButton();
    clyg->setStyleSheet("border:none");
    clyg->setMaximumSize(180,68);
    clyg->setMinimumSize(180,68);
    clyg->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/chuanglianyouguan.png);}");

    bjqk =  new QPushButton();
    bjqk->setStyleSheet("border:none");
    bjqk->setMaximumSize(180,68);
    bjqk->setMinimumSize(180,68);
    bjqk->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/dakaibaojingqi.png);}");

    tuxiang =  new QLabel();
    QPixmap pix = QPixmap(":/new/prefix2/ceshijiemian.jpg");
    tuxiang->setPixmap(pix);
    tuxiang->resize(1024,683);


    deng1 =  new QPushButton();
    deng1->setStyleSheet("border:none");
    deng1->setMaximumSize(180,68);
    deng1->setMinimumSize(180,68);
    deng1->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/灯一.png);}");

    deng2 =  new QPushButton();
    deng2->setStyleSheet("border:none");
    deng2->setMaximumSize(180,68);
    deng2->setMinimumSize(180,68);
    deng2->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/灯二.png);}");

    deng3 =  new QPushButton();
    deng3->setStyleSheet("border:none");
    deng3->setMaximumSize(180,68);
    deng3->setMinimumSize(180,68);
    deng3->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/灯三.png);}");

    deng4 =  new QPushButton();
    deng4->setStyleSheet("border:none");
    deng4->setMaximumSize(180,68);
    deng4->setMinimumSize(180,68);
    deng4->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/灯四.png);}");

    bjqg =  new QPushButton();
    bjqg->setStyleSheet("border:none");
    bjqg->setMaximumSize(180,68);
    bjqg->setMinimumSize(180,68);
    bjqg->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/关闭报警器.png);}");

    zuoLay = new QGridLayout();
    zuoLay->addWidget(clzk,0,0);
    zuoLay->addWidget(clzg,1,0);
    zuoLay->addWidget(clyk,2,0);
    zuoLay->addWidget(clyg,3,0);
    zuoLay->addWidget(bjqk,4,0);

    youLay = new QGridLayout();
    youLay->addWidget(deng1,0,0);
    youLay->addWidget(deng2,1,0);
    youLay->addWidget(deng3,2,0);
    youLay->addWidget(deng4,3,0);
    youLay->addWidget(bjqg,4,0);

    zhongtLay = new QHBoxLayout();
    zhongtLay->addStretch();
    zhongtLay->addLayout(zuoLay);
    zhongtLay->addWidget(tuxiang);
    zhongtLay->addLayout(youLay);
    zhongtLay->addStretch();

    //下
    kt1 =  new QLCDNumber();
    kt1->display("25.0");

    kt1jian =  new QPushButton();
    kt1jian->setStyleSheet("border:none");
    kt1jian->setMaximumSize(23,24);
    kt1jian->setMinimumSize(23,24);
    kt1jian->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/jiangwen.png);}");

    kt1kg =  new QPushButton();
    kt1kg->setStyleSheet("border:none");
    kt1kg->setMaximumSize(33,29);
    kt1kg->setMinimumSize(33,29);
    kt1kg->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/off.png);}");

    kt1jia =  new QPushButton();
    kt1jia->setStyleSheet("border:none");
    kt1jia->setMaximumSize(23,24);
    kt1jia->setMinimumSize(23,24);
    kt1jia->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/shengwen.png);}");

    kt1Lay = new QGridLayout();
    kt1Lay->addWidget(kt1,0,0,1,3);
    kt1Lay->addWidget(kt1jian,2,0);
    kt1Lay->addWidget(kt1kg,2,1);
    kt1Lay->addWidget(kt1jia,2,2);

    sxts =  new QPushButton();
    sxts->setStyleSheet("border:none");
    sxts->setMaximumSize(16,22);
    sxts->setMinimumSize(16,22);
    sxts->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/up.png);}");

    sxtz =  new QPushButton();
    sxtz->setStyleSheet("border:none");
    sxtz->setMaximumSize(22,16);
    sxtz->setMinimumSize(22,16);
    sxtz->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/left.png);}");

    sxtx =  new QPushButton();
    sxtx->setStyleSheet("border:none");
    sxtx->setMaximumSize(16,22);
    sxtx->setMinimumSize(16,22);
    sxtx->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/down.png);}");

    sxty =  new QPushButton();
    sxty->setStyleSheet("border:none");
    sxty->setMaximumSize(22,16);
    sxty->setMinimumSize(22,16);
    sxty->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/right.png);}");

    sxtLay = new QGridLayout();
    sxtLay->addWidget(sxts,0,1,1,1);
    sxtLay->addWidget(sxtz,1,0,1,1);
    sxtLay->addWidget(sxtx,2,1,1,1);
    sxtLay->addWidget(sxty,1,2,1,1);

    kt2 =  new QLCDNumber();
    kt2->display("28.0");

    kt2jian =  new QPushButton();
    kt2jian->setStyleSheet("border:none");
    kt2jian->setMaximumSize(23,24);
    kt2jian->setMinimumSize(23,24);
    kt2jian->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/jiangwen.png);}");

    kt2kg =  new QPushButton();
    kt2kg->setStyleSheet("border:none");
    kt2kg->setMaximumSize(33,29);
    kt2kg->setMinimumSize(33,29);
    kt2kg->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/off.png);}");

    kt2jia =  new QPushButton();
    kt2jia->setStyleSheet("border:none");
    kt2jia->setMaximumSize(23,24);
    kt2jia->setMinimumSize(23,24);
    kt2jia->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/shengwen.png);}");

    kt2Lay = new QGridLayout();
    kt2Lay->addWidget(kt2,0,0,1,3);
    kt2Lay->addWidget(kt2jian,2,0);
    kt2Lay->addWidget(kt2kg,2,1);
    kt2Lay->addWidget(kt2jia,2,2);

//    xiaLay = new QHBoxLayout();
//    xiaLay->addStretch();
//    xiaLay->addLayout(kt1Lay);
//    xiaLay->addLayout(sxtLay);
//    xiaLay->addLayout(kt2Lay);
//    xiaLay->addStretch();

    xiaLay = new QGridLayout();
    xiaLay->addLayout(kt1Lay,0,0);
    xiaLay->addLayout(sxtLay,0,1);
    xiaLay->addLayout(kt2Lay,0,2);

    //注销
    logout =  new QPushButton("注销");
    logout->setStyleSheet("background-color:deepskyblue");

    logoutLay = new QHBoxLayout;
    logoutLay ->addWidget(logout);
    logoutLay->addStretch();

    //主显示
    mainLay = new QVBoxLayout;
    mainLay->addLayout(wsLay);
    mainLay->addStretch();
    mainLay->addLayout(zhongtLay);
    mainLay->addStretch();
    mainLay->addLayout(xiaLay);
    mainLay->addStretch();
    mainLay->addLayout(logoutLay);

    this->setLayout(mainLay);

    //
    connect(clzk,SIGNAL(clicked(bool)),this,SLOT(clzkSlot()));
    connect(clzg,SIGNAL(clicked(bool)),this,SLOT(clzgSlot()));
    connect(clyk,SIGNAL(clicked(bool)),this,SLOT(clykSlot()));
    connect(clyg,SIGNAL(clicked(bool)),this,SLOT(clygSlot()));
    connect(bjqk,SIGNAL(clicked(bool)),this,SLOT(bjqkSlot()));
    connect(deng1,SIGNAL(clicked(bool)),this,SLOT(deng1Slot()));
    connect(deng2,SIGNAL(clicked(bool)),this,SLOT(deng2Slot()));
    connect(deng3,SIGNAL(clicked(bool)),this,SLOT(deng3Slot()));
    connect(deng4,SIGNAL(clicked(bool)),this,SLOT(deng4Slot()));
    connect(bjqg,SIGNAL(clicked(bool)),this,SLOT(bjqgSlot()));
    connect(kt1kg,SIGNAL(clicked(bool)),this,SLOT(kt1kgSlot()));
    connect(kt2kg,SIGNAL(clicked(bool)),this,SLOT(kt2kgSlot()));
    connect(logout,SIGNAL(clicked(bool)),this,SLOT(logoutSlot()));
}

windows::~windows()
{
    delete ui;
}

void windows::clzkSlot()
{
    QMessageBox::information(this,QString("提示"),QString("左侧窗帘已打开"),QMessageBox::Ok);
}

void windows::clzgSlot()
{
    QMessageBox::information(this,QString("提示"),QString("左侧窗帘已关闭"),QMessageBox::Ok);
}

void windows::clykSlot()
{
    QMessageBox::information(this,QString("提示"),QString("右侧窗帘已打开"),QMessageBox::Ok);
}

void windows::clygSlot()
{
    QMessageBox::information(this,QString("提示"),QString("右侧窗帘已关闭"),QMessageBox::Ok);
}

void windows::bjqkSlot()
{
    QMessageBox::information(this,QString("提示"),QString("报警器已打开"),QMessageBox::Ok);
}

void windows::deng1Slot()
{
    QMessageBox::information(this,QString("提示"),QString("1号灯已打开"),QMessageBox::Ok);
}

void windows::deng2Slot()
{
    QMessageBox::information(this,QString("提示"),QString("2号灯已打开"),QMessageBox::Ok);
}

void windows::deng3Slot()
{
    QMessageBox::information(this,QString("提示"),QString("3号灯已打开"),QMessageBox::Ok);
}

void windows::deng4Slot()
{
    QMessageBox::information(this,QString("提示"),QString("4号灯已打开"),QMessageBox::Ok);
}

void windows::bjqgSlot()
{
    QMessageBox::information(this,QString("提示"),QString("报警器已关闭"),QMessageBox::Ok);
}

void windows::kt1kgSlot()
{
    QMessageBox::information(this,QString("提示"),QString("1号空调已打开"),QMessageBox::Ok);
}

void windows::kt2kgSlot()
{
    QMessageBox::information(this,QString("提示"),QString("2号空调已打开"),QMessageBox::Ok);
}

void windows::logoutSlot()
{
    this->close();
}
