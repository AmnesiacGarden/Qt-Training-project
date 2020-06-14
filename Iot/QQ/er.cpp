#include "er.h"
#include "ui_er.h"

er::er(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::er)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("二维码"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(372,368);
    this->setMinimumSize(372,368);

    //背景

    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix1/erweima.jpg"))));
    this->setPalette(pal);

}

er::~er()
{
    delete ui;
}
