#ifndef SOCKETWORK_H
#define SOCKETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>


class SocketWork : public QObject
{
    Q_OBJECT
public:
    explicit SocketWork(QObject *parent = nullptr);
    ~SocketWork();
    void initServer();
    void initSocket();

signals:

public slots:

private:
    QTcpServer *server {nullptr};
    QTcpSocket *socket {nullptr};
};

#endif // SOCKETWORK_H
