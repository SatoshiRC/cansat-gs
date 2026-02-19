#include "commandvm.h"

commandVM::commandVM(QObject *parent)
    : QObject{parent}
{
    serial =  new QSerialPort(this);
    manager = new Command(this, serial);
    (*manager)[command::COMMAND_ID::ConnectionCheck] = static_cast<command::Base*>(&connectionCheck);
    (*manager)[command::COMMAND_ID::SensorStatus] = static_cast<command::Base*>(&sensorStatus);
    (*manager)[command::COMMAND_ID::Request] = static_cast<command::Base*>(&request);
    (*manager)[command::COMMAND_ID::Goal] = static_cast<command::Base*>(&goal);
    (*manager)[command::COMMAND_ID::Altitude] = static_cast<command::Base*>(&altitude);
    (*manager)[command::COMMAND_ID::Mode] = static_cast<command::Base*>(&mode);
    (*manager)[command::COMMAND_ID::AbsoluteNavigationLog] = static_cast<command::Base*>(&absoluteNavigation);
    (*manager)[command::COMMAND_ID::RelativeNavigationLog] = static_cast<command::Base*>(&relativeNavigation);
    (*manager)[command::COMMAND_ID::ServoConfig_prachuteLeft] = static_cast<command::Base*>(&servoConfigParachuteLeft);
    (*manager)[command::COMMAND_ID::ServoConfig_prachuteRight] = static_cast<command::Base*>(&servoConfigParachuteRight);
    (*manager)[command::COMMAND_ID::ServoConfig_stabilizer] = static_cast<command::Base*>(&servoConfigStavilizer);
    (*manager)[command::COMMAND_ID::GPS] = static_cast<command::Base*>(&gps);

    connect(serial, &QSerialPort::readyRead, this, &commandVM::readyReadSerial);
}

bool commandVM::connectSerial(QSerialPortInfo portInfo, qint32 baudrate){
    serial->setBaudRate(baudrate);
    serial->setPort(portInfo);
    return serial->open(QIODeviceBase::ReadWrite);
}

void commandVM::disconnectSerial(){
    serial->close();
}

void commandVM::readyReadSerial(){
    QByteArray read = serial->readAll();
    auto id = manager->receive(read.begin(), read.end());
    switch(id){
    case command::COMMAND_ID::ConnectionCheck:
        break;
    case command::COMMAND_ID::SensorStatus:
        break;
    case command::COMMAND_ID::Request:
        break;
    case command::COMMAND_ID::Goal:
        break;
    case command::COMMAND_ID::Altitude:
        emit altitudeUpdated(altitude.getData().altitude(),
                            altitude.getData().pressure(),
                            altitude.getData().temperature());
        break;
    case command::COMMAND_ID::Mode:
        emit modeUpdated(mode.getData());
        break;
    case command::COMMAND_ID::AbsoluteNavigationLog:
        break;
    case command::COMMAND_ID::RelativeNavigationLog:
        break;
    case command::COMMAND_ID::ServoConfig_prachuteLeft:
        break;
    case command::COMMAND_ID::ServoConfig_prachuteRight:
        break;
    case command::COMMAND_ID::ServoConfig_stabilizer:
        break;
    case command::COMMAND_ID::GPS:
        emit gpsUpdated(gps.getData().latitude(),
                        gps.getData().longitude(),
                        gps.getData().fixStatus());
        break;
    default:
        break;
    }
}

void commandVM::catchSerialError(QSerialPort::SerialPortError error){
    if(static_cast<qint8>(error)>0){
        disconnectSerial();
        emit disconnected();
    }
}

void commandVM::setMode(qint16 mode){
    this->mode.setData(mode);
    manager->transmit(command::COMMAND_ID::Mode);
}
