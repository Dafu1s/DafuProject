#ifndef ModbusTcpServer_H
#define ModbusTcpServer_H

#include <QMainWindow>
#include <QModbusDataUnit>
#include <QModbusServer>
namespace Ui {
class ModbusTcpServer;
}

class ModbusTcpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModbusTcpServer(QWidget *parent = 0);
    ~ModbusTcpServer();
     //QModbusDataUnit  readRequest()const;
     QModbusDataUnit::RegisterType setRequest();//请求类型
private slots:
    void on_connectButton_clicked();

    void onStateChanged(int state);
    void updateWidgets(QModbusDataUnit::RegisterType table, int address, int size);

    void on_clearButton_clicked();
    void handleDeviceError(QModbusDevice::Error newError);
    void on_writeButton_clicked();

    void on_readdataButton_clicked();
    void SlotgChangereadRequest(int);


private:
    QModbusDataUnitMap reg;
    Ui::ModbusTcpServer *ui;
    QModbusServer *modbusDevice;//QModbusClient被QModbusRtuSerialMaster和QModbusTcpClient继成
};

#endif // ModbusTcpServer_H
