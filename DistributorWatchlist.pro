TEMPLATE = app
TARGET = DistributorWatchlist

QT = core gui network charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    window.h
