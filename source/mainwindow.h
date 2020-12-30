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

private slots:
    void on_lineEditd_dots_textEdited(const QString &arg1);

    void on_pushButton_dots_clicked();

    void on_lineEditd_times_textEdited(const QString &arg1);

    void on_pushButton_times_clicked();

private:
    Ui::MainWindow *ui;
    MQGraphicsView *mview = nullptr;
    Scene *scene = nullptr;
    QTimer *tm = nullptr;

    int count = 0;
    double times = 0;
    void setUpScene();
};
#endif // MAINWINDOW_H
