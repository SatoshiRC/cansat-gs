#include "console.hpp"

Console::Console(QWidget *parent)
    :QWidget(parent)
{
    layout = new QHBoxLayout(this);

    ParachuteLeft = new servo(this, "Parachute-Left");
    ParachuteRight = new servo(this, "Parachute-Right");
    Stabilizer = new servo(this, "Stabilizer");

    auto firstCol = new QVBoxLayout(this);
    layout->addLayout(firstCol);
    firstCol->addWidget(ParachuteLeft);
    firstCol->addWidget(ParachuteRight);
    firstCol->addStretch(1);

    auto SecondCol = new QVBoxLayout(this);
    layout->addLayout(SecondCol);
    SecondCol->addWidget(Stabilizer);
    SecondCol->addStretch(1);

    layout->addStretch(1);

}
