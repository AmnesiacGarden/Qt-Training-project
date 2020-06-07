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
#include "qqwidget.h"

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = 0);
    ~Chat();

private:
    Ui::Chat *ui;
    QLabel * Avatar;
    QPushButton *pushButtonchat;
    QPushButton *pushButtonlinkman;
    QPushButton *pushButtonset;
    QVBoxLayout *zuoLay;
    QTreeWidget *treeWidget;
    QTreeWidgetItem *list1;
    QTreeWidgetItem *leaf1;
    QTreeWidgetItem *list2;
    QTreeWidgetItem *leaf2;
    QTreeWidgetItem *list3;
    QTreeWidgetItem *leaf3;
    QVBoxLayout *zhongLay;
    QPlainTextEdit *nametxt;
    QPlainTextEdit *displaytxt;
    QPlainTextEdit *scantxt;
    QPushButton *pushButtonsend;
    QHBoxLayout *pushButtonsendLay;
    QVBoxLayout *youLay;
    QHBoxLayout *mainLay;

};

#endif // CHAT_H
