#include "socketwork.h"
#include <QTimer>

SocketWork::SocketWork(QObject *parent) : QObject(parent)
{
}

SocketWork::~SocketWork()
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

void SocketWork::initServer()
{
    server = new QTcpServer();
    QHostAddress hostAddress =  QHostAddress::LocalHost;
    quint16 ipPort {5050};

    if (server->listen(hostAddress, ipPort)) {
        connect(server, &QTcpServer::newConnection, [=] {
            socket = server->nextPendingConnection();
        });
    } else {
        throw "error" + server->errorString();
    }
}

void SocketWork::initSocket()
{

    QString hostName {"hostName"};
    quint16 port {5050};

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



