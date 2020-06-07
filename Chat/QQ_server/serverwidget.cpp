#include "serverwidget.h"
#include "proto.h"

#include <QHostAddress>
#include <QApplication>

ServerWidget::ServerWidget(QWidget *parent):QWidget(parent)
{
    //界面
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix1/img/erweima.PNG"))));
    this->setPalette(pal);

    this->setMaximumSize(372,372);
    this->setMinimumSize(372,372);

    //初始化
    sd = new QUdpSocket();
    sd->bind(QHostAddress(RGS_SERVER_IP),RGS_SERVER_PORT);


    //链接
    connect(sd,SIGNAL(readyRead()),this,SLOT(sdReadyReadSlot()));

}

ServerWidget::~ServerWidget()
{

}

void ServerWidget::sdReadyReadSlot()
{
    reg_t rcvbuff;
    QHostAddress raddr;
    quint16 rport;

    sd->readDatagram((char *)&rcvbuff,sizeof(rcvbuff),&raddr,&rport);
    qDebug() << rcvbuff.cnt << rcvbuff.pwd ;

    //sql
    QSqlDatabase sql = QSqlDatabase::addDatabase("QSQLITE");

    sql.setDatabaseName(QApplication::applicationDirPath()+"/server.dat");

    //打开sql
    if (!sql.open()) {
        qDebug() << "Error:关门了!" << sql.lastError();
    }else {
        qDebug() << "Succeed:接客!";
    }

    //建表
    QSqlQuery sql_query;
    if (!sql_query.exec("create table if not exists regTable(count text primary key, passwoed text not null)")) {
            qDebug() << "Error:未建表" << sql.lastError();
    }else {
            qDebug() << "Succeed:已建表";
    }

    //查表
    bool ret;
    char buf[256];
    QString cnt;

    sql_query.exec("select * from regTable");

    if (!sql_query.exec()) {
        qDebug() << "Error:找不到" << sql_query.lastError();
    }else {
        while ((ret = sql_query.next())) {
             cnt = sql_query.value(0).toString();
             qDebug() << cnt;
        if (strcmp(rcvbuff.cnt,cnt.toLatin1().data()) == 0) {
            //已注册
            rcvbuff.reg_state = RGS_EXISTS;
            break;
            }
        }
    }

    if (!ret) {
        qDebug() << "reg ok";
        rcvbuff.reg_state = RGS_OK;
        memset(buf,'\0',256);
        snprintf(buf,256, "insert into regTable values(\"%s\",\"%s\")",\
                 rcvbuff.cnt ,rcvbuff.pwd);
        QString s = QString::fromLocal8Bit(buf);
        if (!sql_query.exec(s)) {
            qDebug() << "Error: insert error" << sql_query.lastError();
        }
    }

    sql.close();

    sd->writeDatagram((char *)&rcvbuff, sizeof(rcvbuff),raddr,rport);
}

