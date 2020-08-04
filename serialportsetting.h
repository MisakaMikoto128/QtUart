#ifndef SERIALPORTSETTING_H
#define SERIALPORTSETTING_H
#include <QDialog>
#include <QVector>
#include "ui_serialportsetting.h"

class SerialPortSetting : public QDialog, public Ui::SerialPortSetting
{
    friend class BasicTransceiver;
	Q_OBJECT
public:
	SerialPortSetting(QWidget *parent = nullptr);

private slots:
    void checkAvailablePorts();

    void on_checkAPButton_clicked();

private:
    QVector<int> iVec;
};
#endif
