/**
 * \file        DockWidgetFileExplorer.h
 * \brief       The File Explorer dock widget.
 * \author      Chris Jaquet (chrisjaquet@gmail.com)
 * \date        05 Nov 2012
 * \version     0.1
 * \note        Copyright (c) 2012 Chris Jaquet
 **************************************************************************************************/
#ifndef DOCKWIDGETFILEEXPLORER_H_
#define DOCKWIDGETFILEEXPLORER_H_

// Local Headers ///////////////////////////////////////////////////////////////////////////////////
#include "ui_DockWidgetFileExplorer.h"

// Global Headers //////////////////////////////////////////////////////////////////////////////////
#include <QDockWidget>

// Class Definition ////////////////////////////////////////////////////////////////////////////////

/**
 * \class DockWidgetFileExplorer
 * \brief   A file-explorer dock-widget for browsing in OpenGMS, opening files internally and
 *          externally and changing the current working path.
 */
class DockWidgetFileExplorer : public QDockWidget
{
    Q_OBJECT

    private:
        Ui::DockWidgetFileExplorer _dockwidget;
        QFileSystemModel *_wDirModel;

    public:
        // Constructors/Destructors
        DockWidgetFileExplorer(QWidget *parent = 0, QString workingDir = QString(""));
        virtual ~DockWidgetFileExplorer();
};

#endif /* DOCKWIDGETFILEEXPLORER_H_ */
