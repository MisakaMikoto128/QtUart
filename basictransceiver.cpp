#include "basictransceiver.h"
#include "serialportsetting.h"
#include "ui_basictransceiver.h"
#include "ui_serialportsetting.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QStatusBar>
#include <QPushButton>
#include <QByteArray>
#include <QDataStream>
#include <QTimer>
#include <QRegExp>
#include <QRegExpValidator>
#include <QFile>
#include <QFileDialog>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QAction>

namespace Ui {
class BasicTransceiver;
}

BasicTransceiver::BasicTransceiver(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    //setFixedSize(1074, 627);
    receiveTextBrowser->setAcceptDrops(false);//ȱʡ����£�QTextEdit������������Ӧ�ó�����ק�����ı������ļ�����ʾ������
    senderTextEdit_1->setAcceptDrops(false);

    setAcceptDrops(true);//ͨ����ֹQTextEdit�ؼ���drop�¼������������ڵõ�drop�¼�

    connectButton->setIcon(QIcon(":/images/open.png"));
    cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
    checkAPButton->setIcon(QIcon(":/images/find.png"));
    resetCntButton->setIcon(QIcon(":/images/to_zero.png"));
    exitButton->setIcon(QIcon(":/images/exit.png"));
    actionWrite_data->setIcon(QIcon(":/images/write.png"));
    actionRead_data->setIcon(QIcon(":/images/read.png"));
    actionChoose_file->setIcon(QIcon(":/images/select_file.png"));
    exitAction->setIcon(QIcon(":/images/exit.png"));
    actionAbout->setIcon(QIcon(":/images/about.png"));
    sendButton_1->setIcon(QIcon(":/images/send.png"));

    setConnections();
    emit checkAvailablePorts();

    Timer_CP = new QTimer(this);
    Timer_UPDATE = new QTimer(this);
    connect(Timer_UPDATE, SIGNAL(timeout()), this, SLOT(repaint()));
    Timer_UPDATE->start(2000);
    Timer_AS = new QTimer(this);


    setWindowIcon(QIcon(":/images/paper-plane.png"));
}

BasicTransceiver::~BasicTransceiver()
{

}

void BasicTransceiver::checkAutoSendCB()
{
    QObject *signalSender = sender();
    if ( signalSender->objectName() == "autoSendCB_1")
    {
        if (autoSendCB_1->isChecked())
        {
            intervalSB_1->setEnabled(false);

            startAutoSend(sendButton_1);
        } else if (!autoSendCB_1->isChecked()) {
            Timer_AS->stop();
            Timer_AS->disconnect();
            intervalSB_1->setEnabled(true);

            enabledSendButton();
        }
    }

 }

//���������������
void BasicTransceiver::on_cleanButton_clicked()
{
    if (trashFlag == true) {
        receiveTextBrowser->clear();
        cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
    }
}

void BasicTransceiver::on_receiveTextBrowser_textChanged()
{
    QString tempStr = receiveTextBrowser->toPlainText();
    if (!tempStr.isEmpty()) {
        trashFlag = true;
        if (autoClean->isChecked()){
            if (tempStr.size() >6200 ){
                receiveTextBrowser->clear();
                cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
            }
        } else {
        cleanButton->setIcon(QIcon(":/images/clean.png"));
        }
    } else {
        trashFlag = false;
        cleanButton->setIcon(QIcon(":/images/empty_bin.png"));
    }
}


void BasicTransceiver::setBaudRate()
{
    if (portIsOpen) {
        if (BAUDCB->currentText() == "115200")
            mySerialPort->setBaudRate(QSerialPort::Baud115200);
        else if (BAUDCB->currentText() == "9600")
            mySerialPort->setBaudRate(QSerialPort::Baud9600);
        else if (BAUDCB->currentText() == "1200")
            mySerialPort->setBaudRate(QSerialPort::Baud1200);
        else if (BAUDCB->currentText() == "2400")
            mySerialPort->setBaudRate(QSerialPort::Baud2400);
        else if (BAUDCB->currentText() == "4800")
            mySerialPort->setBaudRate(QSerialPort::Baud4800);
        else if (BAUDCB->currentText() == "19200")
            mySerialPort->setBaudRate(QSerialPort::Baud19200);
        else if (BAUDCB->currentText() == "38400")
            mySerialPort->setBaudRate(QSerialPort::Baud38400);
        else if (BAUDCB->currentText() == "57600")
            mySerialPort->setBaudRate(QSerialPort::Baud57600);
        emit setBaudLabel();
        if (BaudCnt) {
            statusBar()->showMessage("BaudRate set successfully", 2000);
        }
        ++BaudCnt;
    }
}

void BasicTransceiver::setParity()
{
    if (portIsOpen) {
        if (ParityCB->currentText() == QString::fromLocal8Bit("��У��"))
            mySerialPort->setParity(QSerialPort::NoParity);
        else if (ParityCB->currentText() == QString::fromLocal8Bit("��У��"))
            mySerialPort->setParity(QSerialPort::OddParity);
        else if (ParityCB->currentText() == QString::fromLocal8Bit("żУ��"))
            mySerialPort->setParity(QSerialPort::EvenParity);
        if (ParityCnt) {
            statusBar()->showMessage("Parity set successfully", 2000);
        }
        ++ParityCnt;
    }
}

void BasicTransceiver::setDataBits()
{
    if (portIsOpen) {
        if (DataBitsCB->currentText() == "8")
            mySerialPort->setDataBits(QSerialPort::Data8);
        else if (DataBitsCB->currentText() == "7")
            mySerialPort->setDataBits(QSerialPort::Data7);
        else if (DataBitsCB->currentText() == "6")
            mySerialPort->setDataBits(QSerialPort::Data6);
        else if (DataBitsCB->currentText() == "5")
            mySerialPort->setDataBits(QSerialPort::Data5);
        if (DataBitsCnt) {
             statusBar()->showMessage("DataBits set successfully", 2000);
        }
        ++DataBitsCnt;
    }
}

void BasicTransceiver::setStopBits()
{
    if (portIsOpen) {
        if (StopBitsCB->currentText() == "1")
            mySerialPort->setStopBits(QSerialPort::OneStop);
        else if (StopBitsCB->currentText() == "1.5")
            mySerialPort->setStopBits(QSerialPort::OneAndHalfStop);
        else if (StopBitsCB->currentText() == "2")
            mySerialPort->setStopBits(QSerialPort::TwoStop);
        if (StopBitsCnt) {
            statusBar()->showMessage("StopBits set successfully", 2000);
        }
        ++StopBitsCnt;
    }
}

void BasicTransceiver::setFlowCtrl()
{
    if (portIsOpen) {
        if (FlowCtrlCB->currentText() == "off")
            mySerialPort->setFlowControl(QSerialPort::NoFlowControl);
        else if (FlowCtrlCB->currentText() == "hardware")
            mySerialPort->setFlowControl(QSerialPort::HardwareControl);
        else if (FlowCtrlCB->currentText() == "xonxoff")
            mySerialPort->setFlowControl(QSerialPort::SoftwareControl);
        if (FlowCtrlCnt) {
            statusBar()->showMessage("FlowCtrl set successfully", 2000);
        }
        ++FlowCtrlCnt;
    }
}

void BasicTransceiver::resetCnt()
{
    BaudCnt = 0;
    ParityCnt = 0;
    DataBitsCnt = 0;
    StopBitsCnt = 0;
    FlowCtrlCnt = 0;
}

//�򿪺͹رմ���
void BasicTransceiver::on_connectButton_toggled(bool checked)
{
    if (checked == true) {
        mySerialPort = new QSerialPort(this);
        QString tempStr = COMCB->currentText();
        tempStr.remove("  avail", Qt::CaseSensitive);
        mySerialPort->setPortName(tempStr);
        if (mySerialPort->open(QIODevice::ReadWrite)) {
                portIsOpen = true;
                emit setBaudRate();
                emit setParity();
                emit setDataBits();
                emit setStopBits();
                emit setFlowCtrl();
                statusBar()->showMessage(mySerialPort->portName() + " is opened", 2000);
                emit setComLabel();
                emit enabledSendButton();
                emit enabledAutoSend();
                COMCB->setEnabled(false);
                connect(Timer_CP, SIGNAL(timeout()), this, SLOT(checkPort()));
                Timer_CP->start(1000);
                connect(mySerialPort, SIGNAL(readyRead()), this, SLOT(readMyCom()));
                connectButton->setText(QString::fromLocal8Bit("�ر�����"));
                connectButton->setIcon(QIcon(":/images/close.png"));
            } else {
                QMessageBox::warning(this,
                                                       QString::fromLocal8Bit("���ڴ�ʧ��"),
                                                       QString::fromLocal8Bit("���ڲ����ڻ򱾴���"
                                                                                             "�Ѿ���ռ�ã������ԣ�"),
                                                       QMessageBox::Cancel);
                connectButton->setChecked(false);
                return;
           }
    } else  if (checked == false) {
            if (Timer_AS->isActive()) {
                Timer_AS->stop();
                emit resetAutoSendCB();
            }
            if (Timer_CP->isActive()) Timer_CP->stop();
            Timer_CP->disconnect();
            if (mySerialPort->isOpen()) mySerialPort->close();
            emit disabledSendButton();
            emit disabledAutoButton();
            emit setComLabel();
            emit setBaudLabel();
            resetCnt();
            COMCB->setEnabled(true);
            connectButton->setText(QString::fromLocal8Bit("������"));
            connectButton->setIcon(QIcon(":/images/open.png"));
            portIsOpen = false;
    }
}

//������ʾ���ںźͲ����ʵ�Label
void BasicTransceiver::setComLabel()
{
    if (mySerialPort->isOpen()) {
        comLabel->setText(QString(mySerialPort->portName()));
    } else if (!mySerialPort->isOpen()) {
        comLabel->setText(QString::fromLocal8Bit("COM��#"));
    }
}

void BasicTransceiver::setBaudLabel()
{
    if (mySerialPort->isOpen()) {
        int i_baud = mySerialPort->baudRate();
        QString s_baud;
        baudLabel->setText(s_baud.setNum(i_baud));
    } else if (!mySerialPort->isOpen()) {
        baudLabel->setText(QString::fromLocal8Bit("BAUD��#"));
    }
}

void BasicTransceiver::writeToBuf()
{
    QObject *signalSender = sender();
    if (signalSender->objectName() == "sendButton_1") {
        if (hexRB_1->isChecked()) {
            writeHex(senderTextEdit_1);
        } else {
            writeChr(senderTextEdit_1);
        }
    }
}

void BasicTransceiver::writeHex(QTextEdit *textEdit)
{
    QString dataStr = textEdit->toPlainText();
    //������͵����ݸ���Ϊ�����ģ�����ǰ������䵥���ַ�ǰ���һ���ַ�0
    if (dataStr.length() % 2){
        dataStr.insert(dataStr.length()-1, '0');
    }
    QByteArray sendData;
    StringToHex(dataStr, sendData);
    mySerialPort->write(sendData);
    RxLCD->display(RxLCD->value() + sendData.size());
}

void BasicTransceiver::writeChr(QTextEdit *textEdit)
{
    QByteArray sendData = textEdit->toPlainText().toUtf8();
    if (!sendData.isEmpty() && !sendData.isNull()) {
        mySerialPort->write(sendData);
    }
    RxLCD->display(RxLCD->value() + sendData.size());
}

void BasicTransceiver::StringToHex(QString str, QByteArray &senddata) //�ַ���ת��Ϊʮ����������0-F
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len / 2);
    char lstr,hstr;
    for (int i = 0; i < len; ) {
        hstr = str[i].toLatin1();
        if (hstr == ' ') {
            ++i;
            continue;
        }
        ++i;
        if (i  >= len) break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if ((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16 + lowhexdata;
        ++i;
        senddata[hexdatalen] = (char)hexdata;
        ++hexdatalen;
    }
    senddata.resize(hexdatalen);
}

char BasicTransceiver::ConvertHexChar(char ch)
{
    if ((ch >= '0') && (ch <= '9'))
        return ch - 0x30;
    else if ((ch >= 'A') && (ch <= 'F'))
        return ch - 'A' + 10;
    else if ((ch >= 'a') && (ch <= 'f'))
        return ch - 'a' + 10;
    else return ch -  ch;
}

void BasicTransceiver::enabledSendButton()
{
    sendButton_1->setEnabled(true);

}

void BasicTransceiver::disabledSendButton()
{
    sendButton_1->setEnabled(false);

}

void BasicTransceiver::startAutoSend(QPushButton *sendButton)
{
    connect(Timer_AS, SIGNAL(timeout()), sendButton, SIGNAL(clicked()));
    QString interval;
    if (sendButton->objectName() == "sendButton_1") {
        disabledSendButton();
        Timer_AS->start(intervalSB_1->value());
        statusBar()->showMessage(QString::fromLocal8Bit("ÿ ") + interval.setNum(intervalSB_1->value())+ QString::fromLocal8Bit("ms �Զ�����һ��") , 2000);
    }
}

void BasicTransceiver::setConnections()
{
    connect(autoSendCB_1, SIGNAL(stateChanged(int)), this, SLOT(checkAutoSendCB()));


    connect(actionWrite_data, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(actionRead_data, SIGNAL(triggered()), this, SLOT(open()));
    connect(actionChoose_file, SIGNAL(triggered()), this, SLOT(open()));
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(actionAbout, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(sendButton_1, SIGNAL(clicked()), this, SLOT(writeToBuf()));

    connect(BAUDCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setBaudRate()));
    connect(ParityCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setParity()));
    connect(DataBitsCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setDataBits()));
    connect(StopBitsCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setStopBits()));
    connect(FlowCtrlCB, SIGNAL(currentIndexChanged(int)), this, SLOT(setFlowCtrl()));
}

void BasicTransceiver::enabledAutoSend()
{
    autoSendCB_1->setEnabled(true);

}

void BasicTransceiver::disabledAutoButton()
{
    autoSendCB_1->setEnabled(false);

}



void BasicTransceiver::resetAutoSendCB()
{
    autoSendCB_1->setChecked(false);

}

void BasicTransceiver::readMyCom()
{
    QByteArray temp = mySerialPort->readAll();
    QString buf;

    if (actionAlways_show->isChecked()) {
        if(!temp.isEmpty()){
                if(chrReceive->isChecked()){
                    buf = temp;
                }else if(hexReceive->isChecked()){
                    for(int i = 0; i < temp.count(); i++){
                        QString s;
                        s.sprintf("0x%02x, ", (unsigned char)temp.at(i));
                        buf += s;
                    }
                }
            receiveTextBrowser->setText(receiveTextBrowser->document()->toPlainText() + buf);
            receiveTextBrowser->moveCursor(QTextCursor::End);


            //ui->statusBar->showMessage(tr("�ɹ���ȡ%1�ֽ�����").arg(temp.size()));
        }
    }
    TxLCD->display(TxLCD->value() + temp.size());
}

//�����ô��ڲ��ڿ��ô��ںź�����Ͽ��ñ�־
void BasicTransceiver::checkAvailablePorts()
{//�Ҳ������ڴ����ǲ�����뵽foreach�ڲ��ġ��������ڲ�һ������
    foreach ( const QSerialPortInfo &Info, QSerialPortInfo::availablePorts()) {
        QSerialPort availablePort;
        availablePort.setPortName(Info.portName());
        if (availablePort.open(QIODevice::ReadWrite)) {
            int index = COMCB->findText(Info.portName());
            COMCB->setItemText(index, Info.portName() + "  avail");
            COMCB->setCurrentIndex(index);
            iVec.push_back(index);//���޸������ݵ���������ӵ�������
            checkAPButton->setIcon(QIcon(":/images/find_it.png"));
            availablePort.close();
            }
    }
    if (iVec.size() == 0) {checkAPButton->setIcon(QIcon(":/images/find.png"));}
    QString availPortCnt;
    statusBar()->showMessage(availPortCnt.setNum(iVec.size()) + " available ports", 2000);
}
//��ѡ�񴮿ںŵ�checkBox���ò����¼����ô���
void BasicTransceiver::on_checkAPButton_clicked()
{
    if (!iVec.isEmpty()) {
        for (int i = 0; i != iVec.size(); ++i) {
            QString tempStr;
            COMCB->setItemText(iVec[i], QString("COM") +
                                                            tempStr.setNum(iVec[i]));
        }
        COMCB->setCurrentIndex(0);
        iVec.clear();
    }
    emit checkAvailablePorts();
}

void BasicTransceiver::checkPort()
{
    QSet<QString> portSet;
    foreach ( const QSerialPortInfo &Info, QSerialPortInfo::availablePorts()) {
        portSet.insert(Info.portName());
    }
    if (portSet.find(mySerialPort->portName()) == portSet.end()) {
        QMessageBox::warning(this,
                                               QString::fromLocal8Bit("Application error"),
                                               QString::fromLocal8Bit("Fail with the following error : \n���ڷ���ʧ��\n\nPort:%1")
                                               .arg(mySerialPort->portName()),
                                               QMessageBox::Close);
        emit on_connectButton_toggled(false);
    }
}

void BasicTransceiver::on_resetCntButton_clicked()
{
    RxLCD->display(0);
    TxLCD->display(0);
}

void BasicTransceiver::on_exitButton_clicked()
{
    qApp->quit();
}
//���Ϊ
bool BasicTransceiver::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Data"), ".",
                                                    tr("Text File (*.txt)"));
    if (fileName.isEmpty()) {
        return false;
    }
    return saveFile(fileName);
}

bool BasicTransceiver::saveFile(const QString &fileName)
{
    if (!writeFile(fileName)) {
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }
    statusBar()->showMessage(tr("Data saved"), 2000);
    return true;
}

bool BasicTransceiver::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Save Data"),
                                                       tr("Cannot write file %1 : \n%2")
                                                       .arg(file.fileName())
                                                       .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << receiveTextBrowser->toPlainText();
    return true;
}


void BasicTransceiver::open()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                            tr("Choose Text File"), ".",
                                                            tr("Text File (*.txt)"));
    if (!fileName.isEmpty()) {
        loadFile(fileName);
    }
}

bool BasicTransceiver::loadFile(const QString &fileName)
{
    if (!readFile(fileName)) {
            statusBar()->showMessage(tr("Loading canceled"), 2000);
            return false;
        }
        statusBar()->showMessage(tr("Data loaded"), 2000);
        return true;
}

bool BasicTransceiver::readFile(const QString &fileName)
{
    QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, tr("Read failed"),
                                                     tr("Cannot read file %1 : \n%2.")
                                                     .arg(file.fileName())
                                                     .arg(file.errorString()));
            return false;
        }
        QTextStream in(&file);
        QObject *signalSender = sender();
        if (signalSender->objectName() == "actionRead_data"){
            receiveTextBrowser->setText(in.readAll());
        } else if (signalSender->objectName() == "actionChoose_file") {
            senderTextEdit_1->setText(in.readAll());
        }
        return true;
}

void BasicTransceiver::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
            event->acceptProposedAction();
}

void BasicTransceiver::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
        if (urls.isEmpty())
            return;
        QString fileName = urls.first().toLocalFile();
        if (fileName.isEmpty()){
            return;
        }
        loadFile(fileName);
}
/*
void BasicTransceiver::about()
{
    QMessageBox::about(this, tr("About Basic Transceiver"),
                                 tr("<h2>Basic Transceiver 0.9</h2>"
                                    "<p>Copyright &copy; 2016 DrK Inc.</p>"
                                    "<p>Text Editor is a small application "
                                    "that can be used to edit some text files</p>"));
}
*/

