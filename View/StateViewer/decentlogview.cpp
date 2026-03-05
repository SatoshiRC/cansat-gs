#include "decentlogview.h"

DecentLogView::DecentLogView(QWidget *parent)
    :QWidget{parent},
    layout(new QGridLayout(this)),
    altitude(new QLabel(this)),
    parachute(new QLabel(this)),
    stabilizer(new QLabel(this)),
    leftMotorPower(new QLabel(this)),
    rightMotorPower(new QLabel(this))
{
    auto title = new QLabel("Decent Log", this);
    QFont titleFont = title->font();
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->setColumnStretch(4,1);
    layout->setRowStretch(6,1);
    layout->addWidget(title,0,0,1,3,Qt::AlignLeft);

    layout->addWidget(new QLabel("Altitude", this), 1, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 1, 1, Qt::AlignCenter);
    layout->addWidget(altitude,1,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[mm]", this), 1, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Parachute", this), 2, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 2, 1, Qt::AlignCenter);
    layout->addWidget(parachute,2,2,Qt::AlignRight);

    layout->addWidget(new QLabel("Stabilizer", this), 3, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 3, 1, Qt::AlignCenter);
    layout->addWidget(stabilizer,3,2,Qt::AlignRight);

    layout->addWidget(new QLabel("Left Motro Power", this), 4, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 4, 1, Qt::AlignCenter);
    layout->addWidget(leftMotorPower,4,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[%]", this), 4, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Right Motro Power", this), 5, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 5, 1, Qt::AlignCenter);
    layout->addWidget(rightMotorPower,5,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[%]", this), 5, 3, Qt::AlignLeft);
}


void DecentLogView::update(qint16 altitude, bool isParachuteReelased, bool isStabilizerDeploied, qint16 leftMotorPower, qint16 rightMotorPower){
    this->altitude->setText(QString::number(altitude));
    if(isParachuteReelased){
        this->parachute->setText("Released");
    }else{
        this->parachute->setText("-");
    }
    if(isStabilizerDeploied){
        this->stabilizer->setText("Deploied");
    }else{
        this->stabilizer->setText("-");
    }
    this->leftMotorPower->setText(QString::number(leftMotorPower));
    this->rightMotorPower->setText(QString::number(rightMotorPower));
}
