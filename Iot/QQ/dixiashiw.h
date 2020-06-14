#ifndef DIXIASHIW_H
#define DIXIASHIW_H

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
class dixiashiw;
}

class dixiashiw : public QWidget
{
    Q_OBJECT

public:
    explicit dixiashiw(QWidget *parent = 0);
    ~dixiashiw();

private slots:
    void logoutSlot();

private:
    Ui::dixiashiw *ui;
    QProgressBar *wProgressBar;
    QProgressBar *sProgressBar;
    QHBoxLayout *wsLay;
    QLabel * tuxiang;
    QHBoxLayout *txLay;
    QPushButton *logout;
    QLabel * label;
    QDateTime * local;
    QHBoxLayout *logoutLay;
    QVBoxLayout *mainLay;
};

#endif // DIXIASHIW_H
