#ifndef WAIJINGW_H
#define WAIJINGW_H

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

namespace Ui {
class waijingw;
}

class waijingw : public QWidget
{
    Q_OBJECT

public:
    explicit waijingw(QWidget *parent = 0);
    ~waijingw();

private slots:
    void logoutSlot();

private:
    Ui::waijingw *ui;
    QLabel * tuxiang;
    QProgressBar *wProgressBar;
    QProgressBar *sProgressBar;
    QHBoxLayout *wsLay;
    QHBoxLayout *txLay;
    QPushButton * sxts;
    QPushButton * sxtz;
    QPushButton * sxtx;
    QPushButton * sxty;
    QGridLayout *sxtLay;
    QLabel * label;
    QDateTime * local;
    QPushButton *logout;
    QHBoxLayout *logoutLay;
    QVBoxLayout *mainLay;
};

#endif // WAIJINGW_H
