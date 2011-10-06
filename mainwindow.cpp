#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Program_clicked()
{
    // Program button clicked
}

void MainWindow::on_pushButton_Connect_clicked()
{
    // Connect button clicked
}

void MainWindow::on_toolButton_PickFile_clicked()
{
	QString file_name;
    // XXX rinky, should generate a better version, see docs

	file_name = QFileDialog::getOpenFileName(this,
         tr("Select Firmware File"), "/", tr("OpenPilot Firmware (*.ofw)"));
}
