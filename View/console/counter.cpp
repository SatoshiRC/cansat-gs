#include "counter.h"

Counter::Counter(QWidget *parent,int16_t upperLim, int16_t lowerLim, QString name)
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

    valueText->setText(QString::number(layout->verticalSpacing()));
}
