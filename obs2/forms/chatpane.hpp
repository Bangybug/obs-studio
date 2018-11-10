#ifndef _CHATPANE_H
#define _CHATPANE_H

#include <qwidget.h>
#include <memory>
#include "ui-chatpane.hpp"

class ChatPane : public QWidget
{
Q_OBJECT
public:
	ChatPane(QWidget* parent);
private:
	std::unique_ptr<Ui::ChatPane> ui;
};

#endif
