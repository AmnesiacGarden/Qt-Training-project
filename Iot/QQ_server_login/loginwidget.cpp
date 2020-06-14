#include "loginwidget.h"
#include "ui_loginwidget.h"

#include <QHostAddress>
#include "proto.h"

loginWidget::loginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWidget)
{
//    ui->setupUi(this);
    //界面
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix1/img/erweima.PNG"))));
    this->setPalette(pal);

    this->setMaximumSize(359,359);
    this->setMinimumSize(359,359);

    sd = new QUdpSocket();
    sd->bind(QHostAddress(LOGIN_SERVER_IP),LOGIN_SERVER_PORT);

    connect(sd,SIGNAL(readyRead()),this,SLOT(sdReadyReadSlot()));
}

loginWidget::~loginWidget()
{
    delete ui;
}

void loginWidget::sdReadyReadSlot()
{
    //请求登录
    login_t rcvreg;
    QHostAddress raddr;
    quint16 rport;

    sd->readDatagram((char *)&rcvreg,sizeof(rcvreg),&raddr,&rport);
    qDebug() << rcvreg.cnt << rcvreg.pwd ;

    //sql
    QSqlDatabase sql = QSqlDatabase::addDatabase("QSQLITE");

    sql.setDatabaseName("E:\\Project\\QtPrj\\build-QQ_server-Desktop_Qt_5_9_0_MinGW_32bit-Debug\\debug//server.dat");

    //打开sql
    if (!sql.open()) {
        qDebug() << "Error:关门了!" << sql.lastError();
    }else {
        qDebug() << "Succeed:接客!";
    }

    //查表
    QSqlQuery sql_query;

    QString select_sql = "select * from regTable where count=?";
    sql_query.prepare(select_sql);
    sql_query.addBindValue(rcvreg.cnt);
    if (!sql_query.exec()) {
        qDebug() << sql_query.lastError();
    } else {
        if (sql_query.next()) {
            //注册过
            char *pwd = sql_query.value(1).toString().toLatin1().data();
            if (strcmp(pwd,rcvreg.pwd) == 0) {
                rcvreg.login_state = LOGIN_OK;
                qDebug() << "ok" << sql_query.lastError();
            } else {
                rcvreg.login_state = LOGIN_ERRORPW;
            }
        } else {
            //未注册
            rcvreg.login_state = LOGIN_NOTEXISTS;
        }
    }

    sql.close();

    sd->writeDatagram((char *)&rcvreg, sizeof(rcvreg),raddr,rport);

}

