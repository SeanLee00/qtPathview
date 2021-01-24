#ifndef SEND_H
#define SEND_H
#include <QThread>
#include <QtDBus/QtDBus>

class WorkerThread : public QThread
{
    Q_OBJECT
    void run();
};
class SEND :public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ number NOTIFY numberChanged)
signals:
    void numberChanged();
public:
    explicit SEND(QObject *parent = 0);
    void careateRandomNumber();
    //
    void send();
    void dbusConnection();
    int number();
public slots:
    int randnumber();
    void update();
private:
    int rand;
    QDBusMessage msg;
};
#endif // SEND_H
