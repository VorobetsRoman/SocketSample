#ifndef SOCKETWORKWITHLIB_H
#define SOCKETWORKWITHLIB_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

class SocketWorkWithLib : public QObject
{
    Q_OBJECT
public:
    explicit SocketWorkWithLib(QObject *parent = nullptr);
    ~SocketWorkWithLib();
    void initServer();
    void initSocket();

signals:

public slots:

private:
    QTcpServer *server {nullptr};
    QTcpSocket *socket {nullptr};
};

#endif // SOCKETWORKWITHLIB_H
