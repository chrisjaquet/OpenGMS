#include "MainWindow.h"
#include "DialogAbout.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.actionAbout, SIGNAL(activated()), this, SLOT(showAboutDialog(void)));

}

MainWindow::~MainWindow()
{

}

void MainWindow::showAboutDialog(void)
{
    DialogAbout *dlg = new DialogAbout(this);
    dlg->show();
}
