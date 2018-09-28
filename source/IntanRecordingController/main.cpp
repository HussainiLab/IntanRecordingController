//  ------------------------------------------------------------------------
//
//  This file is part of the Intan Technologies RHD2000 Interface
//  Version 2.06
//  Copyright (C) 2013-2018 Intan Technologies
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

#include <QApplication>
#include <QMessageBox>
#include <QSplashScreen>
#include <QStyleFactory>

#include "mainwindow.h"
#include "guicon.h"

// Starts application main window.

int main(int argc, char *argv[]){
    //RedirectIOToConsole();

    QApplication app(argc, argv);

    QSplashScreen *splash = new QSplashScreen();
    splash->setPixmap(QPixmap(":/images/splash.png"));

#ifdef __APPLE__
    app.setStyle(QStyleFactory::create("Fusion"));
    splash->setWindowFlags(Qt::WindowStaysOnBottomHint); //move splash screen to back in Mac OS, otherwise it covers startup dialog window
#elif __linux__
    splash->setWindowFlags(Qt::WindowStaysOnBottomHint); //not sure if we need this for Linux, but let's be safe
#endif

    splash->show();
    splash->showMessage(QObject::tr("Starting Intan Technologies Recording Controller v2.06..."), Qt::AlignCenter | Qt::AlignBottom, Qt::black);

    MainWindow mainWin;
    mainWin.show();

    splash->finish(&mainWin);
    delete splash;

    return app.exec();
}
