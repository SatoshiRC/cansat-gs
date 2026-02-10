#ifndef SERVO_H
#define SERVO_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFont>
#include <QString>
#include "counter.h"

class servo : public QWidget
{
    Q_OBJECT
public:
    explicit servo(QWidget *parent = nullptr, QString name = QString());

signals:

private:
    QVBoxLayout *layout;
    QLabel *name;
    QPushButton *openButton;
    QPushButton *centerButton;
    QPushButton *closeButton;
    Counter *upper;
    Counter *center;
    Counter *lower;

};

#endif // SERVO_H
