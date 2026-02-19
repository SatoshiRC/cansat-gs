#ifndef GPSSTATUSVIEW_H
#define GPSSTATUSVIEW_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class GpsStatusView : public QWidget
{
    Q_OBJECT
public:
    explicit GpsStatusView(QWidget *parent = nullptr);

public slots:
    void update(double latitude, double longitude, qint8 fix);
signals:

private:
    QGridLayout *layout;
    QLabel *longitude;
    QLabel *latitude;
    QLabel *fixStatus;
};

#endif // GPSSTATUSVIEW_H
