#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);

    //窗口属性
    this->setWindowTitle(QString("网络姻缘一线牵"));
    QIcon windowIcon = QIcon(QPixmap(QString(":/new/prefix1/icon1.jpg")));
    this->setWindowIcon(windowIcon);

    this->setMaximumSize(1065,730);
    this->setMinimumSize(1065,730);

    //背景
    QPalette pal;
    pal.setBrush(QPalette::Background,QBrush(QPixmap(QString(":/new/prefix1/bg1.jpg"))));
    this->setPalette(pal);

    //左
    Avatar = new QLabel(this);
    QPixmap pix = QPixmap(":/new/prefix1/Avatar1.jpg");
        Avatar->setPixmap(pix);
        Avatar->resize(80,80);

    pushButtonchat =  new QPushButton();
        pushButtonchat->setStyleSheet("background-color:white");
        pushButtonchat->setFlat(true);
        pushButtonchat->setMaximumSize(45, 45);
        pushButtonchat->setMinimumSize(45, 45);
        pushButtonchat->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/chat.jpg);}");

    pushButtonlinkman =  new QPushButton();
        pushButtonlinkman->setStyleSheet("background-color:white");
        pushButtonlinkman->setFlat(true);
        pushButtonlinkman->setMaximumSize(45, 45);
        pushButtonlinkman->setMinimumSize(45, 45);
        pushButtonlinkman->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/linkman.jpg);}");

    pushButtonset =  new QPushButton();
        pushButtonset->setStyleSheet("background-color:white");
        pushButtonset->setFlat(true);
        pushButtonset->setMaximumSize(45, 45);
        pushButtonset->setMinimumSize(45, 45);
        pushButtonset->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/set.jpg);}");

    zuoLay = new QVBoxLayout;
        zuoLay->addWidget(Avatar);
        zuoLay->addWidget(pushButtonchat);
        zuoLay->addWidget(pushButtonlinkman);
        zuoLay ->addStretch();
        zuoLay->addWidget(pushButtonset);

    //中
    treeWidget = new QTreeWidget();
        treeWidget->setColumnCount(1);
        treeWidget->setMaximumSize(320, 730);
    QStringList headers;
        headers << "富婆通讯录";
        treeWidget->setHeaderLabels(headers);
        treeWidget->setStyleSheet("background-color: rgb(255, 255, 255, 60);");

    list1 = new QTreeWidgetItem(treeWidget, QStringList(QString("广西富婆")));
                leaf1 = new QTreeWidgetItem(list1, QStringList(QString("你还敢点开！")));
                list1->addChild(leaf1);
                QList<QTreeWidgetItem *> rootList1;
                rootList1 << list1;
                treeWidget->insertTopLevelItems(0, rootList1);

    list2 = new QTreeWidgetItem(treeWidget, QStringList(QString("黑龙江富婆")));
                leaf2 = new QTreeWidgetItem(list2, QStringList(QString("你又点开一个！")));
                list2->addChild(leaf2);
                QList<QTreeWidgetItem *> rootList2;
                rootList2 << list2;
                treeWidget->insertTopLevelItems(0, rootList2);

    list3 = new QTreeWidgetItem(treeWidget, QStringList(QString("北京富婆")));
                leaf3 = new QTreeWidgetItem(list3, QStringList(QString("你完了你小小年纪！")));
                list3->addChild(leaf3);
                QList<QTreeWidgetItem *> rootList3;
                rootList3 << list3;
                treeWidget->insertTopLevelItems(0, rootList3);

    zhongLay = new QVBoxLayout;
        zhongLay->addWidget(treeWidget);

    //右
    //聊天名
    nametxt = new QPlainTextEdit();
        nametxt->setMaximumSize(650, 50);
        nametxt->setMinimumSize(650, 50);
        nametxt->setPlainText(QString("名字"));
    QFont name = nametxt->font();
        name.setPointSize(14);
        nametxt->setFont(name);

    //聊天显示
    displaytxt = new QPlainTextEdit();
        displaytxt->setMaximumSize(650, 420);
        displaytxt->setMinimumSize(650, 420);
        displaytxt->setPlainText(QString("聊天记录"));
    QFont display = displaytxt->font();
        display.setPointSize(14);
        displaytxt->setFont(display);

    //输入
    scantxt = new QPlainTextEdit();
        scantxt->setMaximumSize(650, 180);
        scantxt->setMinimumSize(650, 180);
        scantxt->setPlainText(QString("输入"));
    QFont scan = scantxt->font();
        scan.setPointSize(14);
        scantxt->setFont(scan);

    //发送
    pushButtonsend =  new QPushButton("发送(S)");

    pushButtonsendLay = new QHBoxLayout;
        pushButtonsendLay->addStretch();
        pushButtonsendLay ->addWidget(pushButtonsend);

    youLay = new QVBoxLayout;
        youLay->addWidget(nametxt);
        youLay->addWidget(displaytxt);
        youLay->addWidget(scantxt);
        youLay->addLayout(pushButtonsendLay);




    //主显示
    mainLay = new QHBoxLayout;
        mainLay->setContentsMargins(0,20,0,20);
        mainLay->addLayout(zuoLay);
        //mainLay->addStretch();
        mainLay->setContentsMargins(15,0,0,0);
        mainLay->addLayout(zhongLay);
        //mainLay->addStretch();
        mainLay->setContentsMargins(20,0,0,0);
        mainLay->addLayout(youLay);


        this->setLayout(mainLay);
}


Chat::~Chat()
{
    delete ui;
}
