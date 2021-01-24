#include "send.h"
#include <QTime>
#include <QRandomGenerator>

SEND::SEND(QObject *parent)
{
    careateRandomNumber();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
    //
    WorkerThread t;
    t.start();
}
void SEND::careateRandomNumber()
{
    QTime now = QTime::currentTime();
    qsrand(now.msec());
    rand = qrand();
}
void SEND::send()
{
    careateRandomNumber();
    if (QDBusConnection::sessionBus().isConnected()) {
        msg = QDBusMessage::createSignal("/", "org.example.chat", "message");
        qDebug() << "send message : " << rand;
        msg << rand;
        QDBusConnection::sessionBus().send(msg);
        emit numberChanged();
    }
}
void SEND::dbusConnection()
{
    QDBusConnection::sessionBus().registerObject("/", this);
    if (QDBusConnection::sessionBus().isConnected()) {
        msg = QDBusMessage::createSignal("/", "org.example.chat", "message");
    }
}
int SEND::number()
{
    return rand;
}
int SEND::randnumber()
{
    return rand;
}
void SEND::update()
{
    send();
}
void WorkerThread::run()
{
    qDebug()<<"From worker thread: ";
}
