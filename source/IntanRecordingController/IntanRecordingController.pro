TEMPLATE      = app

QT            += widgets multimedia

CONFIG        += static

macx:{
QMAKE_RPATHDIR += /users/intan/qt/5.7/clang_64/lib
QMAKE_RPATHDIR += /users/intan/downloads/
}

HEADERS       = \
    okFrontPanelDLL.h \
    waveplot.h \
    mainwindow.h \
    signalprocessor.h \
    bandwidthdialog.h \
    renamechanneldialog.h \
    signalchannel.h \
    signalgroup.h \
    signalsources.h \
    spikescopedialog.h \
    spikeplot.h \
    keyboardshortcutdialog.h \
    randomnumber.h \
    impedancefreqdialog.h \
    globalconstants.h \
    triggerrecorddialog.h \
    setsaveformatdialog.h \
    helpdialoghighpassfilter.h \
    helpdialognotchfilter.h \
    helpdialogdacs.h \
    helpdialogcomparators.h \
    helpdialogchipfilters.h \
    auxdigoutconfigdialog.h \
    cabledelaydialog.h \
    helpdialogfastsettle.h \
    datastreamfifo.h \
    usbdatathread.h \
    helpdialogreference.h \
    rhd2000datablockusb3.h \
    rhd2000evalboardusb3.h \
    rhd2000registersusb3.h \
    helpdialogioexpander.h

SOURCES       = main.cpp \
    okFrontPanelDLL.cpp \
    waveplot.cpp \
    mainwindow.cpp \
    signalprocessor.cpp \
    bandwidthdialog.cpp \
    renamechanneldialog.cpp \
    signalchannel.cpp \
    signalgroup.cpp \
    signalsources.cpp \
    spikescopedialog.cpp \
    spikeplot.cpp \
    keyboardshortcutdialog.cpp \
    randomnumber.cpp \
    impedancefreqdialog.cpp \
    triggerrecorddialog.cpp \
    setsaveformatdialog.cpp \
    helpdialoghighpassfilter.cpp \
    helpdialognotchfilter.cpp \
    helpdialogdacs.cpp \
    helpdialogcomparators.cpp \
    helpdialogchipfilters.cpp \
    auxdigoutconfigdialog.cpp \
    cabledelaydialog.cpp \
    helpdialogfastsettle.cpp \
    datastreamfifo.cpp \
    usbdatathread.cpp \
    helpdialogreference.cpp \
    rhd2000datablockusb3.cpp \
    rhd2000evalboardusb3.cpp \
    rhd2000registersusb3.cpp \
    helpdialogioexpander.cpp
    
RESOURCES     = IntanRecordingController.qrc

macx:{
LIBS += -L$$PWD/../../../Downloads/ -lokFrontPanel
INCLUDEPATH += $$PWD/../../../Downloads
DEPENDPATH += $$PWD/../../../Downloads
}
