#include "StateViewer.hpp"

StateViwer::StateViwer(QWidget *parent)
    :QWidget(parent),
    layout(new QGridLayout(this)),
    altitudeView(new AltitudeView(this))
{
    layout->setColumnStretch(1,1);
    layout->setRowStretch(1,1);
    layout->addWidget(altitudeView,0,0);
}
