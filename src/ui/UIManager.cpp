/**
 * \file        UIManager.cpp
 * \brief       Manages the UI for the application.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        03 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "UIManager.h"
#include "DockWidgetFileExplorer.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////

// Class Implementation ////////////////////////////////////////////////////////////////////////////

/**
 * The default constructor. This constructor will create the main window and set up its default
 * state.
 */
UIManager::UIManager()
{
    // We will now populate the main window and all its menus and the status bar.

    // File Explorer
    _fileExplorer = new DockWidgetFileExplorer(&_mainWindow);
    _mainWindow.addDockWidget(Qt::LeftDockWidgetArea, _fileExplorer);

    // Console Dock

}

/**
 * The default destructor
 */
UIManager::~UIManager()
{
    if(_fileExplorer)
    {
        delete _fileExplorer;
    }
}

