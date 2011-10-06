#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Populate port list
    QVector<QString> ports;

#if (defined (Q_OS_MAC) || defined (Q_OS_LINUX))

    // Add USB serial port adapters
    // TODO Strangely usb serial port adapters are not enumerated, even when connected
    QString devdir = "/dev";
    QDir dir(devdir);
    dir.setFilter(QDir::System);

    QFileInfoList list = dir.entryInfoList();
    for (int i = list.size() - 1; i >= 0; i--) {
        QFileInfo fileInfo = list.at(i);
        if ((fileInfo.fileName().contains(QString("ttyUSB")) || fileInfo.fileName().contains(QString("ttyS")) || fileInfo.fileName().contains(QString("tty.")) || fileInfo.fileName().contains(QString("ttyACM")))
            && !fileInfo.fileName().contains(QString("tty.B")))
        {
            ports.append(fileInfo.canonicalFilePath());
        }
    }
#endif

    foreach (QString port, ports)
    {
        ui->comboBox->addItem(port);
    }
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
