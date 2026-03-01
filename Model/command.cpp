#include "command.h"
#include <QDebug>

void command::CommandManager::transmit(const COMMAND_ID id){

}

Command::Command(QObject *parent, QSerialPort *serialPort)
    :QObject(parent),
    serialPort(serialPort)
{

}

void Command::transmit(const command::COMMAND_ID id){
    // Check if serial port is valid and command handler is valid
    if(serialPort == nullptr || static_cast<uint8_t>(id) >= static_cast<uint8_t>(command::COMMAND_ID::Last)){
        return;
    }
    if(commandHandlers[static_cast<uint8_t>(id)] == nullptr){
        return;
    }
    uint8_t len = 0;
    constructTransmitFrameToBuffer(id, txBuffer.data(), len);
    // Ensure length doesn't exceed buffer size
    if(len == 0 || len > txBuffer.size()){
        return;
    }
    if(!serialPort->isOpen()){
        return;
    }
    qint64 written = serialPort->write((const char*)txBuffer.data(), len);
    if(written != len){
        qWarning() << "Failed to write complete data to serial port. Expected:" << len << ", Written:" << written;
    }
}
