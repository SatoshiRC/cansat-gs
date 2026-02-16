#ifndef SERIAL_CONFIGURE_HPP
#define SERIAL_CONFIGURE_HPP

#include<QWidget>
#include<QHBoxLayout>
#include<QTextEdit>
#include<QLabel>
#include<QComboBox>
#include<QPushButton>
#include<QStackedWidget>
#include<QtSerialPort/QSerialPortInfo>

class SerialConfigure : public QWidget {
    Q_OBJECT
public:
    SerialConfigure(QWidget *parent = nullptr);

private slots:
    void onScan();
    void onConnect();
    void onDisconnect();

public slots:
    void onErrorDisconnect();
signals:
    void serialDisconnect();
    bool serialConnect(QSerialPortInfo port, qint32 baudrate);

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
