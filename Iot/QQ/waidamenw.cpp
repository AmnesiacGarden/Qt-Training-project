#include "waidamenw.h"
#include "ui_waidamenw.h"

waidamenw::waidamenw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waidamenw)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("外大门"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(1240,540);
    this->setMinimumSize(1240,540);

    //背景
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix2/bg.png"))));
    this->setPalette(pal);

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

    //界面
    tuxiang =  new QLabel();
    QPixmap pix = QPixmap(":/new/prefix2/shexiangtou.jpg");
    tuxiang->setPixmap(pix);
    tuxiang->resize(970,438);

    QDateTime local = QDateTime::currentDateTime();
    label = new QLabel();
    label->setText(local.toString("yyyy-MM-dd hh:mm:ss "));

    deng1 =  new QPushButton();
    deng1->setStyleSheet("border:none");
    deng1->setFlat("ture");
    deng1->setMaximumSize(180,68);
    deng1->setMinimumSize(180,68);
    deng1->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/灯一.png);}");

    deng2 =  new QPushButton();
    deng2->setStyleSheet("border:none");
    deng2->setFlat("ture");
    deng2->setMaximumSize(180,68);
    deng2->setMinimumSize(180,68);
    deng2->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/灯二.png);}");

    dengLay = new QHBoxLayout();
    dengLay->addStretch();
    dengLay->addWidget(deng1);
    dengLay->addWidget(deng2);
    dengLay->addStretch();

    kai =  new QPushButton();
    kai->setStyleSheet("border:none");
    kai->setFlat("ture");
    kai->setMaximumSize(180,68);
    kai->setMinimumSize(180,68);
    kai->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/开门.png);}");

    guan =  new QPushButton();
    guan->setStyleSheet("border:none");
    guan->setFlat("ture");
    guan->setMaximumSize(180,68);
    guan->setMinimumSize(180,68);
    guan->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/关门.png);}");

    kgLay = new QHBoxLayout();
    kgLay->addStretch();
    kgLay->addWidget(kai);
    kgLay->addWidget(guan);
    kgLay->addStretch();

    sxts =  new QPushButton();
    sxts->setStyleSheet("border:none");
    sxts->setFlat("ture");
    sxts->setMaximumSize(16,22);
    sxts->setMinimumSize(16,22);
    sxts->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/up.png);}");

    sxtz =  new QPushButton();
    sxtz->setStyleSheet("border:none");
    sxtz->setFlat("ture");
    sxtz->setMaximumSize(22,16);
    sxtz->setMinimumSize(22,16);
    sxtz->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/left.png);}");

    sxtx =  new QPushButton();
    sxtx->setStyleSheet("border:none");
    sxtx->setFlat("ture");
    sxtx->setMaximumSize(16,22);
    sxtx->setMinimumSize(16,22);
    sxtx->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/down.png);}");

    sxty =  new QPushButton();
    sxty->setStyleSheet("border:none");
    sxty->setFlat("ture");
    sxty->setMaximumSize(22,16);
    sxty->setMinimumSize(22,16);
    sxty->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/right.png);}");

    sxtLay = new QGridLayout();
    sxtLay->addWidget(sxts,0,1,1,1);
    sxtLay->addWidget(sxtz,1,0,1,1);
    sxtLay->addWidget(sxtx,2,1,1,1);
    sxtLay->addWidget(sxty,1,2,1,1);

    anjianLay = new QVBoxLayout();
    anjianLay->addStretch();
    anjianLay->addLayout(dengLay);
    anjianLay->addStretch();
    anjianLay->addLayout(sxtLay);
    anjianLay->addStretch();
    anjianLay->addLayout(kgLay);
    anjianLay->addStretch();

    jiemianLay = new QHBoxLayout;
    jiemianLay->addStretch();
    jiemianLay->addWidget(tuxiang);
    jiemianLay->addStretch();
    jiemianLay->addLayout(anjianLay);
    jiemianLay->addStretch();

    //注销
    logout =  new QPushButton("关闭");
    logout->setStyleSheet("background-color:deepskyblue");

    logoutLay = new QHBoxLayout;
    logoutLay ->addWidget(logout);
    logoutLay->addStretch();

    //主显示
    mainLay = new QVBoxLayout;
    mainLay->addLayout(wsLay);
    mainLay->addWidget(label);
    mainLay->addStretch();
    mainLay->addLayout(jiemianLay);
    mainLay->addStretch();
    mainLay->addLayout(logoutLay);

    this->setLayout(mainLay);

    //
    connect(deng1,SIGNAL(clicked(bool)),this,SLOT(deng1Slot()));
    connect(deng2,SIGNAL(clicked(bool)),this,SLOT(deng2Slot()));
    connect(kai,SIGNAL(clicked(bool)),this,SLOT(kaiSlot()));
    connect(guan,SIGNAL(clicked(bool)),this,SLOT(guanSlot()));
    connect(logout,SIGNAL(clicked(bool)),this,SLOT(logoutSlot()));
}

waidamenw::~waidamenw()
{
    delete ui;
}

void waidamenw::deng1Slot()
{
    QMessageBox::information(this,QString("提示"),QString("1号灯已打开"),QMessageBox::Ok);
}

void waidamenw::deng2Slot()
{
    QMessageBox::information(this,QString("提示"),QString("2号灯已打开"),QMessageBox::Ok);
}

void waidamenw::kaiSlot()
{
    QMessageBox::information(this,QString("提示"),QString("大门已打开"),QMessageBox::Ok);
}

void waidamenw::guanSlot()
{
    QMessageBox::information(this,QString("提示"),QString("大门已关闭"),QMessageBox::Ok);
}

void waidamenw::logoutSlot()
{
    this->close();
}
