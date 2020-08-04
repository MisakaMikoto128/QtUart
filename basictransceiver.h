#ifndef BASICTRANSCEIVER_H
#define BASICTRANSCEIVER_H

#include <QMainWindow>
#include "ui_basictransceiver.h"
#include <QString>
#include <QSet>
class QTimer;
class SerialPortSetting;
class QSerialPort;
class QPushButton;

class BasicTransceiver : public QMainWindow, public Ui::BasicTransceiver
{
    Q_OBJECT

public:
    explicit BasicTransceiver(QWidget *parent = 0);

    ~BasicTransceiver();

    void StringToHex(QString str, QByteArray &senddata);

    char ConvertHexChar(char ch);

    void startAutoSend(QPushButton *sendButton);

    void setConnections();

    void writeHex(QTextEdit *textEdit);

    void writeChr(QTextEdit *textEdit);

    void resetCnt();

protected:
    void dragEnterEvent(QDragEnterEvent *event);

    void dropEvent(QDropEvent *event);

private slots:
    void checkAutoSendCB();

    void on_cleanButton_clicked();

    void on_receiveTextBrowser_textChanged();

    void setBaudRate();

    void setParity();

    void setDataBits();

    void setStopBits();

    void setFlowCtrl();

    void on_connectButton_toggled(bool checked);

    void setComLabel();

    void setBaudLabel();

    void writeToBuf();

    void enabledSendButton();

    void disabledSendButton();

    void enabledAutoSend();

    void disabledAutoButton();

    void resetAutoSendCB();

    void readMyCom();

    void checkAvailablePorts();

    void on_checkAPButton_clicked();

    void checkPort();

    void on_resetCntButton_clicked();

    void on_exitButton_clicked();

    bool saveAs();

    void open();

    //void about();

private:
    bool loadFile(const QString &fileName);

    bool readFile(const QString &fileName);

    bool saveFile(const QString &fileName);

    bool writeFile(const QString &fileName);

    QTimer *Timer_AS;//�Զ����Ͷ�ʱ��
    QTimer *Timer_UPDATE;
    QTimer *Timer_CP;//��ʱ��⴮���Ƿ����
    SerialPortSetting *SPSetting;
    QSerialPort *mySerialPort;
    QSet<QString> portSet;
    QVector<int> iVec;
    QString senderFlag;
    QString readData;
    bool trashFlag = false;
    bool portIsOpen = false;
    int BaudCnt = 0;
    int ParityCnt = 0;
    int DataBitsCnt = 0;
    int StopBitsCnt = 0;
    int FlowCtrlCnt = 0;


};

#endif // BASICTRANSCEIVER_H
