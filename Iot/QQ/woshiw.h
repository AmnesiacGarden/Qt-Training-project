#ifndef WOSHIW_H
#define WOSHIW_H

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
class woshiw;
}

class woshiw : public QWidget
{
    Q_OBJECT

public:
    explicit woshiw(QWidget *parent = 0);
    ~woshiw();

private slots:
    void kaiSlot();
    void guanSlot();
    void logoutSlot();

private:
    Ui::woshiw *ui;
    QProgressBar *wProgressBar;
    QProgressBar *sProgressBar;
    QHBoxLayout * wsLay;
    QLabel * label;
    QDateTime * local;
    QLabel * tuxiang;
    QPushButton *deng1;
    QPushButton *deng2;
    QHBoxLayout *dengLay;
    QPushButton *kai;
    QPushButton *guan;
    QHBoxLayout *kgLay;
    QPushButton * sxts;
    QPushButton * sxtz;
    QPushButton * sxtx;
    QPushButton * sxty;
    QGridLayout *sxtLay;
    QHBoxLayout *jiemianLay;
    QPushButton *logout;
    QHBoxLayout *logoutLay;
    QVBoxLayout *mainLay;
};

#endif // WOSHIW_H
