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
#include "ui/UIManager.h"
#include "Logger.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <QApplication>
#include <QStyleFactory>

// Global Variables ////////////////////////////////////////////////////////////////////////////////

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
    // Welcome message and argument list
    LOGP("Starting...\n");
    LOGP("  Called as \"%s\"\n", argv[0]);
    LOGP("  Argument list: \"");
    for(int i = 1; i < argc; i++)
    {
        LOGPB("%s", argv[i]);
    }
    LOGPB("\"\n");

    // Create the application and UI Manager
    QApplication a(argc, argv);

    UIManager uim;
    uim.show();

    // Start the event loop
    int retval = a.exec();

    LOGP("Exiting with return value: %d\n", retval);
    return retval;
}
