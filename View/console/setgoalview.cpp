#include "setgoalview.h"

SetGoalView::SetGoalView(QWidget *parent)
    : QWidget{parent}
{
    layout = new QGridLayout(this);
    latitude = new QLineEdit(this);
    longitude = new QLineEdit(this);
    getCurrentLocationButton = new QPushButton("Set Current GPS Position", this);
    setGoalButton = new QPushButton("Set Goal Location");

    latitude->setValidator(new QDoubleValidator(0, 90, 6, this));
    longitude->setValidator(new QDoubleValidator(0, 180, 6, this));

    auto title = new QLabel("Goal Location", this);
    QFont titleFont = title->font();
    titleFont.setBold(true);
    title->setFont(titleFont);

    layout->addWidget(title, 0, 0, 1, 4, Qt::AlignLeft);

    layout->addWidget(new QLabel("Latitude"), 1, 0, Qt::AlignLeft);
    layout->addWidget(new QLabel(" : ", this), 1, 1, Qt::AlignCenter);
    layout->addWidget(latitude,1,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[\u00b0]", this), 1, 3, Qt::AlignLeft);

    layout->addWidget(new QLabel("Longitude", this), 2, 0, Qt::AlignCenter);
    layout->addWidget(new QLabel(" : ", this), 2, 1, Qt::AlignCenter);
    layout->addWidget(longitude,2,2,Qt::AlignRight);
    layout->addWidget(new QLabel("[\u00b0]", this), 2, 3, Qt::AlignLeft);

    layout->addWidget(getCurrentLocationButton, 3, 0, 1, 4);
    layout->addWidget(setGoalButton, 4, 0, 1, 4);

    layout->setColumnStretch(5,1);
    layout->setRowStretch(5,1);

    connect(getCurrentLocationButton, &QPushButton::clicked, this, &SetGoalView::getCurrentLocationButtonClicked);
    connect(setGoalButton, &QPushButton::clicked, this, &SetGoalView::setGoalButtonClicked);
}

void SetGoalView::goalUpdate(double latitude, double longitude){
    this->latitude->setText(QString::number(latitude, 'f', 6));
    this->longitude->setText(QString::number(longitude, 'f', 6));
}

void SetGoalView::setGoalButtonClicked(){
    double latitude = this->latitude->text().toDouble();
    double longitude = this->longitude->text().toDouble();
    emit goalUpdated(latitude, longitude);
}

void SetGoalView::getCurrentLocationButtonClicked(){
    auto location = emit requestCurrentLocation();
    goalUpdate(location[0], location[1]);
}
