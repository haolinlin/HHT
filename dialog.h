#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>


#include <QTcpSocket>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow1; }
QT_END_NAMESPACE

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

   // void tcpReadyRead();

private slots:
    //void on_pushButton_clicked();
    void tcpReadyRead();


    void reconnect();
    void tcpConnect();
    void sendDate();

    void on_pushButton1_clicked();

    //void on_pushButton_clicked();

private:
    Ui::MainWindow1 *ui;
  QTcpSocket *mSocket;

  QTimer *mTimer;
  QTimer *mTimer2;

};
#endif // MAINWINDOW_H
