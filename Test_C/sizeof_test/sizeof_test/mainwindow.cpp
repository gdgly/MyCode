#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "data.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int size0 = sizeof(color_buff);
    qDebug("size = %0x\r\n", size0);
    qDebug("size = %0x\r\n", color_buff[0]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

