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
    stackeButton->addWidget(connectButton);
    stackeButton->addWidget(disconnectButton);
    stackeButton->setCurrentWidget(connectButton);
    stackeButton->setSizePolicy(QSizePolicy(QSizePolicy::Policy::MinimumExpanding,QSizePolicy::Fixed));

    layout->addWidget(portLabel);
    layout->addWidget(portSelect, 1);
    layout->addWidget(scanButton);
    layout->addWidget(BaudrateLabel);
    layout->addWidget(baudrateSelect);
    layout->addWidget(stackeButton);
}
