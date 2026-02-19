#ifndef STATE_VIEWER_HPP
#define STATE_VIEWER_HPP

#include <QWidget>
#include <QGridLayout>
#include "altitudeview.h"
#include "gpsstatusview.h"

class StateViwer : public QWidget{
    Q_OBJECT
public:
    StateViwer(QWidget *parent = nullptr);

    AltitudeView *altitudeView;
    GpsStatusView *gpsStatusView;
private:
    QGridLayout *layout;
};

#endif //STAT_EVIEWER_HPP
