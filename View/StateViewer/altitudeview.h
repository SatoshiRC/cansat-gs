#ifndef ALTITUDEVIEW_H
#define ALTITUDEVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class AltitudeView : public QWidget
{
    Q_OBJECT
public:
    explicit AltitudeView(QWidget *parent = nullptr);

signals:

private:
    QGridLayout *layout;
    QLabel *altitude;
    QLabel *pressure;
    QLabel *temperature;

};

#endif // ALTITUDEVIEW_H
