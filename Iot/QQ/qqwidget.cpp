#include "qqwidget.h"
#include "ui_qqwidget.h"

QQWidget::QQWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QQWidget)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("网络姻缘一线牵"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(540,400);
    this->setMinimumSize(540,400);

    //背景

    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix1/bg.jpg"))));
    this->setPalette(pal);

    //头像
    Avatar = new QLabel(this);
    QPixmap pix = QPixmap(":/new/prefix1/Avatar.jpg");
        Avatar->setPixmap(pix);
        Avatar->resize(80,80);

    QHBoxLayout *AvatarLay = new QHBoxLayout;
    AvatarLay->addStretch();
    AvatarLay ->addWidget(Avatar);
    AvatarLay->addStretch();

    //账号密码
    linezhanghao = new QLineEdit("");
    linezhanghao->setPlaceholderText("请输入账号");
    linezhanghao->setStyleSheet("border:none");   //隐藏边框线
    QFont font = linezhanghao->font();
    font.setPointSize(14);
    linezhanghao->setFont(font);

    zh = new QLabel(this);
    QPixmap pix1 = QPixmap(":/new/prefix1/zh.jpg");
    zh->setPixmap(pix1);
    zh->resize(32,36);

    linezhanghaoLay = new QHBoxLayout;
    linezhanghaoLay->addStretch();
    linezhanghaoLay ->addWidget(zh);
    linezhanghaoLay ->addWidget(linezhanghao);
    linezhanghaoLay->addStretch();

    linemima = new QLineEdit("");
    linemima->setPlaceholderText("请输入密码");
    linemima->setEchoMode(QLineEdit::Password);
    linemima->setStyleSheet("border:none");   //隐藏边框线
    QFont font1 = linemima->font();
    font.setPointSize(14);
    linemima->setFont(font);

    mm = new QLabel(this);
    QPixmap pix2 = QPixmap(":/new/prefix1/mm.jpg");
    mm->setPixmap(pix2);
    mm->resize(32,36);

    linemimaLay = new QHBoxLayout;
    linemimaLay->addStretch();
    linemimaLay ->addWidget(mm);
    linemimaLay ->addWidget(linemima);
    linemimaLay->addStretch();

    //勾选
    Tick = new QWidget;
    chkBoxzi = new QCheckBox("自动登录");
    chkBoxji = new QCheckBox("记住密码");
    pushButtonzhao =  new QPushButton("找回密码");
    pushButtonzhao->setStyleSheet("background-color:white");
    pushButtonzhao->setStyleSheet("border:none");   //隐藏边框线

    TickLay = new QHBoxLayout;
    TickLay->addStretch();
    TickLay ->addWidget(chkBoxzi);
    TickLay ->addWidget(chkBoxji);
    TickLay ->addWidget(pushButtonzhao);
    TickLay->addStretch();

    //登录按钮

    pushButtonOK =  new QPushButton("登录");
    pushButtonOK->setStyleSheet("background-color:deepskyblue");
//    pushButtonOK->setMinimumSize(60,30);
 //   pushButtonOK->setMinimumSize(60,30);



    pushButtonOKLay = new QHBoxLayout;
    pushButtonOKLay->setContentsMargins(50,0,50,0);
//    pushButtonOKLay->addStretch();
    pushButtonOKLay ->addWidget(pushButtonOK);
//    pushButtonOKLay->addStretch();
    pushButtonOKLay->setContentsMargins(50,0,50,0);

    //注册 二维
    pushButtonzhu =  new QPushButton("注册\n账号");
 //   pushButtonzhu->setGeometry(5,400,535,5);
    pushButtonzhu->setStyleSheet("background-color:white");
//    pushButtonzhu->setStyleSheet("border:none");   //隐藏边框线
    pushButtonzhu->setMaximumSize(49, 49);
    pushButtonzhu->setMinimumSize(49, 49);

    pushButtoner =  new QPushButton();//二维码
//    pushButtoner->setGeometry(535,400,49,49);
    pushButtoner->setStyleSheet("background-color:white");
    pushButtoner->setStyleSheet("border:none");
    pushButtoner->setMaximumSize(49, 49);
    pushButtoner->setMinimumSize(49, 49);
    pushButtoner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/er.jpg);}");

    pushButtonzeLay = new QHBoxLayout;
    pushButtonzeLay ->addWidget(pushButtonzhu);
    pushButtonzeLay->addStretch();
//    pushButtonzeLay->setContentsMargins(49,0,49,49);
    pushButtonzeLay ->addWidget(pushButtoner);

    //主显示
    mainLay = new QVBoxLayout;
//    mainLay->setSpacing(1);
    mainLay->addLayout(AvatarLay);
 //   mainLay->setContentsMargins(0,50,0,50);
    mainLay->addLayout(linezhanghaoLay);
    mainLay->addLayout(linemimaLay);
    mainLay->addLayout(TickLay);
    mainLay->addLayout(pushButtonOKLay);
    mainLay->addLayout(pushButtonzeLay);

    this->setLayout(mainLay);

    sd = new QUdpSocket();

    connect(pushButtonzhu,SIGNAL(clicked(bool)),this,SLOT(zhucelots()));
    connect(pushButtoner,SIGNAL(clicked(bool)),this,SLOT(erlots()));
    connect(pushButtonOK,SIGNAL(clicked(bool)),this,SLOT(denglulots()));
    connect(sd,SIGNAL(readyRead()),this,SLOT(sdReadyreadSlot()));
}

QQWidget::~QQWidget()
{
    delete ui;
}

void QQWidget::zhucelots()
{
    reg *r = new reg();
    r->show();
}

void QQWidget::erlots()
{
    er *s = new er();
    s->show();
}

void QQWidget::denglulots()
{
    login_t sndbuff;

    QString cntStr = linezhanghao->text();

    QString pwdStr = linemima->text();

    strncpy(sndbuff.cnt, cntStr.toLatin1().data(),CNTSIZE);

    QByteArray pwdArr =  QCryptographicHash::hash(pwdStr.toLatin1(),QCryptographicHash::Sha512);
    strncpy(sndbuff.pwd, pwdArr.toHex().data(),PWDSIZE);
    qDebug() << sndbuff.cnt << sndbuff.pwd;

    sd->writeDatagram((char *)&sndbuff,sizeof(sndbuff),\
                      QHostAddress(LOGIN_SERVER_IP),LOGIN_SERVER_PORT);
}

void QQWidget::sdReadyreadSlot()
{
   Chat *c = new Chat();

    login_t rcvreg;

    sd->readDatagram((char *)&rcvreg, sizeof(rcvreg));

    bool ret;
    switch (rcvreg.login_state) {
    case LOGIN_OK:
           c->show();
           this->close();
        break;
    case LOGIN_NOTEXISTS:
        QMessageBox::information(this,QString("提示"),QString("小老弟，去注册！"),QMessageBox::Ok);
        linezhanghao->clear();
        linemima->clear();
        break;
    case LOGIN_ERRORPW:
        ret = QMessageBox::question(this,QString("提示"),QString("老弟，输错了！"),QMessageBox::Ok);
            linezhanghao->clear();
            linemima->clear();
        break;
    default:
        break;
    }
}

