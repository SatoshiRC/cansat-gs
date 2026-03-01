#ifndef SERVO_H
#define SERVO_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>
#include <QString>
#include "counter.h"

class servo : public QWidget
{
    Q_OBJECT
public:
    explicit servo(QWidget *parent = nullptr, QString name = QString(), uint8_t id = 0);

public slots:
    void update(uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t _state);

signals:
    void updated(uint8_t servoNum, uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t _state);

private slots:
    void openCountUpdated(int16_t value);
    void closeCountUpdated(int16_t value);
    void centerCountUpdated(int16_t value);
    void onOpenClicked();
    void onCloseClicked();
    void onCenterClicked();

private:
    QGridLayout *layout;
    QLabel *name;
    QPushButton *openButton;
    QPushButton *centerButton;
    QPushButton *closeButton;
    Counter *upper;
    Counter *center;
    Counter *lower;

    uint8_t id;

    uint16_t _openCount = 800;
    uint16_t _closeCount = 800;
    uint16_t _centerCount = 800;
};

#endif // SERVO_H
