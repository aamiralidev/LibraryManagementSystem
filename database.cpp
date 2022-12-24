#include "database.h"

QSqlDatabase Database::db;

Database::Database(){

}

bool Database::init(){
//    cout<<path.toStdString();
//    QString Path = path + "/../../LibraryManagementSystem/LibMS.db";
//    Path.toStdString();
    Database::db = QSqlDatabase::addDatabase("QSQLITE");
    Database::db.setDatabaseName("LibMS.db");
    Database::db.open();
    if(!Database::db.isOpen())
    {
        return false;
    }
//    QString qry = QString::fromStdString(R"(SELECT * FROM items)");
//    QSqlQuery query(Database::db);
//    query.prepare(qry);
//    query.exec();
//    cout<<query.next();

    return true;
}

bool Database::saveContent(Content cnt){

    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO items\n VALUES(?,?,?,?,?,?,?,?,?);");
    query.bindValue(0, cnt.getItemId());
    query.bindValue(1, cnt.getLibraryId());
    query.bindValue(2, cnt.getCategory());
    query.bindValue(3, QString::fromStdString(cnt.getTitle()));
    query.bindValue(4, QString::fromStdString(cnt.getAuthor()));
    query.bindValue(5, QString::fromStdString(cnt.getPublisher()));
    query.bindValue(6, cnt.getProductionYear());
    query.bindValue(7, cnt.getStatus());
    query.bindValue(8, cnt.getCopies());
    query.exec();
    return true;

}

bool Database::saveLibrary(Library lb){

//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO library_\n VALUES(?,?);");
    query.bindValue(0, lb.getLibraryId());
    query.bindValue(1, QString::fromStdString(lb.getLibraryName()));
    query.exec();
    return true;
}

bool Database::saveSubscriber(Subscriber sb){

//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO subscriber\n VALUES(?,?,?,?,?,?);");
    query.bindValue(0, sb.getId());
    query.bindValue(1, sb.getType());
    query.bindValue(2, QString::fromStdString(sb.getName()));
    query.bindValue(3, QVariant::fromValue(sb.getPhone()));
    query.bindValue(4, QString::fromStdString(sb.getEmail()));
    query.bindValue(5, QString::fromStdString(sb.getAddress()));
    query.exec();
    return true;

}

bool Database::saveTransaction(Transaction tr){
//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("INSERT INTO borrow\n VALUES(?,?,?,?);");
    query.bindValue(0, tr.getSubscriberId());
    query.bindValue(1, tr.getContentId());
    query.bindValue(2, tr.getIssueDate());
    query.bindValue(3, tr.getReturnDate());
    query.exec();
    return true;

}

bool Database::removeContent(int id){

//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM items WHERE item_id=?;");
    query.bindValue(0, id);
    query.exec();
    return true;
}

bool Database::removeSubscriber(int id){
//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM subscriber WHERE sub_id=?;");
    query.bindValue(0, id);
    query.exec();
    return true;
}

bool Database::removeLibrary(int id){
//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("DELETE FROM library_ WHERE lib_id=?;");
    query.bindValue(0, id);
    query.exec();
    return true;
}

bool Database::updateContent(int id, Content cnt){

//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("UPDATE items SET item_id=?, lib_id=?, category=?, title=?, author=?"
                  ", publisher=?, pub_year=?, status_=?, copies=? WHERE item_id=?;");
    query.bindValue(0, cnt.getItemId());
    query.bindValue(1, cnt.getLibraryId());
    query.bindValue(2, cnt.getCategory());
    query.bindValue(3, QString::fromStdString(cnt.getTitle()));
    query.bindValue(4, QString::fromStdString(cnt.getAuthor()));
    query.bindValue(5, QString::fromStdString(cnt.getPublisher()));
    query.bindValue(6, cnt.getProductionYear());
    query.bindValue(7, cnt.getStatus());
    query.bindValue(8, cnt.getCopies());
    query.bindValue(9, id);
    query.exec();
    return true;
}

bool Database::updateSubscriber(int id, Subscriber sb){
//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("UPDATE subscriber SET sub_id=?, type_=?, name=?, mobile=?, email=?, address=? WHERE sub_id=?;");
    query.bindValue(0, sb.getId());
    query.bindValue(1, sb.getType());
    query.bindValue(2, QString::fromStdString(sb.getName()));
    query.bindValue(3, QVariant::fromValue(sb.getPhone()));
    query.bindValue(4, QString::fromStdString(sb.getEmail()));
    query.bindValue(5, QString::fromStdString(sb.getAddress()));
    query.bindValue(6, id);
    query.exec();
    return true;
}

bool Database::updateLibrary(int id, Library lb){
//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("UPDATE library_ SET lib_id=?, lib_name=? WHERE lib_id=?;");
    query.bindValue(0, lb.getLibraryId());
    query.bindValue(1, QString::fromStdString(lb.getLibraryName()));
    query.bindValue(2, id);
    query.exec();
    return true;
}

bool Database::updateTransaction(Transaction prev, Transaction tr){
//    db.open();
    QSqlQuery query(Database::db);
    query.prepare("UPDATE borrow SET sub_id=?, item_id=?, borrow_date=?, return_date=? WHERE sub_id=? AND item_id=?;");
    query.bindValue(0, tr.getSubscriberId());
    query.bindValue(1, tr.getContentId());
    query.bindValue(2, tr.getIssueDate());
    query.bindValue(3, tr.getReturnDate());
    query.bindValue(4, prev.getSubscriberId());
    query.bindValue(5, prev.getContentId());
    query.exec();
    return true;
}

std::vector<Content*> Database::loadContents(){
//    Database::db.open();
    std::vector<Content*> dta;
    Content* ct;
    QSqlQuery query(Database::db);
    query.prepare("SELECT * from items;");
    query.exec();
    while(query.next()){
        ct = new Content();
        ct->setItemId(query.value(0).toUInt());
        ct->setLibraryId(query.value(1).toUInt());
        ct->setCategory(query.value(2).toUInt());
        ct->setTitle(query.value(3).toString().toStdString());
        ct->setAuthor(query.value(4).toString().toStdString());
        ct->setPublisher(query.value(5).toString().toStdString());
        ct->setProductionYear(query.value(6).toUInt());
        ct->setStatus(query.value(7).toBool());
        ct->setCopies(query.value(8).toUInt());
        dta.push_back(ct);
    }
    return dta;
}

std::vector<Subscriber*> Database::loadSubscribers(){
//    Database::db.open();
    std::vector<Subscriber*> dta;
    Subscriber* sb;
    QSqlQuery query(Database::db);
    query.prepare("SELECT * from subscriber;");
    query.exec();
    while(query.next()){
        sb = new Subscriber();
        sb->setId(query.value(0).toUInt());
        sb->setType(query.value(1).toUInt());
        sb->setName(query.value(2).toString().toStdString());
        sb->setPhone(query.value(3).toULongLong());
        sb->setEmail(query.value(4).toString().toStdString());
        sb->setAddress(query.value(5).toString().toStdString());
        dta.push_back(sb);
    }
    return dta;
}

std::vector<Library*> Database::loadLibraries(){
//    Database::db.open();
    std::vector<Library*> dta;
    Library* lb;
    QSqlQuery query(Database::db);
    query.prepare("SELECT * from library;");
    query.exec();
    while(query.next()){
        lb = new Library();
        lb->setLibraryId(query.value(0).toUInt());
        lb->setLibraryName(query.value(1).toString().toStdString());
        dta.push_back(lb);
    }
    return dta;
}

std::vector<Transaction*> Database::loadTransactions(){
//    Database::db.open();
    std::vector<Transaction*> dta;
    Transaction* tr;
    QSqlQuery query(Database::db);
    query.prepare("SELECT * borrow;");
    query.exec();
    while(query.next()){
        tr = new Transaction();
        tr->setSubscriberId(query.value(0).toUInt());
        tr->setContentId(query.value(1).toUInt());
        tr->setIssueDate(query.value(2).toDate());
        tr->setReturnDate(query.value(3).toDate());
        dta.push_back(tr);
    }
    return dta;
}
