/**
 * \file        UIManager.h
 * \brief       Manages the UI for the application.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        03 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
#ifndef UIMANAGER_H_
#define UIMANAGER_H_

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include <qobject.h>

// Global Headers //////////////////////////////////////////////////////////////////////////////////

// Class Definition ////////////////////////////////////////////////////////////////////////////////

/**
 * \class   UIManager
 * \brief   Manages the main window and all the dockable windows of the application, thus keeping
 *          the UI in the correct state at all times.
 */
class UIManager : public QObject
{
    Q_OBJECT

    private:
        QWidget *parent; ///< The parent window that is being managed.

    public:
        // Constructors/Destructors
        UIManager(QWidget *parent = 0);
        virtual ~UIManager();

        // Getters/Setters
        Const
};

#endif /* UIMANAGER_H_ */
