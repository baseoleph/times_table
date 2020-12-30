#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->hide();

    tm = new QTimer;
    connect(tm, &QTimer::timeout, this, &MainWindow::setUpScene);
    tm->start(150);
}

MainWindow::~MainWindow()
{
    if (mview != nullptr) delete mview;
    if (tm != nullptr) delete tm;
    if (scene != nullptr) delete scene;
    delete ui;
}

void MainWindow::setUpScene()
{
    tm->stop();
    mview = new MQGraphicsView;

    ui->centralwidget->layout()->addWidget(mview);
}


void MainWindow::on_lineEditd_dots_textEdited(const QString &arg1)
{
    count = arg1.toInt();
}

void MainWindow::on_pushButton_dots_clicked()
{
    mview->mscene->updateDots(count);
}

void MainWindow::on_lineEditd_times_textEdited(const QString &arg1)
{
    times = arg1.toDouble();
}

void MainWindow::on_pushButton_times_clicked()
{
    mview->mscene->updateLines(times);
}
