// Multiplication Table
// Copyright (C) 2021 baseoleph@gmail.com

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QShortcut>

#include "mqgraphicsview.h"
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEditd_dots_textEdited(const QString &arg1);
    void on_lineEditd_times_textEdited(const QString &arg1);
    void on_lineEditd_step_textEdited(const QString &arg1);

    void on_pushButton_step_clicked();
    void on_pushButton_left_clicked();
    void on_pushButton_right_clicked();

    void animate();

private:
    void setUpScene();

    Ui::MainWindow *ui;
    MQGraphicsView *mview = nullptr;
    Scene *scene = nullptr;
    QTimer *timer_for_setup_scene = nullptr;
    QTimer *timer_animate = nullptr;

    int count = 0;
    double times = 0;
    double step = 0;
    bool is_play = false;

    QShortcut *keyPageDown = nullptr;
    QShortcut *keyPageUp = nullptr;
    QShortcut *keyEnter = nullptr;
};
#endif // MAINWINDOW_H
