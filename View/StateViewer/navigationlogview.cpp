#include "navigationlogview.h"

NavigationLogView::NavigationLogView(QWidget *parent)
    : QWidget{parent},
    layout(new QGridLayout(this)),
    leftMotorPower(new QLabel(this)),
    rightMotorPower(new QLabel(this)),
    goalDetectionOnCamera(new QLabel(this)),
    goalDetectionOnTof(new QLabel(this)),
    headingDirection(new QLabel(this)),
    goalDirection(new QLabel(this)),
    tofRange(new QLabel(this)),
    positionNorth(new QLabel(this)),
    positionEast(new QLabel(this))
{
    auto title = new QLabel("GNC Log", this);
    QFont titleFont = title->font();
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->setColumnStretch(4,1);
    layout->setRowStretch(10,1);
    layout->addWidget(title,0,0,1,3,Qt::AlignLeft);

    layout->addWidget(new QLabel("Relative Position (N)", this), 1, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 1, 1, Qt::AlignCenter);
    layout->addWidget(positionNorth,1,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[m]", this), 1, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Relative Position (E)", this), 2, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 2, 1, Qt::AlignCenter);
    layout->addWidget(positionEast,2,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[m]", this), 2, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Goal Ditection (Camera)", this), 3, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 3, 1, Qt::AlignCenter);
    layout->addWidget(goalDetectionOnCamera,3,2,Qt::AlignRight);

    layout->addWidget(new QLabel("Goal Ditection (Tof)", this), 4, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 4, 1, Qt::AlignCenter);
    layout->addWidget(goalDetectionOnTof,4,2,Qt::AlignRight);

    layout->addWidget(new QLabel("Tof Range", this), 5, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 5, 1, Qt::AlignCenter);
    layout->addWidget(tofRange,5,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[m]", this), 5, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Heading Direction", this), 6, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 6, 1, Qt::AlignCenter);
    layout->addWidget(headingDirection,6,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[-]", this), 6, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Target Direction", this), 7, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 7, 1, Qt::AlignCenter);
    layout->addWidget(goalDirection,7,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[-]", this), 7, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Left Motro Power", this), 8, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 8, 1, Qt::AlignCenter);
    layout->addWidget(leftMotorPower,8,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[%]", this), 8, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Right Motro Power", this), 9, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 9, 1, Qt::AlignCenter);
    layout->addWidget(rightMotorPower,9,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[%]", this), 9, 3, Qt::AlignLeft);
}

void NavigationLogView::update(int8_t leftMotorPower, int8_t rightMotorPower, int16_t headingDirection, int32_t positionNorth, int32_t positionEast, bool isGoalDetectedByCamera, bool isGoalDetectedByTof, int16_t tofDistance, int16_t goalDirection){
    this->leftMotorPower->setText(QString::number(leftMotorPower));
    this->rightMotorPower->setText(QString::number(rightMotorPower));
    this->positionNorth->setText(QString::number(positionNorth));
    this->positionEast->setText(QString::number(positionEast));
    this->headingDirection->setText(QString::number(headingDirection));
    this->goalDirection->setText(QString::number(goalDirection));
    this->tofRange->setText(QString::number(tofDistance));
    if(isGoalDetectedByCamera){
        this->goalDetectionOnCamera->setText("Detect");
    }else{
        this->goalDetectionOnCamera->setText("-");
    }
    if(isGoalDetectedByTof){
        this->goalDetectionOnCamera->setText("Detect");
    }else{
        this->goalDetectionOnCamera->setText("-");
    }
}
