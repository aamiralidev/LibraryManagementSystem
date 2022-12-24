#include "borrowwidget.h"
#include <QFileDialog>

using namespace  std;

BorrowWidget::BorrowWidget()
{
//    db.init();

    this->borrowWidget = new QWidget();
    this->tabWidget = new QTabWidget();
    this->tabLayout = new QVBoxLayout();

    this->subscriberWidget = new SubscriberWidget();
    this->contentWidget = new ContentWidget();
    this->libraryWidget = new LibraryWidget();

    this->borrowDetails = new QTreeWidget();
    this->borrowDetails->setColumnCount(6);

    this->itm = new QTreeWidgetItem();
    this->addBtn = new QPushButton("Borrow");
    this->printBtn = new QPushButton("Print Details");
    this->removeBtn = new QPushButton("Return");
    this->btnLayout = new QHBoxLayout();
    this->borrowLayout = new QVBoxLayout();

    this->Signals_slots();
    this->loadBorrowData();
    this->loadBorrowDetails(this->borrowDetails);
    this->Design();
}

BorrowWidget::~BorrowWidget()
{
}

void BorrowWidget::Design()
{
    this->btnLayout->addWidget(this->addBtn);
    this->btnLayout->addWidget(this->removeBtn);
    this->btnLayout->addWidget(this->printBtn);

    this->borrowLayout->addWidget(this->borrowDetails);
    this->borrowLayout->addLayout(this->btnLayout);
    this->borrowWidget->setLayout(this->borrowLayout);

    this->tabWidget->addTab(this->subscriberWidget, "Subscriber");
    this->tabWidget->addTab(this->contentWidget, "Content");
    this->tabWidget->addTab(this->libraryWidget, "Library");
    this->tabWidget->addTab(this->borrowWidget, "Borrow");
    this->tabLayout->addWidget(this->tabWidget);
    this->setLayout(this->tabLayout);
}


void BorrowWidget::Signals_slots()
{
    connect(this->subscriberWidget,SIGNAL(subscriberSelected(int,bool)),this,SLOT(selectSubscriberClicked(int,bool)));
    connect(this->contentWidget,SIGNAL(contentSelected(int)),this,SLOT(selectContentClicked(int)));
    connect(this->addBtn,SIGNAL(clicked()),this,SLOT(addBorrowClicked()));
    connect(this->removeBtn,SIGNAL(clicked()),this,SLOT(removeBorrow()));
    connect(this->printBtn,SIGNAL(clicked()),this,SLOT(printBorrow()));
}

void BorrowWidget::loadBorrowDetails(QTreeWidget* treeWidget)
{
    QTreeWidgetItem *itm;
    itm = new QTreeWidgetItem();
    itm->setText(0,"Subscriber ID");
    itm->setText(1,"Borrow Date");
    itm->setText(2,"Content Id");
    itm->setText(3,"Return Date");

    treeWidget->setHeaderHidden(true);
    treeWidget->addTopLevelItem(itm);
    QString cid, sid, idate, rdate;
    for(uint i=0; i<this->borrowData.size(); i++)
    {
        QTreeWidgetItem *item;
        item = new QTreeWidgetItem();
        cid = QString::number(this->borrowData[i]->getContentId());
        sid = QString::number(this->borrowData[i]->getSubscriberId());
        idate = this->borrowData[i]->getIssueDate().toString();
        rdate = this->borrowData[i]->getReturnDate().toString();

        item->setText(0,cid);
        item->setText(1,idate);
        item->setText(2,sid);
        item->setText(3,rdate);

        treeWidget->addTopLevelItem(item);
    }
}


void BorrowWidget::saveBorrowData()
{
    /*
    string fileName = "borrow.txt";
    ofstream out;
    out.open(fileName, ofstream::out | ofstream::trunc);
    for(unsigned int i=0; i < this->borrowData.size(); i++)
    {
        out<<this->borrowData[i]->getSubscriberId()<<" ";
        out<<this->borrowData[i]->getContentId()<<" ";
        out<<this->borrowData[i]->getIssueDate().day()<<" ";
        out<<this->borrowData[i]->getIssueDate().month()<<" ";
        out<<this->borrowData[i]->getIssueDate().year()<<" ";
        out<<this->borrowData[i]->getReturnDate().day()<<" ";
        out<<this->borrowData[i]->getReturnDate().month()<<" ";
        out<<this->borrowData[i]->getReturnDate().year()<<'\n';
    }
    out.close();
    */
}

void BorrowWidget::loadBorrowData()
{
    this->borrowData = db.loadTransactions();
    /*
    Transaction *tempBorrow;
    string fileName = "borrow.txt";
    ifstream inData;
    inData.open(fileName);
    if(!inData.is_open())
    {
        return;
    }
    int iday, imonth, iyear, rday, rmonth, ryear, isubscriberId, icontentId;
    while(!inData.eof() && inData.peek()!=fstream::traits_type::eof())
    {
        tempBorrow = new Transaction();
        inData>>isubscriberId>>icontentId>>iday>>imonth>>iyear>>rday>>rmonth>>ryear;
        inData.ignore();
        tempBorrow->setContentId(icontentId).setSubscriberId(isubscriberId).setIssueDate(QDate(iyear,imonth,iday)).setReturnDate(QDate(ryear,rmonth,rday));

        this->borrowData.push_back(tempBorrow);
    }
    inData.close();
    */
}

void BorrowWidget::addBorrowClicked()
{
    this->subscriberWidget->showSelectSubscriberWidget();
}
void BorrowWidget::selectSubscriberClicked(int subscriberId,bool subscriberType)
{
    this->subscriberId = subscriberId;
    this->subscriberType = subscriberType;
    this->contentWidget->showSelectContentWidget();
}
void BorrowWidget::selectContentClicked(int contentId)
{
    Transaction *tempTransaction;
    this->contentId = contentId;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    QDate *idate, *rdate;
    idate = new QDate();
    idate->setDate(timePtr->tm_year+1900,timePtr->tm_mon,timePtr->tm_mday);
    rdate = new QDate();
    if(this->subscriberType)
        *rdate = idate->addMonths(3);
    else
        *rdate = idate->addDays(21);
    tempTransaction = new Transaction(subscriberId, contentId, *idate, *rdate);
    this->borrowData.push_back(tempTransaction);

    db.saveTransaction(*tempTransaction);

    this->borrowDetails->clear();
    this->loadBorrowDetails(this->borrowDetails);
}


void BorrowWidget::removeBorrow()
{
    int index = (this->borrowDetails->currentIndex().row())-1;
    if(index<0)
    {
        QMessageBox::information(this,"error","Please select an entry from the list");
        return;
    }
    this->borrowData.erase(this->borrowData.begin()+index);
    this->borrowDetails->clear();
    this->loadBorrowDetails(this->borrowDetails);
}

void BorrowWidget::printBorrow()
{
    QPrinter* printer;
    printer = new QPrinter();
    QPrintDialog dialog(printer, this);
    dialog.setWindowTitle("Print Borrow History");
    if(dialog.exec() == QDialog::Rejected) return;
    QString dir = QFileDialog::getExistingDirectory(this,tr("Open Folder"),"/home",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QMessageBox::about(this,"Sorry","We yet don't know how to print.");
}

void BorrowWidget::saveData()
{/*
    this->saveBorrowData();
    this->subscriberWidget->saveSubscriberData();
    this->libraryWidget->saveLibraryData();
    this->contentWidget->saveContentData();
    */
}
