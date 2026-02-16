#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

#include "View/ModeSelector/ModeSelector.hpp"
#include "View/StateViewer/StateViewer.hpp"
#include "View/SerialConfigure.hpp"
#include "View/console/console.hpp"

#include "VM/commandvm.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow* getUi(){
        return ui;
    }

private:
    Ui::MainWindow *ui;
    QWidget *centralWidget;
    QGridLayout *layout;

    SerialConfigure *serialConfiger;
    ModeSelector *modeSelector;
    StateViwer *stateViewr;
    Console *console;

    commandVM *commandVm;

    void binding();
};
#endif // MAINWINDOW_H
