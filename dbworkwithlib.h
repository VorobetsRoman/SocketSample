#ifndef DBWORKWITHLIB_H
#define DBWORKWITHLIB_H

#include <QObject>
#include <QSqlDatabase>

class DbWorkWithLib : public QObject
{
    Q_OBJECT
public:
    explicit DbWorkWithLib(QObject *parent = nullptr);
    ~DbWorkWithLib();

signals:

public slots:

private:
    QSqlDatabase *database {nullptr};

    void getData();
};

#endif // DBWORKWITHLIB_H
