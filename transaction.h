#ifndef TRANSCTION_H
#define TRANSCTION_H

#include <QDate>

class Transaction
{
    QDate issueDate, returnDate;
    unsigned int subscriberId, contentId;
public:
    Transaction();
    Transaction(unsigned int subscriberId, unsigned int contentId, QDate issueDate, QDate returnDate);
    void updateTransactions(unsigned int subscriberId, unsigned int contentId, QDate issueDate, QDate returnDate);

    //======setters=======
    Transaction& setSubscriberId(unsigned int subscriberId);
    Transaction& setContentId(unsigned int contentId);
    Transaction& setIssueDate(QDate date);
    Transaction& setReturnDate(QDate date);
    Transaction& setIssueDate(int day, int month, int year);
    Transaction& setReturnDate(int day, int month, int year);

    //======getters========
    unsigned int getSubscriberId() const;
    unsigned int getContentId() const;
    QDate getIssueDate() const;
    QDate getReturnDate() const;
};

#endif // TRANSCTION_H
