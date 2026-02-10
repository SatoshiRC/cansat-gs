#include "servo.h"

servo::servo(QWidget *parent, QString name)
    : QWidget{parent},
    layout(new QVBoxLayout(this)),
    name(new QLabel("Servo : "+name, this)),
    openButton(new QPushButton("Open",this)),
    centerButton(new QPushButton("Center", this)),
    closeButton(new QPushButton("Close", this)),
    upper(new Counter(this, 800, 2400, "Open")),
    center(new Counter(this, 800, 2400, "Center")),
    lower(new Counter(this, 800, 2400, "Close"))
{
    auto f = this->font();
    f.setPointSize(10);
    upper->setFont(f);
    center->setFont(f);
    lower->setFont(f);
    openButton->setFont(f);
    centerButton->setFont(f);
    closeButton->setFont(f);

    layout->addWidget(this->name);
    auto buttons = new QHBoxLayout(this);
    layout->addLayout(buttons);
    buttons->addWidget(openButton);
    buttons->addWidget(centerButton);
    buttons->addWidget(closeButton);
    layout->addWidget(upper);
    layout->addWidget(center);
    layout->addWidget(lower);
    layout->addStretch();
}
