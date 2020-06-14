#ifndef WAIDAMENW_H
#define WAIDAMENW_H

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
class waidamenw;
}

class waidamenw : public QWidget
{
    Q_OBJECT

public:
    explicit waidamenw(QWidget *parent = 0);
    ~waidamenw();

private slots:
    void deng1Slot();
    void deng2Slot();
    void kaiSlot();
    void guanSlot();
    void logoutSlot();

private:
    Ui::waidamenw *ui;
    QProgressBar *wProgressBar;
    QProgressBar *sProgressBar;
    QHBoxLayout *wsLay;
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
    QVBoxLayout *anjianLay;
    QHBoxLayout *jiemianLay;
    QPushButton *logout;
    QHBoxLayout *logoutLay;
    QVBoxLayout *mainLay;
};

#endif // WAIDAMENW_H
