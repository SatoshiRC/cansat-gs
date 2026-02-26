#include "console.hpp"

Console::Console(QWidget *parent)
    :QWidget(parent)
{
    layout = new QGridLayout(this);

    ParachuteLeft = new servo(this, "Parachute-Left");
    ParachuteRight = new servo(this, "Parachute-Right");
    Stabilizer = new servo(this, "Stabilizer");

    setGoal = new SetGoalView(this);

    layout->setColumnStretch(3,1);
    layout->addWidget(ParachuteLeft, 0, 0);
    layout->addWidget(ParachuteRight, 0, 1);
    layout->addWidget(Stabilizer, 0, 2);

    layout->addWidget(setGoal, 1, 0, 1, 2, Qt::AlignLeft);

}
