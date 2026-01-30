#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "View/console/counter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , centralWidget(new QWidget(this))
    , layout(new QGridLayout(centralWidget))
    , serialConfiger(new SerialConfigure(centralWidget))
    , modeSelector(new ModeSelector(centralWidget))
{
    ui->setupUi(this);
    
    // Set central widget with layout
    setCentralWidget(centralWidget);

    layout->addWidget(serialConfiger,0,0,1,2);
    layout->addWidget(modeSelector,1,0);
    modeSelector->addMode(1, "Debug");
    modeSelector->addMode(2, "Debug2");
    modeSelector->show();

    auto c = new Counter(this, 0, 0, "Debug");
    layout->addWidget(c, 1, 1);

}

MainWindow::~MainWindow()
{
    delete ui;
}
