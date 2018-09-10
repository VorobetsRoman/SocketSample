#include "dbwork.h"
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QTime>
#include <QVariant>



DbWork::DbWork(QObject *parent) : QObject(parent)
{
    database = new QSqlDatabase();

    QString dbName {"fucking"};
    database->setDatabaseName(dbName);

    QString hostName {"127.0.0.1"};
    database->setHostName(hostName);

    int dbPort {5000};
    database->setPort(dbPort);

    QString dbUserName {"SashaGray"};
    database->setUserName(dbUserName);

    QString password {"allInclusive"};
    database->setPassword(password);

    if (!database->open()) {
        throw "error opening database:" + database->lastError().text();
    } else {
        database->driver()->subscribeToNotification(QString("time_to_sex"));
        connect(database->driver(), static_cast <void(QSqlDriver::*)(const QString&)>(&QSqlDriver::notification),
                [=] (QString notification) {
            if (notification == "time_to_sex") {
                //call Sasha Gray
            }
        });
    }
}



DbWork::~DbWork()
{
    if (database) {
        database->close();
        delete database;
    }
}



void DbWork::getData()
{
    QSqlQuery query(*database);
    QString str {"select * from hz"};
    if (!query.exec()) {
        throw "error executing request" + database->lastError().text();
    }

    query.prepare("INSERT INTO sasha_gray (partners_size, date)"
                  "VALUES (:length, :date);");
    query.bindValue(":length", QString::number(19));
    query.bindValue(":date", QTime::currentTime().toString(Qt::ISODate));

    if (!query.exec()) {
        throw "to small!";
    } else {
        query.first();
        do {
            QString str;
            str = query.value(0).toString();
        } while (query.next());

    }
}



