#include "testwidget.h"
#include "ui_testwidget.h"

#include <QColor>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QLineEdit>
#include <QPushButton>
#include <QWidget>

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("测试"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/xiaohui.png")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(1334,750);
    this->setMinimumSize(1334,750);

    setStyleSheet ("border:2px groove gray;border-radius:10px;padding:2px 4px;");
//  setWindowOpacity(0.7);

    //背景

    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix1/img.png"))));
    this->setPalette(pal);

    //字体
    QWidget *Font = new QWidget;
    chkBoxUnder = new QCheckBox("Underline");
    chkBoxItalic = new QCheckBox("Italic");
    chkBoxBold = new QCheckBox("Bold");

    QFont chkBoxUnderfont = chkBoxUnder->font();
    chkBoxUnderfont.setUnderline("bool");
    chkBoxUnder->setFont(chkBoxUnderfont);

    QFont chkBoxItalicfont = chkBoxItalic->font();
    chkBoxItalicfont.setItalic("bool b");
    chkBoxItalic->setFont(chkBoxItalicfont);

    QFont chkBoxBoldfont = chkBoxBold->font();
    chkBoxBoldfont.setBold("Bool");
    chkBoxBold->setFont(chkBoxBoldfont);

    QHBoxLayout *FontLay = new QHBoxLayout;
    FontLay ->addWidget(chkBoxUnder);
    FontLay ->addWidget(chkBoxItalic);
    FontLay ->addWidget(chkBoxBold);


    //颜色
    QWidget *Colour = new QWidget;
    radioButtonRed = new QRadioButton("Red");
    radioButtonBlue = new QRadioButton("Blue");
    radioButtonBlack = new QRadioButton("Black");

    radioButtonRed->setStyleSheet("color:red");
    radioButtonBlue->setStyleSheet("color:Blue");
    radioButtonBlack->setStyleSheet("color:Black");

    QHBoxLayout *ColourLay = new QHBoxLayout;
    ColourLay ->addWidget(radioButtonRed);
    ColourLay ->addWidget(radioButtonBlue);
    ColourLay ->addWidget(radioButtonBlack);

    //文本框
    txtEdt = new QPlainTextEdit();
    txtEdt->setPlainText(QString("hi"));
    txtEdt->setStyleSheet("background-color: rgb(255, 255, 255, 60);");
    QFont font = txtEdt->font();
    font.setPointSize(14);
    txtEdt->setFont(font);

    //确认
    pushButtonOK =  new QPushButton("确定");
    pushButtonCancl =  new QPushButton("取消");

    pushButtonOK->setStyleSheet("color:pink");
    QFont pushButtonOKfont = pushButtonOK->font();
    pushButtonOKfont.setBold("Bool");
    pushButtonOK->setFont(pushButtonOKfont);

    pushButtonCancl->setStyleSheet("color:pink");
    QFont pushButtonCanclfont = pushButtonCancl->font();
    pushButtonCanclfont.setBold("Bool");
    pushButtonCancl->setFont(pushButtonCanclfont);

    QHBoxLayout *ChooseLay = new QHBoxLayout;
    ChooseLay->addStretch();
    ChooseLay ->addWidget(pushButtonOK);
    ChooseLay->addStretch();
    ChooseLay ->addWidget(pushButtonCancl);
    ChooseLay->addStretch();


    QVBoxLayout *mainLay = new QVBoxLayout;
    mainLay->addLayout(FontLay);
    mainLay->addLayout(ColourLay);
    mainLay->addWidget(txtEdt);
    mainLay->addLayout(ChooseLay);

    this->setLayout(mainLay);

    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(Underlineslots()));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(Italicslots()));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(Boldslots()));

    connect(radioButtonRed,SIGNAL(clicked(bool)),this,SLOT(redlots()));
    connect(radioButtonBlue,SIGNAL(clicked(bool)),this,SLOT(Blueslots()));
    connect(radioButtonBlack,SIGNAL(clicked(bool)),this,SLOT(Blackslots()));

    connect(pushButtonOK,SIGNAL(clicked(bool)),this,SLOT(OKslots()));
    connect(pushButtonCancl,SIGNAL(clicked(bool)),this,SLOT(Canclslots()));
}

TestWidget::~TestWidget()
{
    delete ui;
}

void TestWidget::Underlineslots()
{
    QFont font = txtEdt->font();
    if (chkBoxUnder->isChecked())
        font.setUnderline(true);
    else
        font.setUnderline(false);
    txtEdt->setFont(font);
}

void TestWidget::Italicslots()
{
    QFont font = txtEdt->font();
    if (chkBoxItalic->isChecked())
        font.setItalic(true);
    else
        font.setItalic(false);
    txtEdt->setFont(font);
}

void TestWidget::Boldslots()
{
    QFont font = txtEdt->font();
    if (chkBoxBold->isChecked())
        font.setBold(true);
    else
        font.setBold(false);
    txtEdt->setFont(font);
}

void TestWidget::redlots()
{
    QString curText =  txtEdt->toPlainText();
    QString colorText;
    colorText.append(curText);
    txtEdt->clear();
    colorText.clear();
    colorText.append("<font color=\"#FF0000\">");
    colorText.append(curText);
    colorText.append("</font>");
    txtEdt->clear();
    txtEdt->appendHtml(colorText);
}

void TestWidget::Blueslots()
{
    QString curText =  txtEdt->toPlainText();
    QString colorText;
    colorText.append(curText);
    txtEdt->clear();
    colorText.clear();
    colorText.append("<font color=\"#0000FF\">");
    colorText.append(curText);
    colorText.append("</font>");
    txtEdt->clear();
    txtEdt->appendHtml(colorText);
}

void TestWidget::Blackslots()
{
    QString curText =  txtEdt->toPlainText();
    QString colorText;
    colorText.append(curText);
    txtEdt->clear();
    colorText.clear();
    colorText.append("<font color=\"#000000\">");
    colorText.append(curText);
    colorText.append("</font>");
    txtEdt->clear();
    txtEdt->appendHtml(colorText);
}

void TestWidget::OKslots()
{

}

void TestWidget::Canclslots()
{
    txtEdt->setStyleSheet("background-color: rgb(255, 255, 255, 60);");
}
