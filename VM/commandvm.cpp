#include "commandvm.h"

commandVM::commandVM(QObject *parent)
    : QObject{parent}
{
    file = new QFile(this);

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
    (*manager)[command::COMMAND_ID::ServoConfig_stabilizer] = static_cast<command::Base*>(&servoConfigStabilizer);
    (*manager)[command::COMMAND_ID::GPS] = static_cast<command::Base*>(&gps);
    (*manager)[command::COMMAND_ID::IMU] = static_cast<command::Base*>(&imu);

    connect(serial, &QSerialPort::readyRead, this, &commandVM::readyReadSerial);
    connect(serial, &QSerialPort::errorOccurred, this, &commandVM::catchSerialError);
}

bool commandVM::connectSerial(QSerialPortInfo portInfo, qint32 baudrate){
    serial->setBaudRate(baudrate);
    serial->setPort(portInfo);
    bool res = serial->open(QIODeviceBase::ReadWrite);
    if(res == true){
        request.setRequestCommandId(command::COMMAND_ID::ServoConfig_prachuteLeft);
        manager->transmit(command::COMMAND_ID::Request);
        QTimer::singleShot(200,[](){});
        request.setRequestCommandId(command::COMMAND_ID::ServoConfig_prachuteRight);
        manager->transmit(command::COMMAND_ID::Request);
        QTimer::singleShot(200,[](){});
        request.setRequestCommandId(command::COMMAND_ID::ServoConfig_stabilizer);
        manager->transmit(command::COMMAND_ID::Request);
        QTimer::singleShot(200,[](){});
        request.setRequestCommandId(command::COMMAND_ID::Goal);
        manager->transmit(command::COMMAND_ID::Request);
    }
    return res;
}

void commandVM::disconnectSerial(){
    serial->close();
}

void commandVM::readyReadSerial(){
    QByteArray read = serial->readAll();
    if(read.isEmpty()){
        return;
    }
    // Convert QByteArray to std::vector<uint8_t> for safe iteration
    std::vector<uint8_t> data(read.size());
    std::copy(read.begin(), read.end(), data.begin());
    auto id = manager->receive(data.begin(), data.end());

    CommandDataType::ServoConfig servoConfig;
    switch(id){
    case command::COMMAND_ID::ConnectionCheck:
        break;
    case command::COMMAND_ID::SensorStatus:
        break;
    case command::COMMAND_ID::Request:
        break;
    case command::COMMAND_ID::Goal:
        emit goalUpdated(goal.getData().latitude(), goal.getData().longitude());
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
        servoConfig = servoConfigParachuteLeft.getData();
        emit servoParachuteLeftUpdated(servoConfig.openCount(), servoConfig.closeCount(), servoConfig.centerCount(), static_cast<uint8_t>(servoConfig.state()));
        break;
    case command::COMMAND_ID::ServoConfig_prachuteRight:
        servoConfig = servoConfigParachuteRight.getData();
        emit servoParachuteRightUpdated(servoConfig.openCount(), servoConfig.closeCount(), servoConfig.centerCount(), static_cast<uint8_t>(servoConfig.state()));
        break;
    case command::COMMAND_ID::ServoConfig_stabilizer:
        servoConfig = servoConfigStabilizer.getData();
        emit servoStablizerUpdated(servoConfig.openCount(), servoConfig.closeCount(), servoConfig.centerCount(), static_cast<uint8_t>(servoConfig.state()));
        break;
    case command::COMMAND_ID::GPS:
        emit gpsUpdated(gps.getData().latitude(),
                        gps.getData().longitude(),
                        gps.getData().fixStatus());
        break;
    case command::COMMAND_ID::IMU:
        emit accelUpdated(imu.getData().accel());
        emit gyroUpdated(imu.getData().gyro());
        emit magnetUpdated(imu.getData().magnet());
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

void commandVM::exportData(std::filesystem::path &name){
    if(file->openMode() != QIODeviceBase::NotOpen){
        file->close();
    }
    file->setFileName(name);
    file->open(QIODeviceBase::ReadWrite);
    exportData();
}

void commandVM::exportData(){
    if(file->openMode() == QIODeviceBase::NotOpen){
        return;
    }
    QJsonObject rootObj;

    QJsonObject subObj;
    subObj["latitude"] = goal.getData().latitude();
    subObj["longitude"] = goal.getData().longitude();
    rootObj.insert("Goal", subObj);

    subObj = QJsonObject();
    subObj["openCount"] = servoConfigParachuteLeft.getData().openCount();
    subObj["centerCount"] = servoConfigParachuteLeft.getData().centerCount();
    subObj["closeCount"] = servoConfigParachuteLeft.getData().closeCount();
    rootObj.insert("servoConfigParachuteLeft", subObj);

    subObj = QJsonObject();
    subObj["openCount"] = servoConfigParachuteRight.getData().openCount();
    subObj["centerCount"] = servoConfigParachuteRight.getData().centerCount();
    subObj["closeCount"] = servoConfigParachuteRight.getData().closeCount();
    rootObj.insert("servoConfigParachuteRight", subObj);

    subObj = QJsonObject();
    subObj["openCount"] = servoConfigStabilizer.getData().openCount();
    subObj["centerCount"] = servoConfigStabilizer.getData().centerCount();
    subObj["closeCount"] = servoConfigStabilizer.getData().closeCount();
    rootObj.insert("servoConfigStavilizer", subObj);

    file->write(QJsonDocument(rootObj).toJson());

}

void commandVM::loadData(std::filesystem::path &name){
    if(file->openMode() != QIODeviceBase::NotOpen && file->fileName() != QString(name.filename().native())){
        file->close();
        file->setFileName(name);
        file->open(QIODeviceBase::ReadWrite);
    }
    auto raw = file->readAll();
    QJsonObject rootObj = QJsonDocument::fromJson(raw).object();
    QJsonObject subObj;

    subObj = rootObj["Goal"].toObject();
    CommandDataType::Coordinates goal;
    goal.latitude() = subObj["latitude"].toDouble();
    goal.longitude() = subObj["longitude"].toDouble();
    this->goal.setData(goal);

    subObj = rootObj["servoConfigParachuteLeft"].toObject();
    CommandDataType::ServoConfig servoConfig;
    servoConfig.openCount() = subObj["openCout"].toInt(1000);
    servoConfig.centerCount() = subObj["centerCout"].toInt(1000);
    servoConfig.closeCount() = subObj["closeCout"].toInt(1000);
    servoConfig.state() = CommandDataType::ServoState::Center;
    this->servoConfigParachuteLeft.setData(servoConfig);

    subObj = rootObj["servoConfigParachuteRight"].toObject();
    servoConfig.openCount() = subObj["openCout"].toInt(1000);
    servoConfig.centerCount() = subObj["centerCout"].toInt(1000);
    servoConfig.closeCount() = subObj["closeCout"].toInt(1000);
    servoConfig.state() = CommandDataType::ServoState::Center;
    this->servoConfigParachuteRight.setData(servoConfig);

    subObj = rootObj["servoConfigStavilizer"].toObject();
    servoConfig.openCount() = subObj["openCout"].toInt(1000);
    servoConfig.centerCount() = subObj["centerCout"].toInt(1000);
    servoConfig.closeCount() = subObj["closeCout"].toInt(1000);
    servoConfig.state() = CommandDataType::ServoState::Center;
    this->servoConfigStabilizer.setData(servoConfig);
}

void commandVM::setGoal(double latitude, double longitude){
    CommandDataType::Coordinates coord;
    coord.latitude() = latitude;
    coord.longitude() = longitude;
    this->goal.setData(coord);
}

std::array<double, 2> commandVM::requestedCurrentLocation(){
    std::array<double, 2> res = {gps.getData().latitude(), gps.getData().longitude()};
    return res;
}

void commandVM::updateServo(uint8_t servoNum, uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t _state){
    command::COMMAND_ID id;
    CommandDataType::ServoConfig config;
    config.openCount() = _openCount;
    config.closeCount() = _closeCount;
    config.centerCount() = _centerCount;
    config.state() = static_cast<CommandDataType::ServoState>(_state);
    switch(servoNum){
    case 1:
        id = command::COMMAND_ID::ServoConfig_prachuteLeft;
        this->servoConfigParachuteLeft.setData(config);
        break;
    case 2:
        id = command::COMMAND_ID::ServoConfig_prachuteRight;
        this->servoConfigParachuteRight.setData(config);
        break;
    case 3:
        id = command::COMMAND_ID::ServoConfig_stabilizer;
        this->servoConfigStabilizer.setData(config);
        break;
    }
    manager->transmit(id);
}
