#ifndef MYITEM_H
#define MYITEM_H

#include <QtQml/qqml.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qbasictimer.h>
#include <QtCore/qcoreapplication.h>
#include <QQuickItem>

class MinuteTimer : public QObject // QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(MinuteTimer)

public:
    explicit MinuteTimer(QObject *parent = nullptr);
    ~MinuteTimer() override;

    void start();
    void stop();

    int hour() const { return time.hour(); }
    int minute() const { return time.minute(); }

signals:
    void timeChanged();

protected:
    void timerEvent(QTimerEvent *) override;

private:
    QTime time;
    QBasicTimer timer;
};


class TimeModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int hour READ hour NOTIFY timeChanged)
    Q_PROPERTY(int minute READ minute NOTIFY timeChanged)
    QML_NAMED_ELEMENT(Time)
//![0]

public:
    TimeModel(QObject *parent=nullptr);
    ~TimeModel() override;

    int minute() const { return timer->minute(); }
    int hour() const { return timer->hour(); }

signals:
    void timeChanged();

private:
    QTime t;
    static MinuteTimer *timer;
    static int instances;
};

#endif // MYITEM_H
