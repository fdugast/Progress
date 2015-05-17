QT       += core gui widgets positioning

TARGET = progress
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    starterform.cpp

#qtHaveModule(opengl) {
    QT += opengl

    SOURCES += mainwidget.cpp \
       geometryengine.cpp

    HEADERS += \
        mainwidget.h \
        geometryengine.h \
    mainwindow.h \
    starterform.h

    RESOURCES += \
        shaders.qrc \
        textures.qrc
#}

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/opengl/cube
INSTALLS += target

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS =
}

FORMS += \
    mainwindow.ui \
    starterform.ui

symbian:TARGET.CAPABILITY += NetworkServices Location

MOBILITY += location systeminfo

CONFIG += mobility
