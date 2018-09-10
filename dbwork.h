#ifndef DBWORK_H
#define DBWORK_H

#include <QObject>
#include <QSqlDatabase>

class DbWork : public QObject
{
    Q_OBJECT
public:
    explicit DbWork(QObject *parent = nullptr);
    ~DbWork();

signals:

public slots:

private:
    QSqlDatabase *database {nullptr};

    void getData();
};

#endif // DBWORK_H
