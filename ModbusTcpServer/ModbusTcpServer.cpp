#include "ModbusTcpServer.h"
#include "ui_ModbusTcpServer.h"
#include <QModbusDevice>
#include <QSerialPort>
#include <QModbusRtuSerialSlave>
#include <QDebug>
#include <QUrl>
#include <QModbusTcpServer>
#include<QMessageBox>
#include<QRegExpValidator>

ModbusTcpServer::ModbusTcpServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModbusTcpServer)
{
    ui->setupUi(this);

    modbusDevice = new QModbusTcpServer(this);
    if (ui->lineEdit->text().isEmpty())
        ui->lineEdit->setText(QLatin1Literal("127.0.0.1:502"));

    QRegExp regx("[0-9]+$");//
    ui->adresslineEdit->setValidator(new QRegExpValidator(regx, this));
    ui->readadresslineEdit->setValidator(new QRegExpValidator(regx, this));

    reg.insert(QModbusDataUnit::Coils, { QModbusDataUnit::Coils, 0, 10 });//线圈
    modbusDevice->setMap(reg);//把reg设置给了全局的m_modbusDataUnitMap
    connect(ui->cbRegisterType,SIGNAL(currentIndexChanged(int)),this,SLOT(SlotgChangereadRequest(int)));

    connect(modbusDevice, &QModbusServer::stateChanged,
            this, &ModbusTcpServer::onStateChanged);//连接状态发生改变时改变connect按钮上的显示文字（connect or discennect）


    connect(modbusDevice, &QModbusServer::dataWritten,
            this, &ModbusTcpServer::updateWidgets);//modbus客户端向服务器写入数据时dataWritten信号被触发
    connect(modbusDevice, &QModbusServer::errorOccurred,
            this, &ModbusTcpServer::handleDeviceError);
}

ModbusTcpServer::~ModbusTcpServer()
{
    delete ui;
    if (modbusDevice)
        modbusDevice->disconnectDevice();//清除
    delete modbusDevice;
}

void ModbusTcpServer::on_connectButton_clicked()
{
    if (!modbusDevice)
        return;
    statusBar()->clearMessage();

    QString comPortName = ui->lineEdit->text();
    if (modbusDevice->state() != QModbusDevice::ConnectedState) {//如果处在非连接状态，进行连接
        //进行TCP连接
        const QUrl url = QUrl::fromUserInput(ui->lineEdit->text());
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, url.port());
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, url.host());
        modbusDevice->setServerAddress(1);
        if (!modbusDevice->connectDevice()) {
            statusBar()->showMessage(tr("Connect failed: ") + modbusDevice->errorString(), 5000);
        }
    }else{//处在连接状态进行断开连接的操作
        modbusDevice->disconnectDevice();
    }
}

void ModbusTcpServer::onStateChanged(int state)//判断联连状态是否改变，如改变则更改连接按钮上的文字
{

    if (state == QModbusDevice::UnconnectedState)
        ui->connectButton->setText(tr("Connect"));
    else if (state == QModbusDevice::ConnectedState)
        ui->connectButton->setText(tr("Disconnect"));
}

void ModbusTcpServer::updateWidgets(QModbusDataUnit::RegisterType table, int address, int size)
{

        quint16 value;

        switch (table) {
        case QModbusDataUnit::Coils:
            modbusDevice->data(QModbusDataUnit::Coils, address , &value);
            break;
        case QModbusDataUnit::HoldingRegisters:
            modbusDevice->data(QModbusDataUnit::HoldingRegisters, address , &value);//得到数据后做出显示
            break;
        case QModbusDataUnit::DiscreteInputs:
             modbusDevice->data(QModbusDataUnit::DiscreteInputs, address , &value);//得到数据后做出显示
            break;
        case QModbusDataUnit::InputRegisters:
             modbusDevice->data(QModbusDataUnit::InputRegisters, address , &value);//得到数据后做出显示
            break;
        default:
            break;
        }
        QString data =QString("Update address:%1").arg(address)+" "+tr("data:")+ QString::number(value, 10);

        qDebug("%d",value);
        ui->textEdit->append(data);

}

void ModbusTcpServer::handleDeviceError(QModbusDevice::Error newError)//错误提示
{
    if (newError == QModbusDevice::NoError || !modbusDevice)
        return;

    statusBar()->showMessage(modbusDevice->errorString(), 5000);
}

void ModbusTcpServer::on_clearButton_clicked()//清除texiedit上的文本
{
    ui->textEdit->clear();
}

void ModbusTcpServer::on_writeButton_clicked()
{

    if(ui->textEdit_2->toPlainText()==""||ui->adresslineEdit->text()==""){

        QMessageBox::critical(this, tr("提示"), tr("数据或地址为空，请输入数据"));
        return;
    }

    QString str = ui->textEdit_2->toPlainText();
    quint16  address=ui->adresslineEdit->text().toInt();
    QString str2 = str.replace(" ","");
    str2=str2.mid(0,4);
    qDebug()<<"str2"<<" "<<str2;

    bool ok;
    quint16 hex = str2.toInt(&ok,10);
    qDebug()<<"hex"<<" "<<hex;

//    reg.insert(QModbusDataUnit::HoldingRegisters, { QModbusDataUnit::HoldingRegisters, address, 1 });
//    modbusDevice->setMap(reg);//把reg设置给了全局的m_modbusDataUnitMap
    modbusDevice->setData(setRequest(), address, hex);
}

void ModbusTcpServer::on_readdataButton_clicked()
{
    if (!modbusDevice)
        return;
    if(ui->readadresslineEdit->text()==""){

        QMessageBox::critical(this, tr("提示"), tr("读地址为空，请输入数据"));
        return;
    }

    qint16 address=ui->readadresslineEdit->text().toInt();
    statusBar()->clearMessage();

    quint16 value;
    modbusDevice->data(setRequest(), address, &value);//得到数据后做出显示

    QString data =QString("Read address:%1").arg(address)+" "+tr("data:")+ QString::number(value, 10);
    ui->textEdit->append(data);
}

void ModbusTcpServer::SlotgChangereadRequest(int index)
{

    if (ui->cbRegisterType->currentText() == QString("线圈"))
    {
        reg.insert(QModbusDataUnit::Coils, { QModbusDataUnit::Coils, 0, 50000 });//线圈
    }
    else if (ui->cbRegisterType->currentText() == QString("离散输入"))
    {
         reg.insert(QModbusDataUnit::DiscreteInputs, { QModbusDataUnit::DiscreteInputs, 0, 50000 });//离散输入
    }
    else if (ui->cbRegisterType->currentText() == QString("输入寄存器"))
    {
         reg.insert(QModbusDataUnit::InputRegisters, { QModbusDataUnit::InputRegisters, 0, 50000 });//输入寄存器
    }
    else if (ui->cbRegisterType->currentText() == QString("保持寄存器"))
    {
        reg.insert(QModbusDataUnit::HoldingRegisters, { QModbusDataUnit::HoldingRegisters, 0, 50000 });//保持寄存器
    }


    modbusDevice->setMap(reg);//把reg设置给了全局的m_modbusDataUnitMap
}

QModbusDataUnit::RegisterType ModbusTcpServer::setRequest()
{
    QModbusDataUnit::RegisterType type = QModbusDataUnit::Invalid;

    if (ui->cbRegisterType->currentText() == QString("线圈"))
    {
         type = QModbusDataUnit::Coils;
         qDebug()<<"Coils";
    }
    else if (ui->cbRegisterType->currentText() == QString("离散输入"))
    {
        type = QModbusDataUnit::DiscreteInputs;
         qDebug()<<"DiscreteInputs";
    }
    else if (ui->cbRegisterType->currentText() == QString("输入寄存器"))
    {
        type = QModbusDataUnit::InputRegisters;
         qDebug()<<"InputRegisters";
    }
    else if (ui->cbRegisterType->currentText() == QString("保持寄存器"))
    {
        type = QModbusDataUnit::HoldingRegisters;
         qDebug()<<"HoldingRegisters";
    }

    return type;
}
