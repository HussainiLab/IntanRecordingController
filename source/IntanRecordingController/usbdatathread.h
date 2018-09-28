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

#ifndef USBDATATHREAD_H
#define USBDATATHREAD_H

#include <QObject>
#include <QThread>
#include "rhd2000evalboardusb3.h"
#include "datastreamfifo.h"

#define BUFFER_SIZE_IN_BLOCKS 32

class UsbDataThread : public QThread
{
    Q_OBJECT
public:
    explicit UsbDataThread(Rhd2000EvalBoardUsb3* board_, DataStreamFifo* usbFifo_,  QObject *parent = 0);
    ~UsbDataThread();

    void run() override;
    void startRunning();
    void stopRunning();
    bool isRunning() const;
    void close();
    void setNumUsbBlocksToRead(int numUsbBlocksToRead_);

signals:
//    void finished();

public slots:

private:
    Rhd2000EvalBoardUsb3* board;
    DataStreamFifo* usbFifo;
    volatile bool keepGoing;
    volatile bool running;
    volatile bool stopThread;
    volatile int numUsbBlocksToRead;

    unsigned char* usbBuffer;

};

#endif // USBDATATHREAD_H
