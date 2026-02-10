#include "counter.h"

Counter::Counter(QWidget *parent, int16_t lowerLim, int16_t upperLim, QString name)
    : QWidget{parent},
    upperLim(upperLim),
    lowerLim(lowerLim)
{
    layout = new QGridLayout(this);
    titleLabel = new QLabel(name, this);
    minusButton = new QPushButton("-", this);
    plusButton = new QPushButton("+", this);
    valueText = new QLineEdit("0", this);

    // valueText->setFixedHeight(plusButton->height());
    valueText->setSizePolicy(QSizePolicy(QSizePolicy::Policy::MinimumExpanding,QSizePolicy::Fixed));
    titleLabel->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Fixed,QSizePolicy::Fixed));

    layout->addWidget(titleLabel,0,0,1,3,Qt::AlignTop);
    layout->addWidget(minusButton,1,0,1,1,Qt::AlignTop);
    layout->addWidget(valueText,1,2,1,1,Qt::AlignTop);
    layout->addWidget(plusButton,1,3,1,1,Qt::AlignTop);
    layout->setRowStretch(2,1);
    layout->setColumnStretch(4,1);

    connect(plusButton, &QPushButton::clicked, this, &Counter::increment);
    connect(minusButton, &QPushButton::clicked, this, &Counter::decrement);
    connect(valueText, &QLineEdit::textEdited, this, &Counter::edit);

    setValue(lowerLim);
    valueText->setValidator(new QIntValidator(lowerLim, upperLim, this));
}

void Counter::increment(int16_t delta){
    if(delta <= 0){
        delta = 1;
    }
    if(currentValue + delta < upperLim){
        setValue(currentValue + delta);
    }else{
        setValue(upperLim);
    }
}

void Counter::decrement(int16_t delta){
    if(delta >= 0){
        delta = -1;
    }
    if(currentValue + delta > lowerLim){
        setValue(currentValue + delta);
    }else{
        setValue(lowerLim);
    }
}

void Counter::edit(const QString &text){
    setValue(text.toInt());
}

void Counter::setValue(int16_t value){
    currentValue = value;
    valueText->setText(QString::number(currentValue));
    emit onChangeValue(currentValue);
}

void Counter::wheelEvent(QWheelEvent *event){
    qint16 steps = event->angleDelta().y() / 120 * 5;
    if(steps > 0){
        increment(steps);
    }else{
        decrement(steps);
    }
}
