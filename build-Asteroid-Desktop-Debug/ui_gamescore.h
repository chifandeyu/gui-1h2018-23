/********************************************************************************
** Form generated from reading UI file 'gamescore.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCORE_H
#define UI_GAMESCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameScore
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *gameScore)
    {
        if (gameScore->objectName().isEmpty())
            gameScore->setObjectName(QStringLiteral("gameScore"));
        gameScore->resize(400, 300);
        label = new QLabel(gameScore);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 71, 16));
        pushButton = new QPushButton(gameScore);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 270, 75, 23));

        retranslateUi(gameScore);

        QMetaObject::connectSlotsByName(gameScore);
    } // setupUi

    void retranslateUi(QWidget *gameScore)
    {
        gameScore->setWindowTitle(QApplication::translate("gameScore", "Form", nullptr));
        label->setText(QApplication::translate("gameScore", "GAME SCORE ", nullptr));
        pushButton->setText(QApplication::translate("gameScore", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameScore: public Ui_gameScore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCORE_H
