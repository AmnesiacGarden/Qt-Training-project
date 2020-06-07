#ifndef GRAPHICALWIDGET_H
#define GRAPHICALWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class GraphicalWidget;
}

class GraphicalWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicalWidget(QWidget *parent = 0);
    ~GraphicalWidget();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_rililineEdit_selectionChanged();

    void updateTime200();

    void on_pbStart_clicked();

    void on_pbEnd_clicked();

private:
    Ui::GraphicalWidget *ui;

    QTimer * timer200;//200ms更新

    int steps;//记录值
    bool isStart;        //记录是否已经开始计时
};

#endif // GRAPHICALWIDGET_H
