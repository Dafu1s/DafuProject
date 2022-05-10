#include "ModbusTcpClient.h"
#include "ui_ModbusTcpClient.h"
#include <QModbusRtuSerialMaster>
#include <QSerialPort>
#include <QModbusDataUnit>
#include <QDebug>
#include <QUrl>
#include <QModbusTcpClient>
#include<QMessageBox>
#include<QRegExpValidator>


ModbusTcpClient::ModbusTcpClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ModbusTcpClient),m_holdingRegisters(20)
{
    ui->setupUi(this);

    setQRegExs();

    modbusDevice = new QModbusTcpClient(this);//QModbusTcpClient用于TCP通信中的client


    if (ui->lineEdit->text().isEmpty())
        ui->lineEdit->setText(QLatin1Literal("127.0.0.1:502"));
    connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {
        statusBar()->showMessage(modbusDevice->errorString(), 5000);
    });
    connect(modbusDevice, &QModbusClient::stateChanged,
            this, &ModbusTcpClient::onStateChanged);//连接状态发生改变时改变connect按钮上的显示文字（connect or discennect）


//    QByteArray text = QByteArray::fromHex("517420697320677265617421");
//    text.data();            // returns "Qt is great!"
//    qDebug()<<text.data();

}

void ModbusTcpClient::setQRegExs()
{
    QRegExp regx("[0-9]+$");


    ui->writeadressEdit->setValidator(new QRegExpValidator(regx, this));
    ui->ReadAdresslineEdit->setValidator(new QRegExpValidator(regx, this));

}

QModbusDataUnit::RegisterType ModbusTcpClient::Request()
{
    QModbusDataUnit::RegisterType type = QModbusDataUnit::Invalid;

    if (ui->cbRegisterType->currentText() == QString("线圈"))
    {
         type = QModbusDataUnit::Coils;
          qDebug() << "Coils: " << type;
    }
    else if (ui->cbRegisterType->currentText() == QString("离散输入"))
    {
        type = QModbusDataUnit::DiscreteInputs;
         qDebug() << "DiscreteInputs: " << type;
    }
    else if (ui->cbRegisterType->currentText() == QString("输入寄存器"))
    {
        type = QModbusDataUnit::InputRegisters;
         qDebug() << "InputRegisters: " << type;
    }
    else if (ui->cbRegisterType->currentText() == QString("保持寄存器"))
    {
        type = QModbusDataUnit::HoldingRegisters;
         qDebug() << "HoldingRegisters: " << type;
    }

    return type;
}

ModbusTcpClient::~ModbusTcpClient()
{
    if (modbusDevice)
        modbusDevice->disconnectDevice();
    delete modbusDevice;
    delete ui; 
}

void ModbusTcpClient::on_connectButton_clicked()
{
    if (!modbusDevice)
        return;
    statusBar()->clearMessage();

    if (modbusDevice->state() != QModbusDevice::ConnectedState) {//如果处在非连接状态，进行连接
        const QUrl url = QUrl::fromUserInput(ui->lineEdit->text());//获取IP和端口号
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, url.port());
        modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, url.host());

        modbusDevice->setTimeout(1000);//连接超时1S
        modbusDevice->setNumberOfRetries(3);//连接失败重试三次连接
        if (!modbusDevice->connectDevice()) {
            statusBar()->showMessage(tr("Connect failed: ") + modbusDevice->errorString(), 5000);
        }
    }else{//处在连接状态进行断开连接的操作
        modbusDevice->disconnectDevice();
    }
}

void ModbusTcpClient::onStateChanged(int state)//更新connect按钮的显示状态
{

    if (state == QModbusDevice::UnconnectedState)
        ui->connectButton->setText(tr("Connect"));
    else if (state == QModbusDevice::ConnectedState)
        ui->connectButton->setText(tr("Disconnect"));
}

void ModbusTcpClient::on_readButton_clicked()
{
    if (!modbusDevice)
        return;
    if(ui->ReadAdresslineEdit->text()==""){

        QMessageBox::critical(this, tr("提示"), tr("读地址为空，请输入数据"));
        return;
    }

    statusBar()->clearMessage();

    qint16 address=ui->ReadAdresslineEdit->text().toInt();
    QModbusDataUnit readDataUnit(Request(), address, 1);

    if (auto *reply = modbusDevice->sendReadRequest(readDataUnit, 1)) {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &ModbusTcpClient::readReady);
        else
            delete reply; // broadcast replies return immediately
    } else {
        statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
    }
}


void ModbusTcpClient::readReady()//在这里读的数据
{
    auto reply = qobject_cast<QModbusReply *>(sender());//QModbusReply这个类存储了来自client的数据,sender()返回发送信号的对象的指针
    if (!reply)
        return;


//数据从QModbusReply这个类的resuil方法中获取,也就是本程序中的reply->result()
    if (reply->error() == QModbusDevice::NoError) {
        const QModbusDataUnit unit = reply->result();
        for (uint i = 0; i < unit.valueCount(); i++) {
            const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress()).arg(QString::number(unit.value(i), 10));
//            ui->readValue->addItem(entry);//把数据放在QListWidget中
            ui->textEdit_2->append(entry);
        }
    } else if (reply->error() == QModbusDevice::ProtocolError) {
        statusBar()->showMessage(tr("Read response error: %1 (Mobus exception: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->rawResult().exceptionCode(), -1, 16), 5000);
    } else {
        statusBar()->showMessage(tr("Read response error: %1 (code: 0x%2)").
                                    arg(reply->errorString()).
                                    arg(reply->error(), -1, 16), 5000);
    }

    reply->deleteLater();
}



void ModbusTcpClient::on_sendButton_clicked()
{
    if (!modbusDevice)//如果设备没有被创建就返回
        return;

    if(ui->textEdit->toPlainText()==""||ui->writeadressEdit->text()==""){

        QMessageBox::critical(this, tr("提示"), tr("写数据或地址为空，请输入数据"));
        return;
    }

    QString str1 = ui->textEdit->toPlainText();
    qint16 address=ui->writeadressEdit->text().toInt();
    qDebug()<<"str1"<<str1;
    QByteArray str2 = QByteArray::fromHex (str1.toLatin1().data());//按十六进制编码接入文本
      qDebug()<<"str2"<<str2;
    QString str3 = str2.toHex().data();//以十六进制显示
     qDebug()<<"str3"<<str3;
    bool ok;
    int hex =str3.toInt(&ok,10);
    qDebug()<<"hex"<<hex;
    statusBar()->clearMessage();//清除状态栏显示的信息



    QModbusDataUnit writeUnit(Request(),address,1);//发送的数据信息（数据类型 ，起始地址，个数）

    writeUnit.setValue(0, hex);

    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit, 1)) {
        if (!reply->isFinished()) {   //reply Returns true when the reply has finished or was aborted.
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::ProtocolError) {
                    statusBar()->showMessage(tr("Write response error: %1 (Mobus exception: 0x%2)")
                        .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16),
                        5000);
                } else if (reply->error() != QModbusDevice::NoError) {
                    statusBar()->showMessage(tr("Write response error: %1 (code: 0x%2)").
                        arg(reply->errorString()).arg(reply->error(), -1, 16), 5000);
                }
                reply->deleteLater();
            });
        } else {
            // broadcast replies return immediately
            reply->deleteLater();
        }
    } else {
        statusBar()->showMessage(tr("Write error: ") + modbusDevice->errorString(), 5000);
    }
}

