#ifndef REG_H
#define REG_H

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
#include <QString>
#include "qqwidget.h"
#include "proto.h"
#include <QUdpSocket>

namespace Ui {
class reg;
}

class reg : public QWidget
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = 0);
    ~reg();

private slots:
    void zhucelots();
    void sdReadyreadSlot();

private:
    Ui::reg *ui;
    QLineEdit *zhanghao;
    QHBoxLayout *zhanghaoLay;
    QLineEdit *mima;
    QHBoxLayout *mimaLay;
    QPushButton *pushButtonOK;
    QHBoxLayout *pushButtonOKLay;
    QVBoxLayout *mainLay;
    QUdpSocket *sd;
};

#endif // REG_H
