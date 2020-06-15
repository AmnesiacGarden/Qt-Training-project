#ifndef WINDOWS_H
#define WINDOWS_H

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
#include <QTreeWidget>
#include "proto.h"
#include <QUdpSocket>
#include <QDateTime>
#include <QTimer>
#include <QGridLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include<QMessageBox>

namespace Ui {
class windows;
}

class windows : public QWidget
{
    Q_OBJECT

public:
    explicit windows(QWidget *parent = 0);
    ~windows();

private slots:
    void clzkSlot();
    void clzgSlot();
    void clykSlot();
    void clygSlot();
    void bjqkSlot();
    void deng1Slot();
    void deng2Slot();
    void deng3Slot();
    void deng4Slot();
    void bjqgSlot();
    void kt1kgSlot();
    void kt2kgSlot();
    void logoutSlot();

private:
    Ui::windows *ui;
    QProgressBar *wProgressBar;
    QProgressBar *sProgressBar;
    QHBoxLayout *wsLay;
    QPushButton *clzk;
    QPushButton *clzg;
    QPushButton *clyk;
    QPushButton *clyg;
    QPushButton *bjqk;
    QLabel * tuxiang;
    QPushButton *deng1;
    QPushButton *deng2;
    QPushButton *deng3;
    QPushButton *deng4;
    QPushButton *bjqg;
    QGridLayout *zuoLay;
    QGridLayout *youLay;
    QHBoxLayout *zhongtLay;
    QLCDNumber * kt1;
    QPushButton *kt1jian;
    QPushButton *kt1kg;
    QPushButton *kt1jia;
    QLabel * kt1t;
    QGridLayout *kt1Lay;
    QPushButton * sxts;
    QPushButton * sxtz;
    QPushButton * sxtx;
    QPushButton * sxty;
    QLabel * yuan;
    QGridLayout *sxtLay;
    QLCDNumber * kt2;
    QPushButton *kt2jian;
    QPushButton *kt2kg;
    QPushButton *kt2jia;
    QLabel * kt2t;
    QGridLayout *kt2Lay;
    QHBoxLayout *xiaLay;
 //   QGridLayout *xiaLay;
    QPushButton *logout;
    QHBoxLayout *logoutLay;
    QVBoxLayout *mainLay;
};

#endif // WINDOWS_H
