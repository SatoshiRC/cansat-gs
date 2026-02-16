#ifndef MODE_SELECTOR_HPP
#define MODE_SELECTOR_HPP

#include <QWidget>
#include <QObject>
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

public slots:
    void modeChange(uint8_t id);
    void clicked(uint8_t id);

signals:
    void modeChanged(uint8_t id);

private:
    QVBoxLayout *layout;
    QMap<uint8_t, QPushButton*> buttons;
    QLabel *currentMode;
};

class ModeClickHandler : public QObject{
    Q_OBJECT
    qint16 id;
public:
    ModeClickHandler(QObject *parent, qint16 id):QObject(parent),id(id){}

public slots:
    void click(bool checked = false){
        emit clicked(id);
    }

signals:
    void clicked(qint16 id);

};

#endif /*MODE_SELECTOR_HPP*/
