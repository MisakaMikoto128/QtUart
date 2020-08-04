/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionK;
    QAction *actionA;
    QAction *actionFusion;
    QAction *actionWindows;
    QAction *actionMotif;
    QAction *actionCde;
    QAction *actionPlastique;
    QAction *actionCleanlooks;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QComboBox *comboBox_code;
    QWidget *tab_2;
    QLabel *md5label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *filelabel;
    QCommandLinkButton *commandLinkButton;
    QListWidget *dirlistWidget;
    QListWidget *exitlistWidget;
    QWidget *tab_3;
    QDateTimeEdit *dateTimeEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_6;
    QCommandLinkButton *commandLinkButton_7;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_5;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_I;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1307, 854);
        actionK = new QAction(MainWindow);
        actionK->setObjectName(QString::fromUtf8("actionK"));
        actionA = new QAction(MainWindow);
        actionA->setObjectName(QString::fromUtf8("actionA"));
        actionFusion = new QAction(MainWindow);
        actionFusion->setObjectName(QString::fromUtf8("actionFusion"));
        actionWindows = new QAction(MainWindow);
        actionWindows->setObjectName(QString::fromUtf8("actionWindows"));
        actionMotif = new QAction(MainWindow);
        actionMotif->setObjectName(QString::fromUtf8("actionMotif"));
        actionCde = new QAction(MainWindow);
        actionCde->setObjectName(QString::fromUtf8("actionCde"));
        actionPlastique = new QAction(MainWindow);
        actionPlastique->setObjectName(QString::fromUtf8("actionPlastique"));
        actionCleanlooks = new QAction(MainWindow);
        actionCleanlooks->setObjectName(QString::fromUtf8("actionCleanlooks"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(180, 190, 657, 151));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 51, 61));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 240, 71, 61));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 580, 204, 84));
        pushButton->setMinimumSize(QSize(195, 84));
        pushButton->setMaximumSize(QSize(247, 76));
        comboBox_code = new QComboBox(tab);
        comboBox_code->addItem(QString());
        comboBox_code->addItem(QString());
        comboBox_code->addItem(QString());
        comboBox_code->addItem(QString());
        comboBox_code->addItem(QString());
        comboBox_code->addItem(QString());
        comboBox_code->setObjectName(QString::fromUtf8("comboBox_code"));
        comboBox_code->setGeometry(QRect(50, 680, 209, 37));
        comboBox_code->setMinimumSize(QSize(191, 20));
        comboBox_code->setMaximumSize(QSize(230, 37));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        md5label = new QLabel(tab_2);
        md5label->setObjectName(QString::fromUtf8("md5label"));
        md5label->setGeometry(QRect(320, 140, 700, 31));
        md5label->setMinimumSize(QSize(700, 31));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 150, 601, 20));
        label_3->setMinimumSize(QSize(601, 20));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 100, 671, 18));
        label_4->setMinimumSize(QSize(671, 18));
        filelabel = new QLabel(tab_2);
        filelabel->setObjectName(QString::fromUtf8("filelabel"));
        filelabel->setGeometry(QRect(320, 100, 621, 31));
        filelabel->setMinimumSize(QSize(621, 31));
        commandLinkButton = new QCommandLinkButton(tab_2);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(60, 670, 185, 41));
        commandLinkButton->setMinimumSize(QSize(185, 41));
        dirlistWidget = new QListWidget(tab_2);
        dirlistWidget->setObjectName(QString::fromUtf8("dirlistWidget"));
        dirlistWidget->setGeometry(QRect(80, 330, 256, 192));
        exitlistWidget = new QListWidget(tab_2);
        exitlistWidget->setObjectName(QString::fromUtf8("exitlistWidget"));
        exitlistWidget->setGeometry(QRect(420, 350, 256, 192));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        dateTimeEdit = new QDateTimeEdit(tab_3);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(1080, 0, 194, 22));
        verticalLayoutWidget = new QWidget(tab_3);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 80, 271, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        commandLinkButton_2 = new QCommandLinkButton(verticalLayoutWidget);
        commandLinkButton_2->setObjectName(QString::fromUtf8("commandLinkButton_2"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/USB.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_2->setIcon(icon);

        verticalLayout->addWidget(commandLinkButton_2);

        commandLinkButton_6 = new QCommandLinkButton(verticalLayoutWidget);
        commandLinkButton_6->setObjectName(QString::fromUtf8("commandLinkButton_6"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_6->setIcon(icon1);

        verticalLayout->addWidget(commandLinkButton_6);

        commandLinkButton_7 = new QCommandLinkButton(verticalLayoutWidget);
        commandLinkButton_7->setObjectName(QString::fromUtf8("commandLinkButton_7"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/sport.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_7->setIcon(icon2);

        verticalLayout->addWidget(commandLinkButton_7);

        commandLinkButton_3 = new QCommandLinkButton(verticalLayoutWidget);
        commandLinkButton_3->setObjectName(QString::fromUtf8("commandLinkButton_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/face.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_3->setIcon(icon3);

        verticalLayout->addWidget(commandLinkButton_3);

        commandLinkButton_4 = new QCommandLinkButton(verticalLayoutWidget);
        commandLinkButton_4->setObjectName(QString::fromUtf8("commandLinkButton_4"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/bluetooth.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_4->setIcon(icon4);

        verticalLayout->addWidget(commandLinkButton_4);

        commandLinkButton_5 = new QCommandLinkButton(verticalLayoutWidget);
        commandLinkButton_5->setObjectName(QString::fromUtf8("commandLinkButton_5"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton_5->setIcon(icon5);

        verticalLayout->addWidget(commandLinkButton_5);

        tabWidget->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1307, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_I = new QMenu(menu);
        menu_I->setObjectName(QString::fromUtf8("menu_I"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(comboBox_code, pushButton);
        QWidget::setTabOrder(pushButton, textEdit_2);

        menuBar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(menu_I->menuAction());
        menu_I->addAction(actionFusion);
        menu_I->addAction(actionWindows);
        menu_I->addAction(actionMotif);
        menu_I->addAction(actionCde);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionK->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        actionA->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        actionFusion->setText(QCoreApplication::translate("MainWindow", "Fusion", nullptr));
        actionWindows->setText(QCoreApplication::translate("MainWindow", "Windows", nullptr));
        actionMotif->setText(QCoreApplication::translate("MainWindow", "Macintosh", nullptr));
        actionCde->setText(QCoreApplication::translate("MainWindow", "Windowsvista", nullptr));
        actionPlastique->setText(QCoreApplication::translate("MainWindow", "Plastique", nullptr));
        actionCleanlooks->setText(QCoreApplication::translate("MainWindow", "Cleanlooks", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\223\210\345\270\214\345\200\274", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Compare", nullptr));
        comboBox_code->setItemText(0, QCoreApplication::translate("MainWindow", "MD5", nullptr));
        comboBox_code->setItemText(1, QCoreApplication::translate("MainWindow", "SHA1", nullptr));
        comboBox_code->setItemText(2, QCoreApplication::translate("MainWindow", "SHA224", nullptr));
        comboBox_code->setItemText(3, QCoreApplication::translate("MainWindow", "SHA256", nullptr));
        comboBox_code->setItemText(4, QCoreApplication::translate("MainWindow", "SHA384", nullptr));
        comboBox_code->setItemText(5, QCoreApplication::translate("MainWindow", "SHA512", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\345\223\210\345\270\214\345\212\240\345\257\206DEMO", nullptr));
        md5label->setText(QCoreApplication::translate("MainWindow", "md5", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "MD5:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "File:", nullptr));
        filelabel->setText(QCoreApplication::translate("MainWindow", "file", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200MD5\345\255\230\346\224\276\346\226\207\344\273\266\345\244\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\223\210\345\270\214\346\226\207\344\273\266\346\220\234\347\264\242", nullptr));
        commandLinkButton_2->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        commandLinkButton_6->setText(QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\346\243\200\346\265\213DEMO", nullptr));
        commandLinkButton_7->setText(QCoreApplication::translate("MainWindow", "\345\237\272\344\272\216\351\242\234\350\211\262\347\232\204\350\277\220\345\212\250\350\277\275\350\270\252DEMO", nullptr));
        commandLinkButton_3->setText(QCoreApplication::translate("MainWindow", "OpenCV\344\272\272\350\204\270\350\257\206\345\210\253DEMO", nullptr));
        commandLinkButton_4->setText(QCoreApplication::translate("MainWindow", "\350\223\235\347\211\231\345\212\251\346\211\213", nullptr));
        commandLinkButton_5->setText(QCoreApplication::translate("MainWindow", "CommandLinkButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256(&S)", nullptr));
        menu_I->setTitle(QCoreApplication::translate("MainWindow", "\347\225\214\351\235\242\351\243\216\346\240\274(&I)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
