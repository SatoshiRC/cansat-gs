#ifndef LOGGING_H
#define LOGGING_H

#include <QObject>
#include <QFile>
#include <QString>

class Logging : public QObject
{
    Q_OBJECT
    QFile *logFile;
public:
    explicit Logging(QObject *parent = nullptr);
    void push(QString& str);
    void pushDecentlog(qint16 altitude, bool isParachuteReelased, bool isStabilizerDeploied, qint16 leftMotorPower, qint16 rightMotorPower);
    void pushNavigationlog(int8_t leftMotorPower, int8_t rightMotorPower, int16_t headingDirection, int32_t positionNorth, int32_t positionEast, bool isGoalDetectedByCamera, bool isGoalDetectedByTof, int16_t tofDistance, int16_t goalDirection);

signals:
};

#endif // LOGGING_H
