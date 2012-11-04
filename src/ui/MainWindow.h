#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_MainWindow.h"

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

#endif // MAINWINDOW_H
