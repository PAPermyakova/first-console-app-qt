#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double f(double x)
{
    //float y = 9 * x * x + log(x);
    double y = 2 * x * x - log(x);
    return y;
}

void MainWindow::on_findMin_clicked() {
    double a, b, e, centre, d, delta, x1, x2, y1, y2;
    const double K = 0.1;
    a = ui->leftBorder->value();
    b = ui->rightBorder->value();
    e = ui->accuracy->value();
    if (a >= 0 && b > a) {
        ui->error->setText("all right");
        do {
           d = b - a;
           centre = (a + b) / 2;
           delta = K * (b - a) / 2;
           x1 = centre - delta;
           x2 = centre + delta;
           y1 = f(x1);
           y2 = f(x2);
           if (y1 < y2) {
               b = x2;
           }
           if (y1 > y2) {
               a = x1;
           }
           else {
               a = x1;
               b = x2;
           }
       } while (d >= e);
        ui->min->setText(QString::number(a));
        ui->interval->setText(QString::number(d));
        }
    else {
        ui->error->setText("error");
    }
}

