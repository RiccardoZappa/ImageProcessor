#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ImageLoader.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->LoadImage, &QPushButton::clicked, this, &MainWindow::openImageLoader);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImageLoader()
{
    // Create a new ImageLoader window and show it
    Utils::ImageLoader *imageLoader = new Utils::ImageLoader();
    imageLoader->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete the widget when closed
    imageLoader->resize(800, 600);
    imageLoader->show();
}
