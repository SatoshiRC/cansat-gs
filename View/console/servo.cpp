#include "servo.h"

servo::servo(QWidget *parent, QString name)
    : QWidget{parent},
    layout(new QGridLayout(this)),
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

    layout->addWidget(this->name, 0, 0, 1, 3);
    layout->setColumnStretch(3, 1);
    layout->addWidget(openButton, 1, 0);
    layout->addWidget(centerButton, 1, 1);
    layout->addWidget(closeButton, 1, 2);
    layout->addWidget(upper, 2, 0, 1, 3, Qt::AlignLeft);
    layout->addWidget(center, 3, 0, 1, 3, Qt::AlignLeft);
    layout->addWidget(lower, 4, 0, 1, 3, Qt::AlignLeft);
    layout->setRowStretch(5,1);
}
