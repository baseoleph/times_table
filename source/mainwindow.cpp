#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->hide();

    tm_go = new QTimer;
    connect(tm_go, &QTimer::timeout, this, &MainWindow::animate);

    tm = new QTimer;
    connect(tm, &QTimer::timeout, this, &MainWindow::setUpScene);
    tm->start(150);
}

MainWindow::~MainWindow()
{
    if (mview != nullptr) delete mview;
    if (tm != nullptr) delete tm;
    if (tm_go != nullptr) delete tm_go;
    if (scene != nullptr) delete scene;
    delete ui;
}

void MainWindow::setUpScene()
{
    tm->stop();
    mview = new MQGraphicsView;

    ui->centralwidget->layout()->addWidget(mview);
    count = ui->lineEditd_dots->text().toInt();
    mview->mscene->updateDots(count);
    times = ui->lineEditd_times->text().toDouble();
    mview->mscene->updateLines(times);
    step = ui->lineEditd_step->text().toDouble();
}


void MainWindow::on_lineEditd_dots_textEdited(const QString &arg1)
{
    count = arg1.toInt();
    mview->mscene->updateDots(count);
}

void MainWindow::on_lineEditd_times_textEdited(const QString &arg1)
{
    times = arg1.toDouble();
    mview->mscene->updateLines(times);
}

void MainWindow::on_lineEditd_step_textEdited(const QString &arg1)
{
    step = arg1.toDouble();
}

void MainWindow::on_pushButton_step_clicked()
{
    is_play ^= true;
    if (is_play)
    {
        tm_go->start(50);
        ui->pushButton_step->setText("stop");
    }
    else
    {
        tm_go->stop();
        ui->pushButton_step->setText("start");
    }
}

void MainWindow::animate()
{
//    tm_go->stop();

    times += step;
    ui->lineEditd_times->setText(QString::number(times));
    mview->mscene->updateLines(times);
//    int ll = times;
//    int test = ((int)(abs(times) * 10000 - abs(ll) * 10000));
//    if (test == 9999 || test == 0)
//    {
//        tm_go->start(300);
//    }
//    else
//    {
//        tm_go->start(50);
//    }
}
