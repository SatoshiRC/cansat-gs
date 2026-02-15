#ifndef COMMANDVM_H
#define COMMANDVM_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "Model/command.h"

class commandVM : public QObject
{
    Q_OBJECT

    Command manager;
    command::ConnectionCheck connectionCheck;
    command::SensorStatus sensorStatus;
    command::Request request;
    command::Goal goal;
    command::Altitude altitude;
    command::Mode mode;
    command::AbsoluteNavigation absoluteNavigation;
    command::RelativeNavigation relativeNavigation;
    command::ServoConfig_prachuteLeft servoConfigParachuteLeft;
    command::ServoConfig_prachuteRight servoConfigParachuteRight;
    command::ServoConfig_stabilizer servoConfigStavilizer;

    QSerialPort *serial;
public:
    explicit commandVM(QObject *parent = nullptr);

public slots:
    void connectSerial(QSerialPortInfo portInfo, qint32 baudrate);
    void disconnectSerial();
    void readyReadSerial();
    void catchSerialError(QSerialPort::SerialPortError error);

    void setMode(qint16 mode);

signals:
    void disconnected();

    void altitudeUpdated(qint16 altitude, float pressure, float temperature);
    void modeUpdated(qint16 mode);
};

#endif // COMMANDVM_H
