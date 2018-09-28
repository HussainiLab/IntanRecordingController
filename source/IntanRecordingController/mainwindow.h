//  ------------------------------------------------------------------------
//
//  This file is part of the Intan Technologies RHD2000 Interface
//  Version 2.05
//  Copyright (C) 2013-2017 Intan Technologies
//
//  ------------------------------------------------------------------------
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <queue>
#include "rhd2000datablockusb3.h"
#include "rhd2000evalboardusb3.h"
#include "globalconstants.h"

class QAction;
class QPushButton;
class QToolButton;
class QButtonGroup;
class QRadioButton;
class QCheckBox;
class QSpinBox;
class QComboBox;
class QSlider;
class QLineEdit;
class QLabel;
class QFile;
class WavePlot;
class SignalProcessor;
class Rhd2000EvalBoardUsb3;
class SignalSources;
class SignalGroup;
class SignalChannel;
class SpikeScopeDialog;
class KeyboardShortcutDialog;
class HelpDialogChipFilters;
class HelpDialogComparators;
class HelpDialogDacs;
class HelpDialogHighpassFilter;
class HelpDialogNotchFilter;
class HelpDialogFastSettle;
class HelpDialogReference;
class HelpDialogIOExpander;
class WaitForTriggerDialog;
class UsbDataThread;
class DataStreamFifo;

using namespace std;

struct ReferenceSource {
    int stream;
    int channel;
    bool softwareMode;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    void setNumWaveformsComboBox(int index);

    QComboBox *yScaleComboBox;
    QComboBox *yScaleAdcComboBox;
    QComboBox *tScaleComboBox;

    QVector<int> yScaleList;
    QVector<int> yScaleAdcList;
    QVector<int> tScaleList;
    QVector<QVector<bool> > channelVisible;

    int getEvalBoardMode();
    bool isRecording();
    ReferenceSource getReferenceSource();
    bool markerMode();
    bool resetXOnMarker();
    int markerChannel();
    bool showV0Axis();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void about();
    void keyboardShortcutsHelp();
    void chipFiltersHelp();
    void comparatorsHelp();
    void dacsHelp();
    void highpassFilterHelp();
    void notchFilterHelp();
    void fastSettleHelp();
    void ioExpanderHelp();
    void openIntanWebsite();
    void runInterfaceBoard();
    void recordInterfaceBoard();
    void triggerRecordInterfaceBoard();
    void stopInterfaceBoard();
    void selectBaseFilenameSlot();
    void changeNumFrames(int index);
    void changeYScale(int index);
    void changeYScaleAdc(int index);
    void changeTScale(int index);
    void changeSampleRate(int sampleRateIndex);
    void changeNotchFilter(int notchFilterIndex);
    void enableHighpassFilter(bool enable);
    void highpassFilterLineEditChanged();
    void changeBandwidth();
    void changeImpedanceFrequency();
    void changePort(int port);
    void changeDacGain(int index);
    void changeDacNoiseSuppress(int index);
    void dacEnable(bool enable);
    void dacSetChannel();
    void dacSelected(int dacChannel);
    void renameChannel();
    void sortChannelsByNumber();
    void sortChannelsByName();
    void restoreOriginalChannelOrder();
    void alphabetizeChannels();
    void toggleChannelEnable();
    void enableAllChannels();
    void disableAllChannels();
    void spikeScope();
    void newSelectedChannel(SignalChannel* newChannel);
    void scanPorts();
    void enableFastSettle(int enabled);
    void enableExternalFastSettle(bool enabled);
    void setExternalFastSettleChannel(int channel);
    void loadSettings();
    void saveSettings();
    void showImpedances(bool enabled);
    void saveImpedances();
    void runImpedanceMeasurement();
    void configDigOutControl();
    void manualCableDelayControl();
    void plotPointsMode(bool enabled);
    void setSaveFormatDialog();
    void setDacThreshold1(int threshold);
    void setDacThreshold2(int threshold);
    void setDacThreshold3(int threshold);
    void setDacThreshold4(int threshold);
    void setDacThreshold5(int threshold);
    void setDacThreshold6(int threshold);
    void setDacThreshold7(int threshold);
    void setDacThreshold8(int threshold);
    void referenceSetSelectedChannel();
    void referenceSetHardware();
    void referenceHelp();

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void createLayout();

    int openInterfaceBoard(bool &expanderBoardDetected);
    void initializeInterfaceBoard();
    void findConnectedAmplifiers();
    int deviceId(Rhd2000DataBlockUsb3 *dataBlock, int stream, int &register59Value);

    void selectBaseFilename(SaveFormat format);
    void updateImpedanceFrequency();
    void setDacGainLabel(int gain);
    void setDacNoiseSuppressLabel(int noiseSuppress);
    void setDacChannelLabel(int dacChannel, QString channel, QString name);

    void writeSaveFileHeader(QDataStream &outStream, QDataStream &infoStream, SaveFormat format);
    void factorOutParallelCapacitance(double &trueMagnitude, double &impedancePhase,
                                      double frequency, double parasiticCapacitance);
    void empiricalResistanceCorrection(double &impedanceMagnitude, double &impedancePhase,
                                       double boardSampleRate);

    void setStatusBarReady();
    void setStatusBarRunning();
    void setStatusBarRecording(double bytesPerMinute, double totalElapsedRecordTimeSeconds);
    void setStatusBarWaitForTrigger();

    void setSaveFormat(SaveFormat format);
    void startNewSaveFile(SaveFormat format);
    void closeSaveFile(SaveFormat format);

    void setHighpassFilterCutoff(double cutoff);

    void updateAuxDigOut();
    void referenceSetChannel();

    int ttlOut[16];
    int evalBoardMode;
    int numSpiPorts;
    bool expanderBoardConnected;

    bool running;
    bool recording;
    bool triggerSet;
    bool triggered;

    bool saveTtlOut;
    bool validFilename;
    bool synthMode;

    QString saveBaseFileName;
    QString saveFileName;
    QFile *saveFile;
    QDataStream *saveStream;

    QString infoFileName;
    QFile *infoFile;
    QDataStream *infoStream;

    SaveFormat saveFormat;
    int newSaveFilePeriodMinutes;

    unsigned int numUsbBlocksToRead;

    Rhd2000EvalBoardUsb3 *evalBoard;
    SignalSources *signalSources;

    double cableLengthPortA;  // in meters
    double cableLengthPortB;  // in meters
    double cableLengthPortC;  // in meters
    double cableLengthPortD;  // in meters
    double cableLengthPortE;  // in meters
    double cableLengthPortF;  // in meters
    double cableLengthPortG;  // in meters
    double cableLengthPortH;  // in meters

    double desiredDspCutoffFreq;
    double actualDspCutoffFreq;
    double desiredUpperBandwidth;
    double actualUpperBandwidth;
    double desiredLowerBandwidth;
    double actualLowerBandwidth;
    bool dspEnabled;
    double notchFilterFrequency;
    double notchFilterBandwidth;
    bool notchFilterEnabled;
    double highpassFilterFrequency;
    bool highpassFilterEnabled;
    bool fastSettleEnabled;
    double desiredImpedanceFreq;
    double actualImpedanceFreq;
    bool impedanceFreqValid;

    int recordTriggerChannel;
    int recordTriggerPolarity;
    int recordTriggerBuffer;
    int postTriggerTime;
    bool saveTriggerChannel;

    ReferenceSource referenceSource;

    QVector<bool> auxDigOutEnabled;
    QVector<int> auxDigOutChannel;
    QVector<bool> manualDelayEnabled;
    QVector<int> manualDelay;

    double boardSampleRate;

    QVector<double> sampleRateList;

    QVector<SignalChannel*> dacSelectedChannel;
    QVector<bool> dacEnabled;
    QVector<int> chipId;

    queue<Rhd2000DataBlockUsb3> dataQueue;

    WavePlot *wavePlot;
    SignalProcessor *signalProcessor;

    UsbDataThread *usbDataThread;
    DataStreamFifo *usbStreamFifo;
    unsigned char* usbReadBuffer;

    SpikeScopeDialog *spikeScopeDialog;
    KeyboardShortcutDialog *keyboardShortcutDialog;
    HelpDialogChipFilters *helpDialogChipFilters;
    HelpDialogComparators *helpDialogComparators;
    HelpDialogDacs *helpDialogDacs;
    HelpDialogHighpassFilter *helpDialogHighpassFilter;
    HelpDialogNotchFilter *helpDialogNotchFilter;
    HelpDialogFastSettle *helpDialogFastSettle;
    HelpDialogReference *helpDialogReference;
    HelpDialogIOExpander *helpDialogIOExpander;

    QAction *loadSettingsAction;
    QAction *saveSettingsAction;
    QAction *exitAction;
    QAction *originalOrderAction;
    QAction *alphaOrderAction;
    QAction *aboutAction;
    QAction *intanWebsiteAction;
    QAction *keyboardHelpAction;
    QAction *renameChannelAction;
    QAction *toggleChannelEnableAction;
    QAction *enableAllChannelsAction;
    QAction *disableAllChannelsAction;

    QMenu *fileMenu;
    QMenu *channelMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;

    QPushButton *runButton;
    QPushButton *recordButton;
    QPushButton *triggerButton;
    QPushButton *stopButton;
    QPushButton *baseFilenameButton;
    QPushButton *renameChannelButton;
    QPushButton *enableChannelButton;
    QPushButton *enableAllButton;
    QPushButton *disableAllButton;
    QPushButton *spikeScopeButton;
    QPushButton *changeBandwidthButton;
    QPushButton *impedanceFreqSelectButton;
    QPushButton *runImpedanceTestButton;
    QPushButton *dacSetButton;
    QPushButton *scanButton;
    QPushButton *digOutButton;
    QPushButton *saveImpedancesButton;
    QPushButton *setSaveFormatButton;
    QPushButton *setCableDelayButton;
    QPushButton *refSelectButton;
    QPushButton *refHardwareRefButton;

    QToolButton *helpDialogChipFiltersButton;
    QToolButton *helpDialogComparatorsButton;
    QToolButton *helpDialogDacsButton;
    QToolButton *helpDialogHighpassFilterButton;
    QToolButton *helpDialogNotchFilterButton;
    QToolButton *helpDialogSettleButton;
    QToolButton *helpDialogRefButton;
    QToolButton *helpDialogIOExpanderButton;

    QCheckBox *dacEnableCheckBox;
    QCheckBox *dacLockToSelectedBox;
    QCheckBox *fastSettleCheckBox;
    QCheckBox *externalFastSettleCheckBox;
    QCheckBox *showImpedanceCheckBox;
    QCheckBox *plotPointsCheckBox;
    QCheckBox *highpassFilterCheckBox;
    QCheckBox *v0AxisLineCheckBox;
    QCheckBox *displayMarkerCheckBox;
    QCheckBox *displayTriggerCheckBox;

    QRadioButton *displayPortAButton;
    QRadioButton *displayPortBButton;
    QRadioButton *displayPortCButton;
    QRadioButton *displayPortDButton;
    QRadioButton *displayPortEButton;
    QRadioButton *displayPortFButton;
    QRadioButton *displayPortGButton;
    QRadioButton *displayPortHButton;
    QRadioButton *displayAdcButton;
    QRadioButton *displayDigInButton;

    QButtonGroup *dacButtonGroup;
    QRadioButton *dacButton1;
    QRadioButton *dacButton2;
    QRadioButton *dacButton3;
    QRadioButton *dacButton4;
    QRadioButton *dacButton5;
    QRadioButton *dacButton6;
    QRadioButton *dacButton7;
    QRadioButton *dacButton8;

    QComboBox *numFramesComboBox;
    QComboBox *sampleRateComboBox;
    QComboBox *notchFilterComboBox;

    QSpinBox *dac1ThresholdSpinBox;
    QSpinBox *dac2ThresholdSpinBox;
    QSpinBox *dac3ThresholdSpinBox;
    QSpinBox *dac4ThresholdSpinBox;
    QSpinBox *dac5ThresholdSpinBox;
    QSpinBox *dac6ThresholdSpinBox;
    QSpinBox *dac7ThresholdSpinBox;
    QSpinBox *dac8ThresholdSpinBox;
    QSpinBox *externalFastSettleSpinBox;
    QSpinBox *displayMarkerSpinBox;

    QSlider *dacGainSlider;
    QSlider *dacNoiseSuppressSlider;

    QLineEdit *saveFilenameLineEdit;
	QLineEdit *saveSettingsFilenameLineEdit; // added by GMB
    QLineEdit *highpassFilterLineEdit;
    QLineEdit *note1LineEdit;
    QLineEdit *note2LineEdit;
    QLineEdit *note3LineEdit;

    QLabel *voltageScaleLabel;
    QLabel *statusBarLabel;
    QLabel *fifoLagLabel;
    QLabel *fifoFullLabel;
    QLabel *bufferFullLabel;
    QLabel *cpuWarningLabel;
    QLabel *dspCutoffFreqLabel;
    QLabel *upperBandwidthLabel;
    QLabel *lowerBandwidthLabel;
    QLabel *desiredImpedanceFreqLabel;
    QLabel *actualImpedanceFreqLabel;
    QLabel *dacGainLabel;
    QLabel *dacNoiseSuppressLabel;
    QLabel *refTypeLabel;
    QLabel *refChannelLabel;
};


#endif // MAINWINDOW_H
