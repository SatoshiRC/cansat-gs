#ifndef IMUVIEW_H
#define IMUVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QDoubleValidator>

class ImuView : public QWidget
{
    Q_OBJECT

    QGridLayout *layout;

    QLabel *axLabel;
    QLabel *ayLabel;
    QLabel *azLabel;
    QLabel *gxLabel;
    QLabel *gyLabel;
    QLabel *gzLabel;
    QLabel *mxLabel;
    QLabel *myLabel;
    QLabel *mzLabel;
public:
    explicit ImuView(QWidget *parent = nullptr);

public slots:
    void updateAccel(std::array<float, 3> arg);
    void updateGyro(std::array<float, 3> arg);
    void updateMagnet(std::array<float, 3> arg);

signals:
};

#endif // IMUVIEW_H
