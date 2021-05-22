#include "mycom.h"

namespace MyCOM {

int getNames(QList<QString>& qstrList,
              const QList<QSerialPortInfo>& qsiL)
{
    if(qsiL.empty()) return -1;
    //throw std::runtime_error("Serial port info vector is empty");
    for(const auto& qsi : qsiL){
        qstrList.push_back(qsi.portName());
    }
    return 0;
}

int portsAsk(MainWindow& w)
{
    QList<QSerialPortInfo> qsiL;
    QList<QString> portNames;

    qsiL = QSerialPortInfo::availablePorts();
    if(getNames(portNames, qsiL) == -1) return -1;
    w.fillComboBox(portNames);
    return 0;
}

void portInit(QSerialPort& COM_port, MainWindow& w)
{
    COM_port.setBaudRate(QSerialPort::Baud9600);
    COM_port.setDataBits(QSerialPort::Data8);
    COM_port.setParity(QSerialPort::NoParity);
    COM_port.setStopBits(QSerialPort::OneStop);
    COM_port.setFlowControl(QSerialPort::NoFlowControl);
    w.workPort = &COM_port;

}

}
