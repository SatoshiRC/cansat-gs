#ifndef MODE_SELECTOR_HPP
#define MODE_SELECTOR_HPP

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QMap>
#include <QPushButton>
#include <QLabel>

class ModeSelector : public QWidget{
    Q_OBJECT

public:
    explicit ModeSelector(QWidget *parent = nullptr);
    void addMode(uint8_t id, QString key);

signals:
    void onChangeMode(uint8_t id, QString key);

private:
    QVBoxLayout *layout;
    QMap<uint8_t, QPushButton*> buttons;
    QLabel *currentMode;
};

#endif /*MODE_SELECTOR_HPP*/
