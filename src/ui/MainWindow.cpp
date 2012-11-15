/**
 * \file        MainWindow.cpp
 * \brief       The MainWindow UI implementation.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        03 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "MainWindow.h"
#include "DialogAbout.h"

// Class Implementation ////////////////////////////////////////////////////////////////////////////

/**
 * Default constructor
 *
 * \param parent The parent of the window, or \c NULL if it is the main window.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionAboutOpenGMS, SIGNAL(triggered()), this, SLOT(showAboutDialog(void)));

}

/**
 * Default destructor
 */
MainWindow::~MainWindow()
{

}

/**
 * Slot for showing the "About" dialog.
 */
void MainWindow::showAboutDialog(void)
{
    DialogAbout dlg(this);
    dlg.exec();
}
