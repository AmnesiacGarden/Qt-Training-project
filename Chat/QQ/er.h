#ifndef ER_H
#define ER_H

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
#include "proto.h"
#include <QUdpSocket>
#include "qqwidget.h"

namespace Ui {
class er;
}

class er : public QWidget
{
    Q_OBJECT

public:
    explicit er(QWidget *parent = 0);
    ~er();

private:
    Ui::er *ui;
};

#endif // ER_H
