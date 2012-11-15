/**
 * \file        DockWidgetFileExplorer.cpp
 * \brief       The File Explorer dock widget.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        05 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "DockWidgetFileExplorer.h"
#include "../Logger.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <QDir>

// Class Implementation ////////////////////////////////////////////////////////////////////////////

/**
 * The default constructor which initialises and populates the widget based on the starting
 * directory.
 *
 * \param parent        The parent widget.
 * \param workingDir    The working directory to start in.
 */
DockWidgetFileExplorer::DockWidgetFileExplorer(QWidget *parent, QString workingDir) : QDockWidget(parent)
{
    // Set up the GUI elements first
    _dockwidget.setupUi(this);
    _dockwidget.textEditAddressBar->setMinimumHeight(_dockwidget.lineEditFilter->minimumHeight());
    _dockwidget.textEditAddressBar->setMaximumHeight(_dockwidget.lineEditFilter->maximumHeight());
    _dockwidget.textEditAddressBar->setFixedHeight(_dockwidget.lineEditFilter->height());

    // Populate the treeview with the folder and files
    if(workingDir == "")
    {
        // Select the user's home folder if no folder was provided
        // TODO: Make this configurable in the settings.
        workingDir = QDir::homePath();
    }
    _wDirModel = new QFileSystemModel;
    _wDirModel->setRootPath(workingDir);
    _dockwidget.treeViewFiles->setModel(_wDirModel);
    _dockwidget.treeViewFiles->setRootIndex(_wDirModel->index(workingDir));
    _dockwidget.textEditAddressBar->setPlainText(workingDir);

    // Set up the navigation buttons

}

/**
 * Default destructor
 */
DockWidgetFileExplorer::~DockWidgetFileExplorer()
{
    if(_wDirModel)
    {
        delete _wDirModel;
    }
}

