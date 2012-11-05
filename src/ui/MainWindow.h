/**
 * \file        MainWindow.h
 * \brief       The MainWindow UI implementation.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        03 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "ui_MainWindow.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <QtGui/QMainWindow>

// Class Implementation ////////////////////////////////////////////////////////////////////////////

/**
 * \class MainWindow
 * \brief The main window class implementation.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow ui;

    public:
        // Constructors/Destructors
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    public slots:
        void showAboutDialog(void);

};

#endif // MAINWINDOW_H_
