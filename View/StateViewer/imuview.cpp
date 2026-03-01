#include "imuview.h"

ImuView::ImuView(QWidget *parent)
    : QWidget{parent},
    layout(new QGridLayout(this)),
    axLabel(new QLabel(this)),
    ayLabel(new QLabel(this)),
    azLabel(new QLabel(this)),
    gxLabel(new QLabel(this)),
    gyLabel(new QLabel(this)),
    gzLabel(new QLabel(this)),
    mxLabel(new QLabel(this)),
    myLabel(new QLabel(this)),
    mzLabel(new QLabel(this))
{
    auto title = new QLabel("IMU", this);
    QFont titleFont = title->font();
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->setColumnStretch(4,1);
    layout->setRowStretch(4,1);
    layout->addWidget(title,0,0,1,3,Qt::AlignLeft);

    layout->addWidget(new QLabel("Acceleration"), 1, 0, 1, 4, Qt::AlignLeft);
    layout->addWidget(new QLabel("a_x"), 2, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 2, 1, Qt::AlignCenter);
    layout->addWidget(axLabel,2,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[m/s<sup>2</sup>]", this), 2, 3, Qt::AlignLeft);
    layout->addWidget(new QLabel("a_y"), 3, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 3, 1, Qt::AlignCenter);
    layout->addWidget(ayLabel,3,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[m/s<sup>2</sup>]", this), 3, 3, Qt::AlignLeft);
    layout->addWidget(new QLabel("a_z"), 4, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 4, 1, Qt::AlignCenter);
    layout->addWidget(azLabel,4,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[m/s<sup>2</sup>]", this), 4, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Gyro"), 5, 0, 1, 4, Qt::AlignLeft);
    layout->addWidget(new QLabel("g_x"), 6, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 6, 1, Qt::AlignCenter);
    layout->addWidget(gxLabel,6,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[rad/s<sup>2</sup>]", this), 6, 3, Qt::AlignLeft);
    layout->addWidget(new QLabel("g_y"), 7, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 7, 1, Qt::AlignCenter);
    layout->addWidget(gyLabel,7,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[rad/s<sup>2</sup>]", this), 7, 3, Qt::AlignLeft);
    layout->addWidget(new QLabel("g_z"), 8, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 8, 1, Qt::AlignCenter);
    layout->addWidget(gzLabel,8,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[rad/s<sup>2</sup>]", this), 8, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Magnet"), 9, 0, 1, 4, Qt::AlignLeft);
    layout->addWidget(new QLabel("m_x"), 10, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 10, 1, Qt::AlignCenter);
    layout->addWidget(mxLabel,10,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[uT]", this), 10, 3, Qt::AlignLeft);
    layout->addWidget(new QLabel("m_y"), 11, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 11, 1, Qt::AlignCenter);
    layout->addWidget(myLabel,11,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[uT]", this), 11, 3, Qt::AlignLeft);
    layout->addWidget(new QLabel("m_z"), 12, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 12, 1, Qt::AlignCenter);
    layout->addWidget(mzLabel,12,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[uT]", this), 12, 3, Qt::AlignLeft);
}

void ImuView::updateAccel(std::array<float, 3> arg){
    axLabel->setText(QString::number(arg[0],'f',3));
    ayLabel->setText(QString::number(arg[1],'f',3));
    azLabel->setText(QString::number(arg[2],'f',3));
}
void ImuView::updateGyro(std::array<float, 3> arg){
    gxLabel->setText(QString::number(arg[0],'f',3));
    gyLabel->setText(QString::number(arg[1],'f',3));
    gzLabel->setText(QString::number(arg[2],'f',3));
}
void ImuView::updateMagnet(std::array<float, 3> arg){
    mxLabel->setText(QString::number(arg[0],'f',3));
    myLabel->setText(QString::number(arg[1],'f',3));
    mzLabel->setText(QString::number(arg[2],'f',3));
}
