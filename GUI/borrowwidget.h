#ifndef BORROWWIDGET_H
#define BORROWWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QRadioButton>
#include <QTabWidget>
#include <QPrintDialog>
#include <QPrinter>
#include <QDate>

#include <vector>
#include <fstream>
#include <ctime>

#include "transaction.h"
#include "subscriberwidget.h"
#include "contentwidget.h"
#include "librarywidget.h"
#include "database.h"


class BorrowWidget: public QWidget
{
    Q_OBJECT

private:

    Database db;

    QWidget *borrowWidget;
    QPushButton *addBtn, *removeBtn, *printBtn;
    QTreeWidget *borrowDetails;
    QTreeWidgetItem *itm;
    std::vector<Transaction*> borrowData;
    QVBoxLayout *borrowLayout;
    QHBoxLayout *btnLayout;

    SubscriberWidget *subscriberWidget;
    ContentWidget *contentWidget;
    LibraryWidget *libraryWidget;
    int subscriberId, contentId;
    bool subscriberType;

    QTabWidget *tabWidget;
    QVBoxLayout *tabLayout;


public:
    BorrowWidget();
    ~BorrowWidget();
    void Design();
    void Signals_slots();
    void initAddBorrowWidget();
    void initPrintBorrowWidget();
    void loadBorrowData();
    void loadBorrowDetails(QTreeWidget* treeWidget);
    void saveBorrowData();
    void saveData();

public slots:
    void addBorrowClicked();
    void selectSubscriberClicked(int subscriberId,bool subscriberType);
    void selectContentClicked(int contentId);
    void printBorrow();
    void removeBorrow();

};

#endif // BORROWWIDGET_H
