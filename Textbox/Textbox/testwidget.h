#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

namespace Ui {
class TestWidget;
}

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidget(QWidget *parent = 0);
    ~TestWidget();

private slots:
    void Underlineslots();
    void Italicslots();
    void Boldslots();

    void redlots();
    void Blueslots();
    void Blackslots();

    void OKslots();
    void Canclslots();

private:
    Ui::TestWidget *ui;
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;

    QRadioButton *radioButtonRed;
    QRadioButton *radioButtonBlue;
    QRadioButton *radioButtonBlack;

    QPlainTextEdit *txtEdt;

    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancl;
};

#endif // TESTWIDGET_H
