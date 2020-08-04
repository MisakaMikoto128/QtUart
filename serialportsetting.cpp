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

//�����ô��ڲ��ڿ��ô��ںź�����Ͽ��ñ�־
void SerialPortSetting::checkAvailablePorts()
{
    foreach ( const QSerialPortInfo &Info, QSerialPortInfo::availablePorts()) {
         //QSerialPort availablePort;
         //availablePort.setPortName(Info.portName());
         //if (availablePort.open(QIODevice::ReadWrite)) {
            int index = comCB->findText(Info.portName());
            comCB->setItemText(index, Info.portName() + "  avail");
            comCB->setCurrentIndex(index);
            iVec.push_back(index);//���޸������ݵ���������ӵ�������
           // availablePort.close();
         // }
     }
}
//��ѡ�񴮿ںŵ�checkBox���ò����¼����ô���
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


