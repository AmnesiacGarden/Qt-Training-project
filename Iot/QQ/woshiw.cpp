#include "woshiw.h"
#include "ui_woshiw.h"

woshiw::woshiw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::woshiw)
{
    ui->setupUi(this);
    //窗口属性
    this->setWindowTitle(QString("卧室"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(970,540);
    this->setMinimumSize(970,540);

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
    QPixmap pix = QPixmap(":/new/prefix2/卧室.jpg");
    tuxiang->setPixmap(pix);
    tuxiang->resize(970,438);

    QDateTime local = QDateTime::currentDateTime();
    label = new QLabel();
    label->setText(local.toString("yyyy-MM-dd hh:mm:ss "));

    kai =  new QPushButton();
    kai->setStyleSheet("border:none");
    kai->setMaximumSize(180,68);
    kai->setMinimumSize(180,68);
    kai->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/开灯.png);}");

    guan =  new QPushButton();
    guan->setStyleSheet("border:none");
    guan->setMaximumSize(180,68);
    guan->setMinimumSize(180,68);
    guan->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/关灯.png);}");

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

    jiemianLay = new QHBoxLayout;
    jiemianLay->addStretch();
    jiemianLay->addWidget(kai);
    jiemianLay->addStretch();
    jiemianLay->addLayout(sxtLay);
    jiemianLay->addStretch();
    jiemianLay->addWidget(guan);
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
    mainLay->addWidget(tuxiang);
    mainLay->addStretch();
    mainLay->addLayout(jiemianLay);
    mainLay->addStretch();
    mainLay->addLayout(logoutLay);

    this->setLayout(mainLay);

    //
    connect(kai,SIGNAL(clicked(bool)),this,SLOT(kaiSlot()));
    connect(guan,SIGNAL(clicked(bool)),this,SLOT(guanSlot()));
    connect(logout,SIGNAL(clicked(bool)),this,SLOT(logoutSlot()));
}

woshiw::~woshiw()
{
    delete ui;
}

void woshiw::kaiSlot()
{
    QMessageBox::information(this,QString("提示"),QString("灯已打开"),QMessageBox::Ok);
}

void woshiw::guanSlot()
{
    QMessageBox::information(this,QString("提示"),QString("灯已关闭"),QMessageBox::Ok);
}

void woshiw::logoutSlot()
{
    this->close();
}
