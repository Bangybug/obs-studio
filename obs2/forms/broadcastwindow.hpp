#ifndef _BROADCASTWINDOW_H
#define _BROADCASTWINDOW_H

#include <qmainwindow.h>
#include <memory>
#include "ui-broadcastwindow.hpp"

class BroadcastWindow: public QMainWindow {
	Q_OBJECT
public:
	BroadcastWindow(QWidget *parent);
	virtual ~BroadcastWindow() {}
private:
	std::unique_ptr<Ui::BroadcastWindow> ui;
};

#endif

