#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("主菜单"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(1920,1000);
    this->setMinimumSize(1920,1000);

    //背景
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix2/bg.png"))));
    this->setPalette(pal);

    //上

    QDateTime local = QDateTime::currentDateTime();
    label = new QLabel();
    label->setText(local.toString("yyyy-MM-dd hh:mm:ss "));

    //中
    keting =  new QPushButton();
    keting->setStyleSheet("border:none");
    keting->setFlat("ture");
    keting->setMaximumSize(497,266);
    keting->setMinimumSize(497,266);
    keting->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/keting.png);}");

    dixiashi =  new QPushButton();
    dixiashi->setStyleSheet("border:none");
    dixiashi->setFlat("ture");
    dixiashi->setMaximumSize(497,266);
    dixiashi->setMinimumSize(497,266);
    dixiashi->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/dixiashi.png);}");

    waijing =  new QPushButton();
    waijing->setStyleSheet("border:none");
    waijing->setFlat("ture");
    waijing->setMaximumSize(497,266);
    waijing->setMinimumSize(497,266);
    waijing->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/waijing.png);}");

    woshi1 =  new QPushButton();
    woshi1->setStyleSheet("border:none");
    woshi1->setFlat("ture");
    woshi1->setMaximumSize(497,266);
    woshi1->setMinimumSize(497,266);
    woshi1->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/woshiyi.png);}");

    woshi2 =  new QPushButton();
    woshi2->setStyleSheet("border:none");
    woshi2->setFlat("ture");
    woshi2->setMaximumSize(497,266);
    woshi2->setMinimumSize(497,266);
    woshi2->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/woshier.png);}");

    woshi3 =  new QPushButton();
    woshi3->setStyleSheet("border:none");
    woshi3->setFlat("ture");
    woshi3->setMaximumSize(497,266);
    woshi3->setMinimumSize(497,266);
    woshi3->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/woshisan.png);}");

    cheku =  new QPushButton();
    cheku->setStyleSheet("border:none");
    cheku->setFlat("ture");
    cheku->setMaximumSize(497,266);
    cheku->setMinimumSize(497,266);
    cheku->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/cheku.png);}");

    chufang =  new QPushButton();
    chufang->setStyleSheet("border:none");
    chufang->setFlat("ture");
    chufang->setMaximumSize(497,266);
    chufang->setMinimumSize(497,266);
    chufang->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/chufang.png);}");

    waidamen =  new QPushButton();
    waidamen->setStyleSheet("border:none");
    waidamen->setFlat("ture");
    waidamen->setMaximumSize(497,266);
    waidamen->setMinimumSize(497,266);
    waidamen->setStyleSheet("QPushButton{background-image: url(:/new/prefix2/waidamen.png);}");

    butLay = new QGridLayout();
    butLay->addWidget(keting,0,0);
    butLay->addWidget(dixiashi,0,1);
    butLay->addWidget(waijing,0,2);
    butLay->addWidget(woshi1,1,0);
    butLay->addWidget(woshi2,1,1);
    butLay->addWidget(woshi3,1,2);
    butLay->addWidget(cheku,2,0);
    butLay->addWidget(chufang,2,1);
    butLay->addWidget(waidamen,2,2);
    butLay->setHorizontalSpacing(5);

    //下
    logout =  new QPushButton("注销");
    logout->setStyleSheet("background-color:deepskyblue");
    logout->setFlat("ture");

    logoutLay = new QHBoxLayout;
    logoutLay ->addWidget(logout);
    logoutLay->addStretch();

    //主显示
    mainLay = new QVBoxLayout;
    mainLay->addWidget(label);
    mainLay->addStretch();
    mainLay->addLayout(butLay);
    mainLay->addStretch();
    mainLay->addLayout(logoutLay);

    this->setLayout(mainLay);

    //
    connect(keting,SIGNAL(clicked(bool)),this,SLOT(ketingSlot()));
    connect(dixiashi,SIGNAL(clicked(bool)),this,SLOT(dixiashiSlot()));
    connect(waijing,SIGNAL(clicked(bool)),this,SLOT(waijingSlot()));
    connect(woshi1,SIGNAL(clicked(bool)),this,SLOT(woshi1Slot()));
    connect(woshi2,SIGNAL(clicked(bool)),this,SLOT(woshi2Slot()));
    connect(woshi3,SIGNAL(clicked(bool)),this,SLOT(woshi3Slot()));
    connect(cheku,SIGNAL(clicked(bool)),this,SLOT(chekuSlot()));
    connect(chufang,SIGNAL(clicked(bool)),this,SLOT(chufangSlot()));
    connect(waidamen,SIGNAL(clicked(bool)),this,SLOT(waidamenSlot()));
    connect(logout,SIGNAL(clicked(bool)),this,SLOT(logoutSlot()));
}


Chat::~Chat()
{
    delete ui;
}

void Chat::ketingSlot()
{
    windows *r = new windows();
    r->show();
}

void Chat::dixiashiSlot()
{
    dixiashiw *r = new dixiashiw();
    r->show();
}

void Chat::waijingSlot()
{
    waijingw *r = new waijingw();
    r->show();
}

void Chat::woshi1Slot()
{
    woshiw *r = new woshiw();
    r->show();
}

void Chat::woshi2Slot()
{
    woshiw *r = new woshiw();
    r->show();
}

void Chat::woshi3Slot()
{
    woshiw *r = new woshiw();
    r->show();
}

void Chat::chekuSlot()
{
    chekuw *s = new chekuw();
    s->show();
}

void Chat::chufangSlot()
{
    chufangw *r = new chufangw();
    r->show();
}

void Chat::waidamenSlot()
{
    waidamenw *r = new waidamenw();
    r->show();
}

void Chat::logoutSlot()
{
    this->close();
}

