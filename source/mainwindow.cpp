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

