/**
 * \file        DockWidgetConsole.h
 * \brief       The QDockWidget that contains the console for command input.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        03 Nov 2012
 * \version     0.1
 * $Rev: $
 * $Date: $
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
#ifndef DOCKWIDGETCONSOLE_H_
#define DOCKWIDGETCONSOLE_H_

// Local Headers ///////////////////////////////////////////////////////////////////////////////////

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <QDockWidget>

// Class Definition ////////////////////////////////////////////////////////////////////////////////

/**
 * \class DockWidgetConsole
 * \brief The QDockWidget that contains the console for command input.
 */
class DockWidgetConsole : public QDockWidget
{
    Q_OBJECT

    private:

    public:
        // Constructors/Destructors
        DockWidgetConsole(QWidget *parent = 0);
        virtual ~DockWidgetConsole();
};

#endif /* DOCKWIDGETCONSOLE_H_ */
