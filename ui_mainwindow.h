/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QSlider *pSlider;
    QPushButton *prev_pushButton;
    QPushButton *play_pushButton;
    QPushButton *next_pushButton;
    QLabel *curtime_label;
    QLabel *totoltime_label;
    QSlider *volumSlider;
    QPushButton *playbackmodepushButton;
    QPushButton *volsw_pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1477, 739);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pSlider = new QSlider(centralWidget);
        pSlider->setObjectName(QStringLiteral("pSlider"));
        pSlider->setGeometry(QRect(310, 620, 741, 22));
        pSlider->setOrientation(Qt::Horizontal);
        prev_pushButton = new QPushButton(centralWidget);
        prev_pushButton->setObjectName(QStringLiteral("prev_pushButton"));
        prev_pushButton->setGeometry(QRect(10, 600, 50, 50));
        prev_pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border:3px solid red;\n"
"	border-radius:25px;\n"
"	background:url(:/leftbutton.png);\n"
"	background-position: center;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border:3px solid black;\n"
"}"));
        play_pushButton = new QPushButton(centralWidget);
        play_pushButton->setObjectName(QStringLiteral("play_pushButton"));
        play_pushButton->setGeometry(QRect(80, 590, 70, 70));
        play_pushButton->setAutoFillBackground(false);
        play_pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border:3px solid red;\n"
"	border-radius:35px;\n"
"	background:url(:/playbutton.png) no-repeat;\n"
"	background-position: center;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border:3px solid black;\n"
"}"));
        play_pushButton->setIconSize(QSize(80, 60));
        play_pushButton->setAutoExclusive(false);
        next_pushButton = new QPushButton(centralWidget);
        next_pushButton->setObjectName(QStringLiteral("next_pushButton"));
        next_pushButton->setGeometry(QRect(170, 600, 50, 50));
        next_pushButton->setAutoFillBackground(false);
        next_pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border:3px solid red;\n"
"	border-radius:25px;\n"
"	background:url(:/rightbutton.png);\n"
"	background-position: center;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border:3px solid black;\n"
"}"));
        curtime_label = new QLabel(centralWidget);
        curtime_label->setObjectName(QStringLiteral("curtime_label"));
        curtime_label->setGeometry(QRect(250, 620, 51, 18));
        totoltime_label = new QLabel(centralWidget);
        totoltime_label->setObjectName(QStringLiteral("totoltime_label"));
        totoltime_label->setGeometry(QRect(1070, 620, 51, 18));
        volumSlider = new QSlider(centralWidget);
        volumSlider->setObjectName(QStringLiteral("volumSlider"));
        volumSlider->setGeometry(QRect(1170, 620, 160, 21));
        volumSlider->setOrientation(Qt::Horizontal);
        playbackmodepushButton = new QPushButton(centralWidget);
        playbackmodepushButton->setObjectName(QStringLiteral("playbackmodepushButton"));
        playbackmodepushButton->setGeometry(QRect(1340, 613, 31, 31));
        playbackmodepushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border:1px solid white;\n"
"	background-image:url(\":/random.png\") no-repeat;\n"
"	background-position:center;\n"
"}"));
        volsw_pushButton = new QPushButton(centralWidget);
        volsw_pushButton->setObjectName(QStringLiteral("volsw_pushButton"));
        volsw_pushButton->setGeometry(QRect(1130, 615, 31, 31));
        volsw_pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	border:1px solid white;\n"
"	background-image:url(:/VolOn.png) no-repeat;\n"
"	background-position:center;\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1477, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        prev_pushButton->setText(QString());
        play_pushButton->setText(QString());
        next_pushButton->setText(QString());
        curtime_label->setText(QApplication::translate("MainWindow", "--:--", 0));
        totoltime_label->setText(QApplication::translate("MainWindow", "--:--", 0));
        playbackmodepushButton->setText(QString());
        volsw_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
