#ifndef CHAT_H
#define CHAT_H

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
#include "qqwidget.h"
#include "windows.h"
#include "chekuw.h"
#include "dixiashiw.h"
#include "waijingw.h"
#include "waidamenw.h"
#include "woshiw.h"
#include "chufangw.h"

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = 0);
    ~Chat();

private slots:
    void ketingSlot();
    void dixiashiSlot();
    void waijingSlot();
    void woshi1Slot();
    void woshi2Slot();
    void woshi3Slot();
    void chekuSlot();
    void chufangSlot();
    void waidamenSlot();
    void logoutSlot();

private:
    Ui::Chat *ui;
    QLabel * label;
    QDateTime * local;
    QPushButton *keting;
    QPushButton *dixiashi;
    QPushButton *waijing;
    QPushButton *woshi1;
    QPushButton *woshi2;
    QPushButton *woshi3;
    QPushButton *cheku;
    QPushButton *chufang;
    QPushButton *waidamen;
    QGridLayout *butLay;
    QPushButton *logout;
    QHBoxLayout *logoutLay;
    QVBoxLayout *mainLay;

};

#endif // CHAT_H
