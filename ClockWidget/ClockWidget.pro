TEMPLATE = lib
TARGET = ClockWidget
QT += qml quick
CONFIG += plugin c++11 qmltypes

QML_IMPORT_NAME = splitscreen.clock
QML_IMPORT_MAJOR_VERSION = 1
#CONFIG += qmltypes to instruct the build system to generate QML types.
#QML_IMPORT_NAME = <my.import.name> to specify the import name.
#QML_IMPORT_MAJOR_VERSION = <version> to specify the import major version.

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.mycompany.qmlcomponents

# Input
SOURCES += \
        clockwidget_plugin.cpp \
        myitem.cpp

HEADERS += \
        clockwidget_plugin.h \
        myitem.h

DISTFILES = qmldir \
    imports/TimeExample/Clock.qml \
    imports/TimeExample/center.png \
    imports/TimeExample/clock.png \
    imports/TimeExample/hour.png \
    imports/TimeExample/minute.png \
    imports/TimeExample/qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

#///////////////////////

#QML_IMPORT_NAME = TimeExample
#QML_IMPORT_MAJOR_VERSION = 1

#DESTDIR = imports/$$QML_IMPORT_NAME
#TARGET  = qmlqtimeexampleplugin
#QMLTYPES_FILENAME = $$DESTDIR/plugins.qmltypes

#PLUGINFILES = \
#    imports/$$QML_IMPORT_NAME/qmldir \
#    imports/$$QML_IMPORT_NAME/center.png \
#    imports/$$QML_IMPORT_NAME/clock.png \
#    imports/$$QML_IMPORT_NAME/Clock.qml \
#    imports/$$QML_IMPORT_NAME/hour.png \
#    imports/$$QML_IMPORT_NAME/minute.png

#target.path = $$[QT_INSTALL_EXAMPLES]/qml/qmlextensionplugins/imports/$$QML_IMPORT_NAME

#pluginfiles_copy.files = $$PLUGINFILES
#pluginfiles_copy.path = $$DESTDIR

#pluginfiles_install.files = $$PLUGINFILES $$OUT_PWD/$$DESTDIR/plugins.qmltypes
#pluginfiles_install.path = $$[QT_INSTALL_EXAMPLES]/qml/qmlextensionplugins/imports/$$QML_IMPORT_NAME

#qml_copy.files = plugins.qml plugins.qmlproject
#qml_copy.path = $$OUT_PWD

#qml_install.files = plugins.qml plugins.qmlproject
#qml_install.path = $$[QT_INSTALL_EXAMPLES]/qml/qmlextensionplugins

#INSTALLS += target qml_install pluginfiles_install
#COPIES += qml_copy pluginfiles_copy

#OTHER_FILES += $$PLUGINFILES plugins.qml

#CONFIG += install_ok  # Do not cargo-cult this!
