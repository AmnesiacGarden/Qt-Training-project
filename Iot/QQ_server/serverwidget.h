#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

private slots:
   void sdReadyReadSlot();


public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

private:
    Ui::ServerWidget *ui;
    QUdpSocket *sd;

};

#endif // SERVERWIDGET_H
