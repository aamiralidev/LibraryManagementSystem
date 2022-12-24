#include "transaction.h"

using namespace std;

Transaction::Transaction()
{

}
Transaction::Transaction(unsigned int subscriberId, unsigned int contentId, QDate issueDate, QDate returnDate)
{
    this->contentId = contentId;
    this->subscriberId = subscriberId;
    this->issueDate = issueDate;
    this->returnDate = returnDate;
}
void Transaction::updateTransactions(unsigned int subscriberId, unsigned int contentId, QDate issueDate, QDate returnDate)
{
    this->contentId = contentId;
    this->subscriberId = subscriberId;
    this->issueDate = issueDate;
    this->returnDate = returnDate;
}

//======setters=======
Transaction& Transaction::setSubscriberId(unsigned int subscriberId)
{
    this->subscriberId = subscriberId;
    return *this;
}
Transaction& Transaction::setContentId(unsigned int contentId)
{
    this->contentId = contentId;
    return *this;
}
Transaction& Transaction::setIssueDate(QDate date)
{
    this->issueDate = date;
    return *this;
}
Transaction& Transaction::setIssueDate(int day, int  month, int year)
{
    this->issueDate.setDate(year,month,day);
    return *this;
}
Transaction& Transaction::setReturnDate(int day,int month, int year)
{
    this->returnDate.setDate(year,month,day);
    return *this;
}
Transaction& Transaction::setReturnDate(QDate date)
{
    this->returnDate = date;
    return *this;
}

//======getters========
unsigned int Transaction::getSubscriberId() const
{
    return this->subscriberId;
}
unsigned int Transaction::getContentId() const
{
    return this->contentId;
}
QDate Transaction::getIssueDate() const
{
    return this->issueDate;
}
QDate Transaction::getReturnDate() const
{
    return this->returnDate;
}
