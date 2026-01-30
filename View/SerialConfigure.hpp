#ifndef SERIAL_CONFIGURE_HPP
#define SERIAL_CONFIGURE_HPP

#include<QWidget>
#include<QHBoxLayout>
#include<QTextEdit>
#include<QLabel>
#include<QComboBox>
#include<QPushButton>
#include<QStackedWidget>

class SerialConfigure : public QWidget {
    Q_OBJECT
public:
    SerialConfigure(QWidget *parent = nullptr);

private:
    QHBoxLayout *layout;

    QLabel *portLabel;
    QComboBox *portSelect;
    QPushButton *scanButton;
    QLabel *BaudrateLabel;
    QComboBox *baudrateSelect;
    QStackedWidget *stackeButton;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
};

#endif //SERIAL_CONFIGURE_HPP
