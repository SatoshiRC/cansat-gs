#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <QWidget>
#include <QMap>

class Console : public QWidget{
    Q_OBJECT
public:
    Console(QWidget *parent = nullptr);
    void addMode(uint8_t id, QWidget *child);

public slots:
    void modeChange(uint8_t id){};

private:
    struct _Console{
        uint8_t id;
        QWidget *child;
    };
    QMap<uint8_t, QWidget*> childs;
    uint8_t activeKey;

};
#endif //CONSOLE_HPP
