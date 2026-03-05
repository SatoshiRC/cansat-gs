#ifndef NAVIGATIONLOGVIEW_H
#define NAVIGATIONLOGVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class NavigationLogView : public QWidget
{
    Q_OBJECT

    QGridLayout *layout;

    QLabel *leftMotorPower;
    QLabel *rightMotorPower;
    QLabel *goalDetectionOnCamera;
    QLabel *goalDetectionOnTof;
    QLabel *headingDirection;
    QLabel *goalDirection;
    QLabel *tofRange;
    QLabel *positionNorth;
    QLabel *positionEast;

public:
    explicit NavigationLogView(QWidget *parent = nullptr);

public slots:
    void update(int8_t leftMotorPower, int8_t rightMotorPower, int16_t headingDirection, int32_t positionNorth, int32_t positionEast, bool isGoalDetectedByCamera, bool isGoalDetectedByTof, int16_t tofDistance, int16_t goalDirection);
signals:

};

#endif // NAVIGATIONLOGVIEW_H
