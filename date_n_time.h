#ifndef DATE_N_TIME_H
#define DATE_N_TIME_H

namespace calendar
{
  int to_hijri(int gregorian)
  {
    return gregorian - 576;
  }

  int to_gregorian(int hijri)
  {
    return hijri + 576;
  }
}

/********************************************************************************
** Form generated from reading UI file 'calculatorhU3386.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CALCULATORHU3386_H
#define CALCULATORHU3386_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QPushButton *button_7;
    QPushButton *button_8;
    QPushButton *button_9;
    QPushButton *button_4;
    QPushButton *button_5;
    QPushButton *button_6;
    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_3;
    QPushButton *button_0;
    QPushButton *button_11;
    QPushButton *button_10;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(335, 520);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_3->addWidget(textEdit, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button_7 = new QPushButton(centralwidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));

        gridLayout->addWidget(button_7, 0, 0, 1, 1);

        button_8 = new QPushButton(centralwidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));

        gridLayout->addWidget(button_8, 0, 1, 1, 1);

        button_9 = new QPushButton(centralwidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));

        gridLayout->addWidget(button_9, 0, 2, 1, 1);

        button_4 = new QPushButton(centralwidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));

        gridLayout->addWidget(button_4, 1, 0, 1, 1);

        button_5 = new QPushButton(centralwidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));

        gridLayout->addWidget(button_5, 1, 1, 1, 1);

        button_6 = new QPushButton(centralwidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));

        gridLayout->addWidget(button_6, 1, 2, 1, 1);

        button_1 = new QPushButton(centralwidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));

        gridLayout->addWidget(button_1, 2, 0, 1, 1);

        button_2 = new QPushButton(centralwidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));

        gridLayout->addWidget(button_2, 2, 1, 1, 1);

        button_3 = new QPushButton(centralwidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));

        gridLayout->addWidget(button_3, 2, 2, 1, 1);

        button_0 = new QPushButton(centralwidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));

        gridLayout->addWidget(button_0, 3, 0, 1, 1);

        button_11 = new QPushButton(centralwidget);
        button_11->setObjectName(QString::fromUtf8("button_11"));

        gridLayout->addWidget(button_11, 3, 1, 1, 1);

        button_10 = new QPushButton(centralwidget);
        button_10->setObjectName(QString::fromUtf8("button_10"));

        gridLayout->addWidget(button_10, 3, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 335, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        button_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        button_8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        button_9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        button_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        button_5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        button_6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        button_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        button_2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        button_3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        button_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        button_11->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        button_10->setText(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CALCULATORHU3386_H

#endif//DATE_N_TIME_H
