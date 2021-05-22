#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>
#include <vector>
#include "mycom.h"
#include "FUNCTIONS/MathFunctions.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT   

public:

QSerialPort* workPort = nullptr;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void fillComboBox(const QList<QString>& qstrV);

private slots:

void on_pushButton_clicked();

void on_refreshButton_clicked();

void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
};







#endif // MAINWINDOW_H
