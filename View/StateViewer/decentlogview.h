#ifndef DECENTLOGVIEW_H
#define DECENTLOGVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class DecentLogView : public QWidget
{
    Q_OBJECT
public:
    DecentLogView(QWidget *parent = nullptr);

public slots:
    void update(qint16 altitude, bool isParachuteReelased, bool isStabilizerDeploied, qint16 leftMotorPower, qint16 rightMotorPower);

private:
    QGridLayout *layout;
    QLabel *altitude;
    QLabel *parachute;
    QLabel *stabilizer;
    QLabel *leftMotorPower;
    QLabel *rightMotorPower;
};

#endif // DECENTLOGVIEW_H
