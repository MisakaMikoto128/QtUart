#include "serialportsetting.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

SerialPortSetting::SerialPortSetting(QWidget *parent)
:	QDialog(parent)
{
    setupUi(this);
    setFixedSize(220, 319);
    checkAPButton->setIcon(QIcon(":/images/finger_up.png"));
    emit checkAvailablePorts();
}

//检测可用串口并在可用串口号后面加上可用标志
void SerialPortSetting::checkAvailablePorts()
{
    foreach ( const QSerialPortInfo &Info, QSerialPortInfo::availablePorts()) {
         //QSerialPort availablePort;
         //availablePort.setPortName(Info.portName());
         //if (availablePort.open(QIODevice::ReadWrite)) {
            int index = comCB->findText(Info.portName());
            comCB->setItemText(index, Info.portName() + "  avail");
            comCB->setCurrentIndex(index);
            iVec.push_back(index);//将修改了内容的项索引添加到容器中
           // availablePort.close();
         // }
     }
}
//将选择串口号的checkBox重置并重新检测可用串口
void SerialPortSetting::on_checkAPButton_clicked()
{
    if (!iVec.isEmpty()) {
        for (int i = 0; i != iVec.size(); ++i) {
            QString tempStr;
            comCB->setItemText(iVec[i], QString("COM") +
                                                            tempStr.setNum(iVec[i] + 1));
        }
        comCB->setCurrentIndex(0);
        iVec.clear();
    }
    emit checkAvailablePorts();
    static bool flag = true;
    if (flag) {
        checkAPButton->setIcon(QIcon(":/images/finger_up.png"));
        flag = false;
    } else {
        checkAPButton->setIcon(QIcon(":/images/finger_right.png"));
        flag = true;
    }
}


