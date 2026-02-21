#include "gpsstatusview.h"

GpsStatusView::GpsStatusView(QWidget *parent)
    : QWidget{parent}
    , layout(new QGridLayout(this))
    ,longitude(new QLabel(this))
    ,latitude(new QLabel(this))
    ,fixStatus(new QLabel(this))
{
    auto title = new QLabel("GPS", this);
    QFont titleFont = title->font();
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->setColumnStretch(4,1);
    layout->setRowStretch(4,1);
    layout->addWidget(title,0,0,1,3,Qt::AlignLeft);

    layout->addWidget(new QLabel("Latitude", this), 1, 0, Qt::AlignCenter);
    layout->addWidget(new QLabel(" : ", this), 1, 1, Qt::AlignCenter);
    layout->addWidget(latitude,1,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[\u00b0]", this), 1, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Longitude", this), 2, 0, Qt::AlignCenter);
    layout->addWidget(new QLabel(" : ", this), 2, 1, Qt::AlignCenter);
    layout->addWidget(longitude,2,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[\u00b0]", this), 2, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Fix", this), 3, 0, Qt::AlignCenter);
    layout->addWidget(new QLabel(" : ", this), 3, 1, Qt::AlignCenter);
    layout->addWidget(fixStatus,3,2, 1, 2, Qt::AlignRight);
}


void GpsStatusView::update(double latitude, double longitude, qint8 fix){
    this->latitude->setText(QString::number(latitude, 'f', 6));
    this->longitude->setText(QString::number(longitude, 'f', 6));
    this->fixStatus->setText(QString::number(fix));
}
