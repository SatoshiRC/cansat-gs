#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <QWidget>
#include <QMap>
#include <QGridLayout>
#include "servo.h"
#include "setgoalview.h"

class Console : public QWidget{
    Q_OBJECT
public:
    Console(QWidget *parent = nullptr);
    void addMode(uint8_t id, QWidget *child);

    servo *ParachuteLeft;
    servo *ParachuteRight;
    servo *Stabilizer;

    SetGoalView *setGoal;
public slots:
    void modeChange(uint8_t id){};

private:
    struct _Console{
        uint8_t id;
        QWidget *child;
    };
    QMap<uint8_t, QWidget*> childs;
    uint8_t activeKey;

    QGridLayout *layout;

};
#endif //CONSOLE_HPP
