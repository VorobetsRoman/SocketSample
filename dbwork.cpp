#include "dbwork.h"
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlQuery>



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
        /*connect(database->driver(), &QSqlDriver::notification, [=] (QString notification){

        });*/
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
    QSqlQuery query(database);
    QString str {"select * from hz"};
    if (!query.exec) {
        throw "error executing request" + database->lastError().text();
    }
}



