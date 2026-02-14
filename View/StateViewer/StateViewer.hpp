#ifndef STATE_VIEWER_HPP
#define STATE_VIEWER_HPP

#include <QWidget>
#include <QGridLayout>
#include "altitudeview.h"

class StateViwer : public QWidget{
    Q_OBJECT
public:
    StateViwer(QWidget *parent = nullptr);

private:
    QGridLayout *layout;
    AltitudeView *altitudeView;
};

#endif //STAT_EVIEWER_HPP
