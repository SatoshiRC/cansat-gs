#include "logging.h"
#include <QDateTime>

Logging::Logging(QObject *parent)
    : QObject{parent},
    logFile(new QFile(this))
{
    QString filename = "~/";
    filename += QDateTime().toString("dd_hh-mm-ss") + "aaa.csv";
    logFile->setFileName(filename);
    logFile->open(QIODevice::WriteOnly);
}

void Logging::push(QString& str){
    logFile->write((char*)str.data(), str.size());
}

void Logging::pushDecentlog(qint16 altitude, bool isParachuteReelased, bool isStabilizerDeploied, qint16 leftMotorPower, qint16 rightMotorPower){
    QString str;
    str.append(QString::number(QDateTime().toMSecsSinceEpoch()));
    str.append(",");

    str.append(QString::number(altitude));
    str.append(",");

    if(isParachuteReelased){
        str.append("1");
    }else{
        str.append("0");
    }
    str.append(",");

    if(isStabilizerDeploied){
        str.append("1");
    }else{
        str.append("0");
    }
    str.append(",");

    str.append(QString::number(leftMotorPower));
    str.append(",");

    str.append(QString::number(rightMotorPower));
    str.append(",");


    str.append(",");

    str.append(",");

    str.append(",");

    str.append(",");

    str.append(",");

    str.append(",");

    str.append("\n");
    logFile->write((char*)str.data(), str.size());
}

void Logging::pushNavigationlog(int8_t leftMotorPower, int8_t rightMotorPower, int16_t headingDirection, int32_t positionNorth, int32_t positionEast, bool isGoalDetectedByCamera, bool isGoalDetectedByTof, int16_t tofDistance, int16_t goalDirection){
    QString str;
    str.append(QString::number(QDateTime().toMSecsSinceEpoch()));
    str.append(",");


    str.append(",");

    str.append(",");

    str.append(",");

    str.append(QString::number(leftMotorPower));
    str.append(",");

    str.append(QString::number(rightMotorPower));
    str.append(",");

    //TODO:impliment
    str.append(QString::number(positionNorth));
    str.append(",");

    str.append(QString::number(positionEast));
    str.append(",");

    str.append(QString::number(headingDirection));
    str.append(",");

    str.append(QString::number(goalDirection));
    str.append(",");

    str.append(QString::number(tofDistance));
    str.append(",");

    if(isGoalDetectedByCamera){
        str.append("1");
    }else{
        str.append("0");
    }
    str.append(",");

    if(isGoalDetectedByTof){
        str.append("1");
    }else{
        str.append("0");
    }
    str.append("\n");
    logFile->write((char*)str.data(), str.size());
}
