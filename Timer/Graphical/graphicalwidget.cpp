#include "graphicalwidget.h"
#include "ui_graphicalwidget.h"

#include <QDateTime>
#include <QTimer>

GraphicalWidget::GraphicalWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicalWidget)
{
    ui->setupUi(this);

    isStart = false;     //初始为还未计时
    timer200=new QTimer;
    steps=0;
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->display("0");

    ui->pbEnd->setEnabled(false);
    connect(timer200,SIGNAL(timeout()),this,SLOT(updateTime200()));

}

GraphicalWidget::~GraphicalWidget()
{
    delete ui;
}

void GraphicalWidget::on_pushButton_clicked()
{
    //读取当前日期时间
    QDateTime curDateTime;
    curDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->dateEdit->setDate(curDateTime.date());
    ui->dateTimeEdit->setDateTime(curDateTime);

    ui->timelineEdit->setText(curDateTime.toString("hh:mm:ss"));
    ui->datelineEdit->setText(curDateTime.toString("yyyy-MM-dd"));
    ui->timedatelineEdit->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss "));
}

void GraphicalWidget::updateTime200()
{
    steps++;
    ui->lcdNumber->display(QString("%1").arg(steps));
}

//void GraphicalWidget::on_rililineEdit_selectionChanged()
//{    //获取
//    QDate dt = ui->calendarWidget->selectedDate();
//    ui->rililineEdit->setText(dt.toString("yyyy年MM月dd日"));
//
//}

void GraphicalWidget::on_pbStart_clicked()
{
    if(!isStart) //尚未开始 开始计时
        {
            timer200->start(200);
            ui->pbStart->setDisabled(true);
            ui->pbEnd->setEnabled(true);
        }
        isStart = !isStart;
}

void GraphicalWidget::on_pbEnd_clicked()
{
    ui->pbEnd->setDisabled(true);
        ui->pbStart->setEnabled(true);
        timer200->stop();
        steps=0;
        ui->lcdNumber->display("0");
        isStart = false;
}
