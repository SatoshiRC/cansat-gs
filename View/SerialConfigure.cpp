#include "SerialConfigure.hpp"

SerialConfigure::SerialConfigure(QWidget *parent)
:QWidget(parent){
    layout = new QHBoxLayout(this);

    portLabel = new QLabel("Port", this);
    portSelect = new QComboBox(this);
    scanButton = new QPushButton("Scan",this);
    BaudrateLabel = new QLabel("Baudrate", this);
    baudrateSelect = new QComboBox(this);
    stackeButton = new QStackedWidget(this);
    connectButton = new QPushButton("Connect", stackeButton);
    disconnectButton = new QPushButton("Disconnect", stackeButton);
    stackeButton->setMinimumWidth(disconnectButton->width());
    stackeButton->addWidget(connectButton);
    stackeButton->addWidget(disconnectButton);
    stackeButton->setCurrentWidget(connectButton);
    stackeButton->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Preferred,QSizePolicy::Fixed));

    layout->addWidget(portLabel);
    layout->addWidget(portSelect, 1);
    layout->addWidget(scanButton);
    layout->addWidget(BaudrateLabel);
    layout->addWidget(baudrateSelect);
    layout->addWidget(stackeButton);
    layout->addStretch(1);

    QList<qint32> baudrateList = QSerialPortInfo::standardBaudRates();
    foreach (auto i, baudrateList) {
        baudrateSelect->addItem(QString::number(i),i);
    }
    baudrateSelect->setCurrentText("115200");

    connect(scanButton, &QPushButton::clicked, this, &SerialConfigure::onScan);
    connect(connectButton, &QPushButton::clicked, this, &SerialConfigure::onConnect);
    connect(disconnectButton, &QPushButton::clicked, this, &SerialConfigure::onDisconnect);
    onScan();
}

void SerialConfigure::onScan(){
    auto portList = QSerialPortInfo::availablePorts();
    portSelect->clear();
    foreach (auto port, portList){
        auto t = port.portName() + " : " + port.description();
        portSelect->addItem(t, port.portName());
    }
}

void SerialConfigure::onConnect(){
    QSerialPortInfo portInfo(portSelect->currentData().toString());
    qint32 baudrate = baudrateSelect->currentData().toUInt();

    if(emit serialConnect(portInfo, baudrate)){
        stackeButton->setCurrentWidget(disconnectButton);
    }
}

void SerialConfigure::onDisconnect(){
    emit serialDisconnect();
    stackeButton->setCurrentWidget(connectButton);
}
