#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QWheelEvent>

class Counter : public QWidget
{
    Q_OBJECT
public:
    explicit Counter(QWidget *parent = nullptr, int16_t lowerLim = 0,int16_t upperLim = 0, QString name = "'");
    int16_t getValue(){
        return currentValue;
    }

public slots:
    void increment(int16_t delta = 1);
    void decrement(int16_t delta = -1);
    void edit(const QString &text);
    void setValue(int16_t value);

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

    void wheelEvent(QWheelEvent *event);
};

#endif // COUNTER_H
