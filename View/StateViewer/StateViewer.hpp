#ifndef STATE_VIEWER_HPP
#define STATE_VIEWER_HPP

#include <QWidget>
#include <QGridLayout>
#include "altitudeview.h"
#include "gpsstatusview.h"
#include "imuview.h"
#include "decentlogview.h"
#include "navigationlogview.h"

class StateViwer : public QWidget{
    Q_OBJECT
public:
    StateViwer(QWidget *parent = nullptr);

    AltitudeView *altitudeView;
    GpsStatusView *gpsStatusView;
    ImuView *imuView;
    DecentLogView *decentLogView;
    NavigationLogView *navigationLogView;
private:
    QGridLayout *layout;
};

#endif //STAT_EVIEWER_HPP
