#include "clockwidget_plugin.h"

#include "myitem.h"

#include <qqml.h>

void ClockWidgetPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<MinuteTimer>(uri, 1, 0, "MinuteTimer");
    qmlRegisterType<TimeModel>(uri, 1, 0, "TimeModel");
}

