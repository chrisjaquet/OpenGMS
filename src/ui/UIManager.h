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
#include "MainWindow.h"
#include "../Helpers.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <QObject>

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
        QDockWidget *_fileExplorer;
        MainWindow _mainWindow; ///< The main window that is being managed.

    public:
        // Constructors/Destructors
        UIManager();
        virtual ~UIManager();

        // Getters/Setters
        MainWindow &mainWindow(void);

        // Other Methods
        void setup(void);
        void show(void);
};

// Inline Method Implementations ///////////////////////////////////////////////////////////////////

/**
 * Getter for _mainWindow. Since the main window being managed can only be set at initialisation,
 * there is no setter.
 *
 * \return The mainWindow widget being managed.
 */
inline MainWindow &UIManager::mainWindow(void)
{
    return _mainWindow;
}

/**
 * Shows the main window.
 */
inline void UIManager::show(void)
{
    _mainWindow.show();
}
#endif /* UIMANAGER_H_ */
