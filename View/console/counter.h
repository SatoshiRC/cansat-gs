#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Counter : public QWidget
{
    Q_OBJECT
public:
    explicit Counter(QWidget *parent = nullptr, int16_t upperLim = 0, int16_t lowerLim = 0, QString name = "'");


signals:
    void onChangeValue(int16_t value);

private:
    QGridLayout *layout;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QLineEdit *valueText;
    QLabel *titleLabel;

    int16_t upperLim;
    int16_t lowerLim;
    int16_t currentValue;
};

#endif // COUNTER_H
