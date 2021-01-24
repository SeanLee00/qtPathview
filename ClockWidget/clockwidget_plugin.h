#ifndef CLOCKWIDGET_PLUGIN_H
#define CLOCKWIDGET_PLUGIN_H

#include <QQmlExtensionPlugin>

class ClockWidgetPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // CLOCKWIDGET_PLUGIN_H
