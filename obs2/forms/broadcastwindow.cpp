#include "broadcastwindow.hpp"
#include "broadcastwindow.moc.hpp"

BroadcastWindow::BroadcastWindow(QWidget *parent)
	: QMainWindow(parent),
	ui(new Ui::BroadcastWindow)
{
	setAttribute(Qt::WA_NativeWindow);
	ui->setupUi(this);
}
