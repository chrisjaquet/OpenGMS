/**
 * \file        DialogAbout.cpp
 * \brief       Implementation for the About dialog
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        03 Nov 2012
 * \version     1.0
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "DialogAbout.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////

// Class Implementation ////////////////////////////////////////////////////////////////////////////

/**
 * Default constructor
 *
 * \param parent The parent of the widget (typically the main window, since the dialog is modal).
 */
DialogAbout::DialogAbout(QWidget *parent) : QDialog(parent)
{
    dialog.setupUi(this);
}

/**
 * Default destructor
 */
DialogAbout::~DialogAbout()
{
}

