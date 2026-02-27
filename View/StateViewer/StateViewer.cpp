#include "StateViewer.hpp"

StateViwer::StateViwer(QWidget *parent)
    :QWidget(parent),
    altitudeView(new AltitudeView(this)),
    gpsStatusView(new GpsStatusView(this)),
    imuView(new ImuView(this)),
    layout(new QGridLayout(this))
{
    layout->setColumnStretch(4,1);
    layout->setRowStretch(2,1);
    layout->addWidget(altitudeView,0,0);
    layout->addWidget(gpsStatusView, 1, 0);

    layout->addWidget(imuView, 0, 1, 2, 1);
}
