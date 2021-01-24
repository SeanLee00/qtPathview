#include "viewer.h"
#include "chat_adaptor.h"
#include "chat_interface.h"

Viewer::Viewer(QObject *parent)
{
    QDBusConnection::sessionBus().registerObject("/", parent);
    org::example::chat *iface;
    iface = new org::example::chat(QString(), QString(),
                                   rent);
    QDBusConnection::sessionBus(), pa
            connect(iface, SIGNAL(message(int)), this, SLOT(getNumber(int)));
}
void Viewer::getNumber(int number)
{
    getnumber = number;
    qDebug() << "getnumber :" << getnumber;
    emit numberChanged(number);
}
int Viewer::number()
{
    return getnumber;
}
