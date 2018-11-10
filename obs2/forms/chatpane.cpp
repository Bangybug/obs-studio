#include "chatpane.hpp"
#include "chatpane.moc.hpp"

ChatPane::ChatPane(QWidget* parent) : QWidget(parent), ui(new Ui::ChatPane)
{
	ui->setupUi(this);
}
