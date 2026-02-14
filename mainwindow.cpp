#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , centralWidget(new QWidget(this))
    , layout(new QGridLayout(centralWidget))
    , serialConfiger(new SerialConfigure(centralWidget))
    , modeSelector(new ModeSelector(centralWidget))
    , stateViewr(new StateViwer(centralWidget))
    , console(new Console(centralWidget))
{
    ui->setupUi(this);
    auto f = this->font();
    f.setPointSize(12);
    this->setFont(f);
    
    // Set central widget with layout
    setCentralWidget(centralWidget);

    layout->addWidget(serialConfiger,0,0,1,2);
    layout->addWidget(modeSelector,1,0);
    layout->addWidget(console, 1,1);
    layout->addWidget(stateViewr, 2, 0, 1, 2);


    modeSelector->addMode(1, "Debug");
    modeSelector->addMode(2, "Debug2");
    modeSelector->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
