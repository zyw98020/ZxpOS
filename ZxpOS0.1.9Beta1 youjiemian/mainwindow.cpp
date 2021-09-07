#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdio>
#include <QPushButton>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *bt1 = new QPushButton("关机", this);
    bt1->resize(50, 30);
    connect(bt1,&QPushButton::clicked,this,&QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

