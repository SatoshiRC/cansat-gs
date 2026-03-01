#ifndef COMMANDVM_H
#define COMMANDVM_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>

#include "Model/command.h"


class commandVM : public QObject
{
    Q_OBJECT

    Command *manager;
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
    command::ServoConfig_stabilizer servoConfigStabilizer;
    command::Gps gps;
    command::Imu imu;

    QSerialPort *serial;
    QFile *file;
public:
    explicit commandVM(QObject *parent = nullptr);

public slots:
    bool connectSerial(QSerialPortInfo portInfo, qint32 baudrate);
    void disconnectSerial();
    void readyReadSerial();
    void catchSerialError(QSerialPort::SerialPortError error);

    void exportData(std::filesystem::path &name);
    void exportData();
    void loadData(std::filesystem::path &name);

    void setMode(qint16 mode);

    void setGoal(double latitude, double longitude);
    std::array<double, 2> requestedCurrentLocation();

    void updateServo(uint8_t servoNum, uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t _state);

signals:
    void disconnected();

    void altitudeUpdated(qint16 altitude, float pressure, float temperature);
    void modeUpdated(qint16 mode);
    void gpsUpdated(double latitude, double longitude, qint16 fixStatus);
    void accelUpdated(std::array<float, 3> arg);
    void gyroUpdated(std::array<float, 3> arg);
    void magnetUpdated(std::array<float, 3> arg);
    void goalUpdated(double latitude, double longitude);

    void servoParachuteLeftUpdated(uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t state);
    void servoParachuteRightUpdated(uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t state);
    void servoStablizerUpdated(uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t state);
};

#endif // COMMANDVM_H
