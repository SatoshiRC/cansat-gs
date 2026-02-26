#ifndef SETGOALVIEW_H
#define SETGOALVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QDoubleValidator>

class SetGoalView : public QWidget
{
    Q_OBJECT
public:
    explicit SetGoalView(QWidget *parent = nullptr);

public slots:
    void goalUpdate(double latitude, double longitude);

signals:
    void goalUpdated(double latitude, double longitude);
    std::array<double, 2> requestCurrentLocation();

private:
    QGridLayout *layout;
    QLineEdit *latitude;
    QLineEdit *longitude;
    QPushButton *getCurrentLocationButton;
    QPushButton *setGoalButton;

private slots:
    void setGoalButtonClicked();
    void getCurrentLocationButtonClicked();
};

#endif // SETGOALVIEW_H
