#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include<QVariant>
#include<QSql>
#include<QSqlRecord>
#include "subscriber.h"
#include "library.h"
#include "content.h"
#include "transaction.h"

class Database
{
private:

public:
    Database();

    static QSqlDatabase db;

    bool init();
    //***** for inserting data into database
    bool saveContent(Content cnt);
    bool saveSubscriber(Subscriber sb);
    bool saveLibrary(Library lb);
    bool saveTransaction(Transaction tr);

    bool removeContent(int id);
    bool removeSubscriber(int id);
    bool removeLibrary(int id);

    bool updateContent(int id, Content ct);
    bool updateSubscriber(int id, Subscriber sb);
    bool updateLibrary(int id, Library lb);
    bool updateTransaction(Transaction prev, Transaction next);

    std::vector<Content*> loadContents();
    std::vector<Library*> loadLibraries();
    std::vector<Subscriber*> loadSubscribers();
    std::vector<Transaction*> loadTransactions();
};

#endif // DATABASE_H
