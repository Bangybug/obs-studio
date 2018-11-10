#include "previewpane.hpp"
#include "previewpane.moc.hpp"

PreviewPane::PreviewPane(QWidget* parent) : QWidget(parent), ui(new Ui::PreviewPane)
{
	ui->setupUi(this);
}
