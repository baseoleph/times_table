#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->hide();

    keyPageDown = new QShortcut(this);
    keyPageDown->setKey(Qt::Key_PageDown);
    keyPageUp = new QShortcut(this);
    keyPageUp->setKey(Qt::Key_PageUp);
    keyEnter = new QShortcut(this);
    keyEnter->setKey(Qt::Key_Return);

    connect(keyPageDown, &QShortcut::activated, this, &MainWindow::on_pushButton_right_clicked);
    connect(keyPageUp, &QShortcut::activated, this, &MainWindow::on_pushButton_left_clicked);
    connect(keyEnter, &QShortcut::activated, this, &MainWindow::on_pushButton_step_clicked);

    timer_animate = new QTimer;
    connect(timer_animate, &QTimer::timeout, this, &MainWindow::animate);

    timer_for_setup_scene = new QTimer;
    connect(timer_for_setup_scene, &QTimer::timeout, this, &MainWindow::setUpScene);
    timer_for_setup_scene->start(150);
}

MainWindow::~MainWindow()
{
    if (mview != nullptr) delete mview;
    if (timer_for_setup_scene != nullptr) delete timer_for_setup_scene;
    if (timer_animate != nullptr) delete timer_animate;
    if (scene != nullptr) delete scene;
    delete ui;
}

void MainWindow::setUpScene()
{
    timer_for_setup_scene->stop();
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
        timer_animate->start(50);
        ui->pushButton_step->setText("stop");
    }
    else
    {
        timer_animate->stop();
        ui->pushButton_step->setText("start");
    }
}

void MainWindow::animate()
{
    times += step;
    ui->lineEditd_times->setText(QString::number(times));
    mview->mscene->updateLines(times);
}

void MainWindow::on_pushButton_left_clicked()
{
    timer_animate->stop();
    times = ceil(times - 1);
    ui->lineEditd_times->setText(QString::number(times));
    mview->mscene->updateLines(times);
}

void MainWindow::on_pushButton_right_clicked()
{
    timer_animate->stop();
    times = floor(times + 1);
    ui->lineEditd_times->setText(QString::number(times));
    mview->mscene->updateLines(times);
}
