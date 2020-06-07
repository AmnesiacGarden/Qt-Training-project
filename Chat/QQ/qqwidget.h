#ifndef QQWIDGET_H
#define QQWIDGET_H

#include <QLabel>
#include <QColor>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QWidget>
#include <QUdpSocket>
#include<QCryptographicHash>
#include<QMessageBox>
#include "proto.h"
#include "reg.h"
#include "er.h"
#include "chat.h"

namespace Ui {
class QQWidget;
}

class QQWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QQWidget(QWidget *parent = 0);
    ~QQWidget();

private slots:
    void zhucelots(void);
    void erlots(void);
    void denglulots(void);
    void sdReadyreadSlot();


private:
    Ui::QQWidget *ui;
    QLabel * Avatar;
    QLineEdit * linezhanghao;
    QLabel * zh;
    QHBoxLayout * linezhanghaoLay;
    QLineEdit * linemima;
    QLabel * mm;
    QHBoxLayout * linemimaLay;
    QWidget * Tick;
    QCheckBox * chkBoxzi;
    QCheckBox * chkBoxji;
    QPushButton * pushButtonzhao;
    QHBoxLayout * TickLay;
    QPushButton * pushButtonOK;
    QHBoxLayout * pushButtonOKLay;
    QPushButton * pushButtonzhu;
    QPushButton * pushButtoner;
    QHBoxLayout * pushButtonzeLay;
    QVBoxLayout *mainLay;
    QUdpSocket * sd;
};

#endif // QQWIDGET_H
