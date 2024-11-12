#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->LoadImage, &QPushButton::clicked, this, &MainWindow::onLoadImageClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoadImageClicked()
{
    // This is the backend function handling the button click
    QMessageBox::information(this, "Button Clicked", "The push button was clicked!");
}
