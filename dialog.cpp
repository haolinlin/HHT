#include "dialog.h"
#include "ui_mainwindow1.h"

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QtDebug>

/*
//任务：
//服务端断开，服务器重新监听的时候，客户端要再次连上
// connect(mSocket, SIGNAL(disconnected()), this, SLOT(reconnect()));
//connect(mSoc

//connect(mSocket,SIGNAL)

 //connect(mTimer,SIGNAL(timeout()),this,SLOT(reconnect()) );
  //connect(mSocket,SIGNAL(disconnected()), this,SLOT(restart()));
  //void MainWindow::


//任务2：实现用定时器服务端->客户端 每1秒发送一次数据   数据内容”111“
同时客户端->像服务端 每1秒发送一次数据                数据内容”AAAA“


*/

MainWindow1::MainWindow1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow1)
{
    ui->setupUi(this);

    mSocket = new QTcpSocket(this);

    connect(mSocket,SIGNAL(readyRead()),this, SLOT(tcpReadyRead()));
 //  connect(mSocket,SIGNAL(connected()), mTimer,SLOT(stop()));


 // mSocket->connectToHost(QHostAddress::LocalHost,1234);

  mTimer = new QTimer(this);

 connect(mTimer,SIGNAL(timeout()),this,SLOT(reconnect()) );//计时时间到重连
  connect(mSocket,SIGNAL(connected()), mTimer,SLOT(stop()));

  connect(mSocket,SIGNAL(disconnected()),mTimer,SLOT(start()));//定时器断开后重新计时

  mTimer->start(2000); //每500ms就发生timeout

  connect(mSocket,SIGNAL(connected()), this , SLOT(tcpConnect()));
  mTimer2 = new QTimer(this);
  connect(mTimer2,SIGNAL(timeout()), this , SLOT(sendDate()));

}

MainWindow1::~MainWindow1()
{
    delete ui;
}


void MainWindow1::tcpReadyRead()
{

    ui->textEdit_1_1->append(mSocket->readAll());
}


void MainWindow1::reconnect()
{


    if(mSocket->state() == QAbstractSocket::UnconnectedState)
    {
        qDebug()<<"try to connectToHost";

  mSocket->connectToHost(QHostAddress::LocalHost,1235);
    }

 }
void MainWindow1::tcpConnect()
{
    mTimer2 = new QTimer(this);//来一次就new一个timer
    connect(mTimer2,SIGNAL(timeout()), this , SLOT(sendDate()));
    connect(mSocket,SIGNAL(disconnected()),mTimer2, SLOT(deleteLater()));//断开就重连


        }

void MainWindow1::sendDate()
{
    if(mSocket->state() == QAbstractSocket::UnconnectedState)
    return;

    mSocket->write("1111111");


}

void MainWindow1::on_pushButton1_clicked()
{

    if(mSocket->state() == QAbstractSocket::UnconnectedState)
        return;

        mSocket->write(ui->lineEdit_1_1->text().toLatin1());

}


