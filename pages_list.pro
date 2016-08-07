TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    pagedlist.cpp


INCLUDEPATH += __submodules/boost \
  __submodules/btree/include \
  __submodules/boost/libs/endian/include \

DEFINES += DT_RUNPATH=built_boost

LIBS += -Lbuilt_boost -l:"libboost_btree.so.1.61.0" -l:"libboost_system.so.1.61.0" -l:"libboost_filesystem.so.1.61.0"

HEADERS += \
    pagedlist.h
