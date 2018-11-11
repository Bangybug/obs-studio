/********************************************************************************
** Form generated from reading UI file 'uv74broadcastwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2D_BROADCASTWINDOW_H
#define UI_2D_BROADCASTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "chatpane.hpp"
#include "previewpane.hpp"

QT_BEGIN_NAMESPACE

class Ui_BroadcastWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    ChatPane *chatPane;
    PreviewPane *previewPane;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPlay;
    QLabel *labelDuration;
    QPushButton *pushButton;
    QMenuBar *menubar;

    void setupUi(QMainWindow *BroadcastWindow)
    {
        if (BroadcastWindow->objectName().isEmpty())
            BroadcastWindow->setObjectName(QStringLiteral("BroadcastWindow"));
        BroadcastWindow->resize(962, 696);
        BroadcastWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(BroadcastWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        chatPane = new ChatPane(widget);
        chatPane->setObjectName(QStringLiteral("chatPane"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(chatPane->sizePolicy().hasHeightForWidth());
        chatPane->setSizePolicy(sizePolicy3);
        chatPane->setMinimumSize(QSize(400, 0));

        horizontalLayout_2->addWidget(chatPane);

        previewPane = new PreviewPane(widget);
        previewPane->setObjectName(QStringLiteral("previewPane"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(previewPane->sizePolicy().hasHeightForWidth());
        previewPane->setSizePolicy(sizePolicy4);
        previewPane->setMinimumSize(QSize(200, 0));
        previewPane->setMaximumSize(QSize(16777215, 16777215));
        previewPane->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(previewPane);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(widget);

        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy5);
        horizontalWidget->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        btnPlay = new QPushButton(horizontalWidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
        btnPlay->setSizePolicy(sizePolicy6);
        btnPlay->setMinimumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/images/uvplay.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QStringLiteral(":/res/images/uvpause.png"), QSize(), QIcon::Selected, QIcon::On);
        btnPlay->setIcon(icon);
        btnPlay->setIconSize(QSize(32, 32));
        btnPlay->setCheckable(true);
        btnPlay->setChecked(false);
        btnPlay->setFlat(true);

        horizontalLayout->addWidget(btnPlay, 0, Qt::AlignLeft);

        labelDuration = new QLabel(horizontalWidget);
        labelDuration->setObjectName(QStringLiteral("labelDuration"));
        labelDuration->setEnabled(false);
        sizePolicy.setHeightForWidth(labelDuration->sizePolicy().hasHeightForWidth());
        labelDuration->setSizePolicy(sizePolicy);
        labelDuration->setMinimumSize(QSize(47, 0));

        horizontalLayout->addWidget(labelDuration);

        pushButton = new QPushButton(horizontalWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy6.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy6);
        pushButton->setMinimumSize(QSize(180, 0));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addWidget(horizontalWidget, 0, Qt::AlignBottom);

        BroadcastWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BroadcastWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 962, 21));
        BroadcastWindow->setMenuBar(menubar);

        retranslateUi(BroadcastWindow);

        QMetaObject::connectSlotsByName(BroadcastWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BroadcastWindow)
    {
        BroadcastWindow->setWindowTitle(QApplication::translate("BroadcastWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("BroadcastWindow", "\320\222\320\265\321\211\320\260\320\275\320\270\320\265", Q_NULLPTR));
        btnPlay->setText(QString());
        labelDuration->setText(QApplication::translate("BroadcastWindow", "\320\264\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214: 00:00", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BroadcastWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\262\320\265\320\261\320\270\320\275\320\260\321\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BroadcastWindow: public Ui_BroadcastWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2D_BROADCASTWINDOW_H
