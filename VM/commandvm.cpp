#include "commandvm.h"

commandVM::commandVM(QObject *parent)
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
    auto id = manager.receive(read.begin(), read.end());
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
    manager.transmit(command::COMMAND_ID::Mode);
}
