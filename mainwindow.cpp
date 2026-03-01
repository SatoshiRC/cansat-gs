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
    , commandVm(new commandVM(centralWidget))
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


    modeSelector->addMode(0, "WAKE UP");
    modeSelector->addMode(1, "Ready");
    modeSelector->addMode(2, "Decent");
    modeSelector->addMode(3, "Landing");
    modeSelector->addMode(4, "Relative Navigation");
    modeSelector->addMode(5, "Absolute Navigation");
    modeSelector->addMode(6, "Goal");
    modeSelector->addMode(7, "Remote Control");
    modeSelector->addMode(8, "Alittude Estimation Test");
    modeSelector->show();

    binding();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::binding(){
    connect(serialConfiger, &SerialConfigure::serialConnect, commandVm, &commandVM::connectSerial);
    connect(serialConfiger, &SerialConfigure::serialDisconnect, commandVm, &commandVM::disconnectSerial);
    connect(commandVm, &commandVM::disconnected, serialConfiger, &SerialConfigure::onErrorDisconnect);

    connect(modeSelector, &ModeSelector::modeChanged, commandVm, &commandVM::setMode);
    connect(commandVm, &commandVM::modeUpdated, modeSelector, &ModeSelector::modeChange);
    connect(console->setGoal, &SetGoalView::requestCurrentLocation, commandVm, &commandVM::requestedCurrentLocation);
    connect(console->setGoal, &SetGoalView::goalUpdated, commandVm, &commandVM::setGoal);
    connect(commandVm, &commandVM::goalUpdated, console->setGoal, &SetGoalView::goalUpdate);

    connect(commandVm, &commandVM::altitudeUpdated, stateViewr->altitudeView, &AltitudeView::update);
    connect(commandVm, &commandVM::gpsUpdated, stateViewr->gpsStatusView, &GpsStatusView::update);
    connect(commandVm, &commandVM::accelUpdated, stateViewr->imuView, &ImuView::updateAccel);
    connect(commandVm, &commandVM::gyroUpdated, stateViewr->imuView, &ImuView::updateGyro);
    connect(commandVm, &commandVM::magnetUpdated, stateViewr->imuView, &ImuView::updateMagnet);

    connect(console->ParachuteLeft, &servo::updated, commandVm, &commandVM::updateServo);
    connect(console->ParachuteRight, &servo::updated, commandVm, &commandVM::updateServo);
    connect(console->Stabilizer, &servo::updated, commandVm, &commandVM::updateServo);
    connect(commandVm, &commandVM::servoParachuteLeftUpdated, console->ParachuteLeft, &servo::update);
    connect(commandVm, &commandVM::servoParachuteRightUpdated, console->ParachuteRight, &servo::update);
    connect(commandVm, &commandVM::servoStablizerUpdated, console->Stabilizer, &servo::update);
}
