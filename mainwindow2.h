#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow2; }
QT_END_NAMESPACE

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private slots:
       void tcpNewConnection(); //绑定sever的NewConnection信号
       void tcpReadyRead();  //用来绑定socket的Readyread信号
       void tcpDisconnect(); //用来绑定socket的disconnect的信号

       void on_pushButton_clicked();

private:
    Ui::MainWindow2 *ui;


    QTcpServer *mTcpServer;
    QTcpSocket *mSocket;
};
#endif // MAINWINDOW_H
