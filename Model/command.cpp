#include "command.h"

void command::CommandManager::transmit(const COMMAND_ID id){

}

Command::Command(QObject *parent, QSerialPort *serialPort)
    :QObject(parent),
    serialPort(serialPort)
{

}

void Command::transmit(const command::COMMAND_ID id){
    auto frame = constructTransmitFrame(id);
    serialPort->write((const char*)frame.data(), frame.size());
}
