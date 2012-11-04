/**
 * \file        DialogAbout.h
 * \brief       Implementation of the About dialog
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        03 Nov 2012
 * \version     1.0
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
#ifndef DIALOGABOUT_H_
#define DIALOGABOUT_H_

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "ui_DialogAbout.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <QDialog>

// Class Definition ////////////////////////////////////////////////////////////////////////////////

/**
 * \class DialogAbout
 * \brief The About containing useful information about the application.
 */
class DialogAbout : public QDialog
{
    Q_OBJECT

    private:
        Ui::DialogAbout dialog;

    public:
        DialogAbout(QWidget *parent = 0);
        virtual ~DialogAbout();
};

#endif /* DIALOGABOUT_H_ */
