#include "ModeSelector.hpp"

ModeSelector::ModeSelector(QWidget *parent)
:QWidget(parent){
    layout = new QVBoxLayout(this);
    this->setLayout(layout);
    currentMode = new QLabel(this);
    currentMode->setText("test");
    // currentMode->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Minimum,QSizePolicy::Minimum));
    layout->addWidget(currentMode,0);
    layout->addStretch();
}

void ModeSelector::addMode(uint8_t id, QString key){
    buttons[id] = new QPushButton(this);
    buttons[id]->setText(key);
    layout->insertWidget(layout->count()-1,buttons[id]);
}
