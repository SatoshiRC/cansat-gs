#include "altitudeview.h"

AltitudeView::AltitudeView(QWidget *parent)
    : QWidget{parent},
    layout(new QGridLayout(this)),
    altitude(new QLabel(this)),
    pressure(new QLabel(this)),
    temperature(new QLabel(this))
{
    auto title = new QLabel("Altitude", this);
    QFont titleFont = title->font();
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->setColumnStretch(4,1);
    layout->setRowStretch(4,1);
    layout->addWidget(title,0,0,1,3,Qt::AlignLeft);

    layout->addWidget(new QLabel("Altitude", this), 1, 0, Qt::AlignCenter);
    layout->addWidget(new QLabel(" : ", this), 1, 1, Qt::AlignCenter);
    layout->addWidget(altitude,1,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[mm]", this), 1, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Pressure", this), 2, 0, Qt::AlignCenter);
    layout->addWidget(new QLabel(" : ", this), 2, 1, Qt::AlignCenter);
    layout->addWidget(pressure,2,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[Pa]", this), 2, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Temperature", this), 3, 0, Qt::AlignCenter);
    layout->addWidget(new QLabel(" : ", this), 3, 1, Qt::AlignCenter);
    layout->addWidget(temperature,3,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[\u2103]", this), 3, 3, Qt::AlignLeft);
}
