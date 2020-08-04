/********************************************************************************
** Form generated from reading UI file 'serialportsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTSETTING_H
#define UI_SERIALPORTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SerialPortSetting
{
public:
    QGroupBox *SPSGB;
    QComboBox *baudCB;
    QComboBox *comCB;
    QComboBox *parityCB;
    QLabel *COMLabel;
    QLabel *StopBitsLabel;
    QLabel *ParityLabel;
    QLabel *DataBitsLabel;
    QComboBox *dataBitsCB;
    QLabel *BaudLabel;
    QComboBox *stopBitsCB;
    QLabel *FlowCtrlLabel;
    QComboBox *flowCtrlCB;
    QPushButton *checkAPButton;

    void setupUi(QDialog *SerialPortSetting)
    {
        if (SerialPortSetting->objectName().isEmpty())
            SerialPortSetting->setObjectName(QStringLiteral("SerialPortSetting"));
        SerialPortSetting->resize(220, 319);
        SPSGB = new QGroupBox(SerialPortSetting);
        SPSGB->setObjectName(QStringLiteral("SPSGB"));
        SPSGB->setGeometry(QRect(10, 10, 201, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        SPSGB->setFont(font);
        baudCB = new QComboBox(SPSGB);
        baudCB->setObjectName(QStringLiteral("baudCB"));
        baudCB->setGeometry(QRect(78, 70, 111, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        baudCB->setFont(font1);
        comCB = new QComboBox(SPSGB);
        comCB->setObjectName(QStringLiteral("comCB"));
        comCB->setGeometry(QRect(78, 30, 111, 22));
        parityCB = new QComboBox(SPSGB);
        parityCB->setObjectName(QStringLiteral("parityCB"));
        parityCB->setGeometry(QRect(78, 110, 111, 22));
        COMLabel = new QLabel(SPSGB);
        COMLabel->setObjectName(QStringLiteral("COMLabel"));
        COMLabel->setGeometry(QRect(10, 30, 54, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        COMLabel->setFont(font2);
        StopBitsLabel = new QLabel(SPSGB);
        StopBitsLabel->setObjectName(QStringLiteral("StopBitsLabel"));
        StopBitsLabel->setGeometry(QRect(10, 190, 54, 21));
        StopBitsLabel->setFont(font2);
        ParityLabel = new QLabel(SPSGB);
        ParityLabel->setObjectName(QStringLiteral("ParityLabel"));
        ParityLabel->setGeometry(QRect(10, 110, 54, 21));
        ParityLabel->setFont(font2);
        DataBitsLabel = new QLabel(SPSGB);
        DataBitsLabel->setObjectName(QStringLiteral("DataBitsLabel"));
        DataBitsLabel->setGeometry(QRect(10, 150, 54, 21));
        DataBitsLabel->setFont(font2);
        dataBitsCB = new QComboBox(SPSGB);
        dataBitsCB->setObjectName(QStringLiteral("dataBitsCB"));
        dataBitsCB->setGeometry(QRect(78, 150, 111, 22));
        BaudLabel = new QLabel(SPSGB);
        BaudLabel->setObjectName(QStringLiteral("BaudLabel"));
        BaudLabel->setGeometry(QRect(10, 70, 54, 21));
        BaudLabel->setFont(font2);
        stopBitsCB = new QComboBox(SPSGB);
        stopBitsCB->setObjectName(QStringLiteral("stopBitsCB"));
        stopBitsCB->setGeometry(QRect(78, 190, 111, 22));
        FlowCtrlLabel = new QLabel(SPSGB);
        FlowCtrlLabel->setObjectName(QStringLiteral("FlowCtrlLabel"));
        FlowCtrlLabel->setGeometry(QRect(10, 230, 54, 21));
        FlowCtrlLabel->setFont(font2);
        flowCtrlCB = new QComboBox(SPSGB);
        flowCtrlCB->setObjectName(QStringLiteral("flowCtrlCB"));
        flowCtrlCB->setGeometry(QRect(78, 230, 111, 22));
        checkAPButton = new QPushButton(SPSGB);
        checkAPButton->setObjectName(QStringLiteral("checkAPButton"));
        checkAPButton->setGeometry(QRect(78, 270, 111, 22));

        retranslateUi(SerialPortSetting);

        QMetaObject::connectSlotsByName(SerialPortSetting);
    } // setupUi

    void retranslateUi(QDialog *SerialPortSetting)
    {
        SerialPortSetting->setWindowTitle(QApplication::translate("SerialPortSetting", "Dialog", 0));
        SPSGB->setTitle(QApplication::translate("SerialPortSetting", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        baudCB->clear();
        baudCB->insertItems(0, QStringList()
         << QApplication::translate("SerialPortSetting", "115200", 0)
         << QApplication::translate("SerialPortSetting", "57600", 0)
         << QApplication::translate("SerialPortSetting", "38400", 0)
         << QApplication::translate("SerialPortSetting", "19200", 0)
         << QApplication::translate("SerialPortSetting", "9600", 0)
         << QApplication::translate("SerialPortSetting", "4800", 0)
         << QApplication::translate("SerialPortSetting", "2400", 0)
         << QApplication::translate("SerialPortSetting", "1200", 0)
        );
        comCB->clear();
        comCB->insertItems(0, QStringList()
         << QApplication::translate("SerialPortSetting", "COM1", 0)
         << QApplication::translate("SerialPortSetting", "COM2", 0)
         << QApplication::translate("SerialPortSetting", "COM3", 0)
         << QApplication::translate("SerialPortSetting", "COM4", 0)
         << QApplication::translate("SerialPortSetting", "COM5", 0)
         << QApplication::translate("SerialPortSetting", "COM6", 0)
         << QApplication::translate("SerialPortSetting", "COM7", 0)
         << QApplication::translate("SerialPortSetting", "COM8", 0)
         << QApplication::translate("SerialPortSetting", "COM9", 0)
         << QApplication::translate("SerialPortSetting", "COM10", 0)
         << QApplication::translate("SerialPortSetting", "COM11", 0)
         << QApplication::translate("SerialPortSetting", "COM12", 0)
         << QApplication::translate("SerialPortSetting", "COM13", 0)
         << QApplication::translate("SerialPortSetting", "COM14", 0)
         << QApplication::translate("SerialPortSetting", "COM15", 0)
         << QApplication::translate("SerialPortSetting", "COM16", 0)
         << QApplication::translate("SerialPortSetting", "COM17", 0)
         << QApplication::translate("SerialPortSetting", "COM18", 0)
         << QApplication::translate("SerialPortSetting", "COM19", 0)
         << QApplication::translate("SerialPortSetting", "COM20", 0)
        );
        parityCB->clear();
        parityCB->insertItems(0, QStringList()
         << QApplication::translate("SerialPortSetting", "\346\227\240\346\240\241\351\252\214", 0)
         << QApplication::translate("SerialPortSetting", "\345\245\207\346\240\241\351\252\214", 0)
         << QApplication::translate("SerialPortSetting", "\345\201\266\346\240\241\351\252\214", 0)
        );
        COMLabel->setText(QApplication::translate("SerialPortSetting", "\347\253\257\345\217\243\345\217\267", 0));
        StopBitsLabel->setText(QApplication::translate("SerialPortSetting", "\345\201\234\346\255\242\344\275\215", 0));
        ParityLabel->setText(QApplication::translate("SerialPortSetting", "\346\240\241\351\252\214\344\275\215", 0));
        DataBitsLabel->setText(QApplication::translate("SerialPortSetting", "\346\225\260\346\215\256\344\275\215", 0));
        dataBitsCB->clear();
        dataBitsCB->insertItems(0, QStringList()
         << QApplication::translate("SerialPortSetting", "8", 0)
         << QApplication::translate("SerialPortSetting", "7", 0)
         << QApplication::translate("SerialPortSetting", "6", 0)
         << QApplication::translate("SerialPortSetting", "5", 0)
        );
        BaudLabel->setText(QApplication::translate("SerialPortSetting", "\346\263\242\347\211\271\347\216\207", 0));
        stopBitsCB->clear();
        stopBitsCB->insertItems(0, QStringList()
         << QApplication::translate("SerialPortSetting", "1", 0)
         << QApplication::translate("SerialPortSetting", "1.5", 0)
         << QApplication::translate("SerialPortSetting", "2", 0)
        );
        FlowCtrlLabel->setText(QApplication::translate("SerialPortSetting", "\346\265\201\346\216\247\345\210\266", 0));
        flowCtrlCB->clear();
        flowCtrlCB->insertItems(0, QStringList()
         << QApplication::translate("SerialPortSetting", "off", 0)
         << QApplication::translate("SerialPortSetting", "hardware", 0)
         << QApplication::translate("SerialPortSetting", "xonxoff", 0)
        );
        checkAPButton->setText(QApplication::translate("SerialPortSetting", "\346\243\200\346\265\213\345\217\257\347\224\250\344\270\262\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialPortSetting: public Ui_SerialPortSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTSETTING_H
