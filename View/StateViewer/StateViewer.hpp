#ifndef STATE_VIEWER_HPP
#define STATE_VIEWER_HPP

#include <QWidget>
#include <QGridLayout>
#include "altitudeview.h"

class StateViwer : public QWidget{
    Q_OBJECT
public:
    StateViwer(QWidget *parent = nullptr);

    AltitudeView *altitudeView;
private:
    QGridLayout *layout;
};

#endif //STAT_EVIEWER_HPP
