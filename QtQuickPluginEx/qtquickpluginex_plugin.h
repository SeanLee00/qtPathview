#ifndef QTQUICKPLUGINEX_PLUGIN_H
#define QTQUICKPLUGINEX_PLUGIN_H

#include <QQmlExtensionPlugin>

class QtQuickPluginExPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // QTQUICKPLUGINEX_PLUGIN_H
