#include "socketworkwithlib.h"
#include <QTimer>
#include "appsettings.h"

SocketWorkWithLib::SocketWorkWithLib(QObject *parent) : QObject(parent)
{

}

SocketWorkWithLib::~SocketWorkWithLib()
{
    if (socket) {
        socket->close();
        delete socket;
    }
    if (server) {
        server->close();
        delete server;
    }
}

void SocketWorkWithLib::initServer()
{
    server = new QTcpServer();
    QHostAddress hostAddress =  QHostAddress::LocalHost;

    if (server->listen(hostAddress, AppSettings::settingsValue("network/ipPort", 5000).toInt())) {
        connect(server, &QTcpServer::newConnection, [=] {
            socket = server->nextPendingConnection();
        });
    } else {
        throw "error" + server->errorString();
    }
}

void SocketWorkWithLib::initSocket()
{
    QString hostName {AppSettings::settingsValue("network/hostAddress", "127.0.0.1").toString()};
    quint16 port {static_cast<quint16>(AppSettings::settingsValue("network/ipPort", 5000).toUInt())};

    if (!socket) {
        socket = new QTcpSocket();
        connect(socket, &QTcpSocket::connected, [=] {
            //socket connected
        });
        connect(socket, &QTcpSocket::disconnected, [=] {
            QTimer::singleShot(300, [=] {
                socket->connectToHost(hostName, port, QIODevice::ReadWrite);
            });
        });
        connect(socket, &QTcpSocket::readyRead, [=] {
            //QByteArray ba = socket->readAll();
            int temp;
//            socket->read((char*)&temp, sizeof(temp));
            socket->read(reinterpret_cast<char*>(&temp), sizeof (temp));
        });
        connect(socket, &QTcpSocket::stateChanged, [=] (QTcpSocket::SocketState state) {
            switch (state) {
            case QTcpSocket::ConnectedState : {
                break;
            }
            case QTcpSocket::ConnectingState : {
                break;
            }
            case QTcpSocket::ClosingState : {
                break;
            }
            case QTcpSocket::HostLookupState : {
                break;
            }
            case QTcpSocket::ListeningState : {
                break;
            }
            case QTcpSocket::UnconnectedState : {
                break;
            }
            case QTcpSocket::BoundState : {
                break;
            }
            }
        });
    }
    socket->connectToHost(hostName, port, QIODevice::ReadWrite);
}
