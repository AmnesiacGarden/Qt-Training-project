#include "reg.h"
#include "ui_reg.h"

#include<QCryptographicHash>
#include<QMessageBox>

reg::reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("注册"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(540,400);
    this->setMinimumSize(540,400);

    //背景

    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix1/bg.jpg"))));
    this->setPalette(pal);

    //
    zhanghao = new QLineEdit("");
        zhanghao->setPlaceholderText("请输入账号");
    QFont font = zhanghao->font();
        font.setPointSize(14);
        zhanghao->setFont(font);

    zhanghaoLay = new QHBoxLayout;
        zhanghaoLay->addStretch();
        zhanghaoLay ->addWidget(zhanghao);
        zhanghaoLay->addStretch();

    mima = new QLineEdit("");
        mima->setPlaceholderText("请输入密码");
        mima->setEchoMode(QLineEdit::Password);
    QFont font1 = mima->font();
        font.setPointSize(14);
        mima->setFont(font);

    mimaLay = new QHBoxLayout;
        mimaLay->addStretch();
        mimaLay ->addWidget(mima);
        mimaLay->addStretch();

    pushButtonOK =  new QPushButton("注册");
        pushButtonOK->setStyleSheet("background-color:deepskyblue");

    pushButtonOKLay = new QHBoxLayout;
        pushButtonOKLay->setContentsMargins(50,0,50,0);
    //    pushButtonOKLay->addStretch();
        pushButtonOKLay ->addWidget(pushButtonOK);
    //    pushButtonOKLay->addStretch();
        pushButtonOKLay->setContentsMargins(50,0,50,0);

    mainLay = new QVBoxLayout;
        mainLay->addLayout(zhanghaoLay);
        mainLay->addLayout(mimaLay);
        mainLay->addWidget(pushButtonOK);

    this->setLayout(mainLay);

    sd = new QUdpSocket();

    connect(pushButtonOK,SIGNAL(clicked(bool)),this,SLOT(zhucelots()));
    connect(sd,SIGNAL(readyRead()),this,SLOT(sdReadyreadSlot()));
}

reg::~reg()
{
    delete ui;
}

void reg::zhucelots()
{
    reg_t sndbuff;

    QString cntStr = zhanghao->text();

    QString pwdStr = mima->text();

    strncpy(sndbuff.cnt, cntStr.toLatin1().data(),CNTSIZE);

    QByteArray pwdArr =  QCryptographicHash::hash(pwdStr.toLatin1(),QCryptographicHash::Sha512);
    strncpy(sndbuff.pwd, pwdArr.toHex().data(),PWDSIZE);
    qDebug() << sndbuff.cnt << sndbuff.pwd;
    sd->writeDatagram((char *)&sndbuff,sizeof(sndbuff),\
                      QHostAddress(RGS_SERVER_IP),RGS_SERVER_PORT);
}

void reg::sdReadyreadSlot()
{
    reg_t rcvbuff;

    sd->readDatagram((char *)&rcvbuff, sizeof(rcvbuff));

    bool ret;
    switch (rcvbuff.reg_state) {
    case RGS_OK:
        QMessageBox::information(this,QString("提示"),QString("来了，老弟！"),QMessageBox::Ok);
        this->close();
        break;
    case RGS_ERROR:
        QMessageBox::information(this,QString("提示"),QString("小老弟，别乱来！"),QMessageBox::Ok);
        this->close();
        break;
    case RGS_EXISTS:
        ret = QMessageBox::question(this,QString("提示"),QString("老弟，你很眼熟啊！"),QMessageBox::Ok,QMessageBox::No);
        if (ret == QMessageBox::No)
            this->close();
        else {
            zhanghao->clear();
            mima->clear();
        }
        break;
    default:
        break;
    }
}

