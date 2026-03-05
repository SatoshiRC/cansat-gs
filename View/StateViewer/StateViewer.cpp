#include "StateViewer.hpp"

StateViwer::StateViwer(QWidget *parent)
    :QWidget(parent),
    altitudeView(new AltitudeView(this)),
    gpsStatusView(new GpsStatusView(this)),
    imuView(new ImuView(this)),
    decentLogView(new DecentLogView(this)),
    navigationLogView(new NavigationLogView(this)),
    layout(new QGridLayout(this))
{
    layout->setColumnStretch(4,1);
    layout->setRowStretch(2,1);
    layout->addWidget(altitudeView,0,0);
    layout->addWidget(gpsStatusView, 1, 0);

    layout->addWidget(imuView, 0, 1, 2, 1);

    layout->addWidget(decentLogView, 0, 2, 2, 1);

    layout->addWidget(navigationLogView, 0, 3, 2, 1);
}
