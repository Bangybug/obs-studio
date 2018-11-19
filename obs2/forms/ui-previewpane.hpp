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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <window-basic-preview.hpp>

QT_BEGIN_NAMESPACE

class Ui_PreviewPane
{
public:
    QVBoxLayout *verticalLayout_2;
    OBSBasicPreview *widget;
    QVBoxLayout *verticalLayout;
    QWidget *hVolumeWidgets;
    QVBoxLayout *hVolControlLayout;

    void setupUi(QWidget *PreviewPane)
    {
        if (PreviewPane->objectName().isEmpty())
            PreviewPane->setObjectName(QStringLiteral("PreviewPane"));
        PreviewPane->resize(453, 497);
        verticalLayout_2 = new QVBoxLayout(PreviewPane);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget = new OBSBasicPreview(PreviewPane);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout_2->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        hVolumeWidgets = new QWidget(PreviewPane);
        hVolumeWidgets->setObjectName(QStringLiteral("hVolumeWidgets"));
        hVolumeWidgets->setGeometry(QRect(0, 0, 81, 32));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hVolumeWidgets->sizePolicy().hasHeightForWidth());
        hVolumeWidgets->setSizePolicy(sizePolicy);
        hVolControlLayout = new QVBoxLayout(hVolumeWidgets);
        hVolControlLayout->setSpacing(0);
        hVolControlLayout->setObjectName(QStringLiteral("hVolControlLayout"));
        hVolControlLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(hVolumeWidgets);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(PreviewPane);

        QMetaObject::connectSlotsByName(PreviewPane);
    } // setupUi

    void retranslateUi(QWidget *PreviewPane)
    {
        PreviewPane->setWindowTitle(QApplication::translate("PreviewPane", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PreviewPane: public Ui_PreviewPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2D_PREVIEWPANE_H
