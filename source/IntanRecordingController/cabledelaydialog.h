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

#ifndef CABLEDELAYDIALOG_H
#define CABLEDELAYDIALOG_H

#include <QDialog>

using namespace std;

class QCheckBox;
class QSpinBox;
class QDialogButtonBox;

class CableDelayDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CableDelayDialog(QVector<bool> &manualDelayEnabled, vector<int> &currentDelay, int numPorts, QWidget *parent = 0);
    
    QCheckBox *manualPortACheckBox;
    QCheckBox *manualPortBCheckBox;
    QCheckBox *manualPortCCheckBox;
    QCheckBox *manualPortDCheckBox;
    QCheckBox *manualPortECheckBox;
    QCheckBox *manualPortFCheckBox;
    QCheckBox *manualPortGCheckBox;
    QCheckBox *manualPortHCheckBox;

    QSpinBox *delayPortASpinBox;
    QSpinBox *delayPortBSpinBox;
    QSpinBox *delayPortCSpinBox;
    QSpinBox *delayPortDSpinBox;
    QSpinBox *delayPortESpinBox;
    QSpinBox *delayPortFSpinBox;
    QSpinBox *delayPortGSpinBox;
    QSpinBox *delayPortHSpinBox;

    QDialogButtonBox *buttonBox;

signals:
    
public slots:
    
};

#endif // CABLEDELAYDIALOG_H
