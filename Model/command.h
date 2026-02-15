#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include <QSerialPort>
#include "cansat_command/Inc/CommandManager.h"

class Command : public QObject, public command::CommandManager{
    Q_OBJECT
    QSerialPort *serialPort;
public:
    Command() = default;
    Command(QObject *parent, QSerialPort *serialPort);
    void transmit(const command::COMMAND_ID id);

};

#endif // COMMAND_H
