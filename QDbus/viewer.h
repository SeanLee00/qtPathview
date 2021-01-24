#ifndef VIEWER_H
#define VIEWER_H
#include <QObject>

class Viewer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ number NOTIFY numberChanged)
    signals:
        void onchanged();
    void numberChanged(int n);
public:
    Viewer(QObject *parent = 0);
    int number();
public slots:
    void getNumber(int number);
private:
    int getnumber = 0;
};

#endif // VIEWER_H
