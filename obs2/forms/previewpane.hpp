#ifndef _PREVIEWPANE_H
#define _PREVIEWPANE_H

#include <qwidget.h>
#include <memory>
#include "ui-previewpane.hpp"

class BroadcastWindow;

class PreviewPane : public QWidget
{
	Q_OBJECT
public:
	PreviewPane(QWidget* parent);
private:
	friend class BroadcastWindow;
	std::unique_ptr<Ui::PreviewPane> ui;
};

#endif
