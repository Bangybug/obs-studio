/********************************************************************************
** Form generated from reading UI file 'uv74chatpane.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_2D_CHATPANE_H
#define UI_2D_CHATPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatPane
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *commentBrowser;
    QHBoxLayout *horizontalLayout;
    QLineEdit *myComment;
    QPushButton *sendComment;

    void setupUi(QWidget *ChatPane)
    {
        if (ChatPane->objectName().isEmpty())
            ChatPane->setObjectName(QStringLiteral("ChatPane"));
        ChatPane->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(ChatPane);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        commentBrowser = new QTextBrowser(ChatPane);
        commentBrowser->setObjectName(QStringLiteral("commentBrowser"));

        verticalLayout->addWidget(commentBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        myComment = new QLineEdit(ChatPane);
        myComment->setObjectName(QStringLiteral("myComment"));

        horizontalLayout->addWidget(myComment);

        sendComment = new QPushButton(ChatPane);
        sendComment->setObjectName(QStringLiteral("sendComment"));

        horizontalLayout->addWidget(sendComment);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ChatPane);

        QMetaObject::connectSlotsByName(ChatPane);
    } // setupUi

    void retranslateUi(QWidget *ChatPane)
    {
        ChatPane->setWindowTitle(QApplication::translate("ChatPane", "Form", Q_NULLPTR));
        myComment->setPlaceholderText(QString());
        sendComment->setText(QApplication::translate("ChatPane", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatPane: public Ui_ChatPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_2D_CHATPANE_H
