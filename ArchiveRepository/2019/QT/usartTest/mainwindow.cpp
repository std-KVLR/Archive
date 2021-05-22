#include "mainwindow.h"
#include "ui_mainwindow.h"


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

void MainWindow::fillComboBox(const QList<QString>& qstrV)
{
    ui->comboBox->addItems(qstrV);
}



// Slots

void MainWindow::on_pushButton_clicked()
{
    double angle = ui->lineEdit->text().split(" ")[0].toDouble(); // Convert QString to double

    try
    {
        const short maxDigits = 5;
        char buffer[maxDigits + 2];
        sprintf(buffer, "%d;", angleToPulse1(angle));


        QSerialPort& workPortRef = *workPort;
        if(!workPortRef.open(QSerialPort::WriteOnly))
            throw std::runtime_error("error: can't open port");
        workPortRef.write(buffer);
    }
    catch (const std::runtime_error &e)
    {
        ui->lineEdit->setText(e.what());
    }
}

void MainWindow::on_refreshButton_clicked()
{
    ui->comboBox->clear();
    if(MyCOM::portsAsk(*this) == - 1) {
        workPort = nullptr;
        ui->lineEdit->setText("N/A");
        ui->pushButton->setEnabled(0);
    }

}

void MainWindow::on_comboBox_activated(int index)
{
    if(workPort != nullptr){
        ui->pushButton->setEnabled(1);
        QSerialPort& workPortRef = *workPort;
        workPortRef.setPortName(ui->comboBox->itemText(index));
        ui->lineEdit->setText(workPortRef.portName());
    }
}
