#include "dixiashiw.h"
#include "ui_dixiashiw.h"

dixiashiw::dixiashiw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dixiashiw)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("地下室"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(1060,540);
    this->setMinimumSize(1060,540);

    //背景
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix2/bg.png"))));
    this->setPalette(pal);

    //界面
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

    tuxiang =  new QLabel();
    QPixmap pix = QPixmap(":/new/prefix2/地下室.jpg");
    tuxiang->setPixmap(pix);
    tuxiang->resize(1024,438);

    txLay = new QHBoxLayout;
    txLay ->addWidget(tuxiang);
    txLay->addStretch();

    //关闭
    logout =  new QPushButton("关闭");
    logout->setStyleSheet("background-color:deepskyblue");

    QDateTime local = QDateTime::currentDateTime();
    label = new QLabel();
    label->setText(local.toString("yyyy-MM-dd hh:mm:ss "));


    logoutLay = new QHBoxLayout;
    logoutLay ->addWidget(logout);
    logoutLay->addStretch();
    logoutLay ->addWidget(label);

    //主显示
    mainLay = new QVBoxLayout;
    mainLay->addLayout(wsLay);
    mainLay->addLayout(txLay);
    mainLay->addLayout(logoutLay);
    mainLay->addStretch();

    this->setLayout(mainLay);

    //
    connect(logout,SIGNAL(clicked(bool)),this,SLOT(logoutSlot()));
}

dixiashiw::~dixiashiw()
{
    delete ui;
}

void dixiashiw::logoutSlot()
{
    this->close();
}
