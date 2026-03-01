#include "servo.h"

servo::servo(QWidget *parent, QString name, uint8_t id)
    : QWidget{parent},
    layout(new QGridLayout(this)),
    name(new QLabel("Servo : "+name, this)),
    openButton(new QPushButton("Open",this)),
    centerButton(new QPushButton("Center", this)),
    closeButton(new QPushButton("Close", this)),
    upper(new Counter(this, 800, 2400, "Open")),
    center(new Counter(this, 800, 2400, "Center")),
    lower(new Counter(this, 800, 2400, "Close")),
    id(id)
{
    auto f = this->font();
    f.setPointSize(10);
    upper->setFont(f);
    center->setFont(f);
    lower->setFont(f);
    openButton->setFont(f);
    centerButton->setFont(f);
    closeButton->setFont(f);

    layout->addWidget(this->name, 0, 0, 1, 3);
    layout->setColumnStretch(3, 1);
    layout->addWidget(openButton, 1, 0);
    layout->addWidget(centerButton, 1, 1);
    layout->addWidget(closeButton, 1, 2);
    layout->addWidget(upper, 2, 0, 1, 3, Qt::AlignLeft);
    layout->addWidget(center, 3, 0, 1, 3, Qt::AlignLeft);
    layout->addWidget(lower, 4, 0, 1, 3, Qt::AlignLeft);
    layout->setRowStretch(5,1);

    connect(upper, &Counter::onChangeValue, this, &servo::openCountUpdated);
    connect(center, &Counter::onChangeValue, this, &servo::centerCountUpdated);
    connect(lower, &Counter::onChangeValue, this, &servo::closeCountUpdated);
    connect(openButton, &QPushButton::clicked, this, &servo::onOpenClicked);
    connect(centerButton, &QPushButton::clicked, this, &servo::onCenterClicked);
    connect(closeButton, &QPushButton::clicked, this, &servo::onCloseClicked);
}

void servo::update(uint16_t _openCount, uint16_t _closeCount, uint16_t _centerCount, uint8_t state){
    upper->setValue(_openCount);
    center->setValue(_centerCount);
    lower->setValue(_closeCount);
}

void servo::openCountUpdated(int16_t value){
    emit updated(id, upper->getValue(), lower->getValue(), center->getValue(), 1);
}
void servo::centerCountUpdated(int16_t value){
    emit updated(id, upper->getValue(), lower->getValue(), center->getValue(), 2);
}
void servo::closeCountUpdated(int16_t value){
    emit updated(id, upper->getValue(), lower->getValue(), center->getValue(), 3);
}
void servo::onOpenClicked(){
    emit updated(id, upper->getValue(), lower->getValue(), center->getValue(), 1);
}
void servo::onCenterClicked(){
    emit updated(id, upper->getValue(), lower->getValue(), center->getValue(), 2);
}
void servo::onCloseClicked(){
    emit updated(id, upper->getValue(), lower->getValue(), center->getValue(), 3);
}

