/********************************************************************************
** Form generated from reading UI file 'uv74previewpane.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2D_PREVIEWPANE_H
#define UI_2D_PREVIEWPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewPane
{
public:
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *PreviewPane)
    {
        if (PreviewPane->objectName().isEmpty())
            PreviewPane->setObjectName(QStringLiteral("PreviewPane"));
        PreviewPane->resize(453, 497);
        graphicsView = new QGraphicsView(PreviewPane);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 256, 192));
        verticalLayoutWidget = new QWidget(PreviewPane);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 220, 421, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        retranslateUi(PreviewPane);

        QMetaObject::connectSlotsByName(PreviewPane);
    } // setupUi

    void retranslateUi(QWidget *PreviewPane)
    {
        PreviewPane->setWindowTitle(QApplication::translate("PreviewPane", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("PreviewPane", "\320\222\321\205\320\276\320\264 (Aux1)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PreviewPane: public Ui_PreviewPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2D_PREVIEWPANE_H
