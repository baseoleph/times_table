#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "mqgraphicsview.h"
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MQGraphicsView *mview = nullptr;
    Scene *scene = nullptr;
    QTimer *tm = nullptr;

    void setUpScene();
};
#endif // MAINWINDOW_H
