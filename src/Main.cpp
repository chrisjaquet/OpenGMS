/**
 * \file    Main.cpp
 * \brief   Contains the program entry point implementation.
 * \author  Chris Jaquet (chrisjaquet@gmail.com)
 * \date    19 Apr 2012
 * \version 0.1
 * \note    Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "Main.h"
#include "ui/MainWindow.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <QtGui>
#include <QApplication>

/**
 * Program entry point
 *
 * \param argc  The argument count
 * \param argv  The list of arguments passed by the operating system
 *
 * \return An error value. 0 is success.
 */
int main(int argc, char **argv)
{
    printf("[main] Starting...\n");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int retval = a.exec();
    printf("[main] Done (Return Value: %d)\n", retval);

    return retval;
}
