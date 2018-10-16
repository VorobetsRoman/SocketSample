#include "dbworkwithlib.h"
#include "appsettings.h"
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QTime>
#include <QVariant>




//========================================
DbWorkWithLib::DbWorkWithLib(QObject *parent) : QObject(parent)
{
    database = new QSqlDatabase();

    database->setDatabaseName(AppSettings::settingsValue("database/dbName", "database").toString());
    database->setHostName(AppSettings::settingsValue("database/dbAddress", "127.0.0.1").toString());
    database->setPort(AppSettings::settingsValue("database/dbPort", 5000).toInt());
    database->setUserName(AppSettings::settingsValue("database/userName", "userName").toString());
    database->setPassword(AppSettings::settingsValue("database/userPassword", "12345678").toString());

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




//========================================
DbWorkWithLib::~DbWorkWithLib()
{
    if (database) {
        database->close();
        delete database;
    }
}




//========================================
void DbWorkWithLib::getData()
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
