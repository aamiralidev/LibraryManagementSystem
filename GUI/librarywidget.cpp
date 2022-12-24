#include "librarywidget.h"
#include <fstream>

LibraryWidget::LibraryWidget()
{
//    db.init();

    this->libraryDetails = new QTreeWidget();
    this->libraryDetails->setColumnCount(2);
    this->addBtn = new QPushButton("Add Library");
    this->editBtn = new QPushButton("Edit Library");
    this->removeBtn = new QPushButton("Remove Library");
    this->libraryLayout = new QVBoxLayout();
    this->btnLayout = new QHBoxLayout();

    this->addLibraryWidget = new QWidget();
    this->libraryId = new QLabel("Library Id");
    this->libraryName = new QLabel("Library Name");
    this->addLibraryId = new QLineEdit();
    this->addLibraryName = new QLineEdit();
    this->addLibraryLayout = new QGridLayout();
    this->addOkBtn = new QPushButton("ok");
    this->libraryIdValidator = new QIntValidator(0,100);

    this->editLibraryWidget = new QWidget();
    this->elibraryId = new QLabel("Library Id");
    this->elibraryName = new QLabel("Library Name");
    this->editLibraryId = new QLineEdit();
    this->editLibraryName = new QLineEdit();
    this->editLibraryLayout = new QGridLayout();
    this->editOkBtn = new QPushButton("ok");
    this->elibraryIdValidator = new QIntValidator(0,100);

    this->loadLibraryData();
    this->loadLibraryDetails();
    this->initAddLibraryWidget();
    this->initEditLibraryWidget();
    this->Design();
    this->Signals_slots();
}

LibraryWidget::~LibraryWidget()
{

}

void LibraryWidget::Design()
{
    this->btnLayout->addWidget(this->addBtn);
    this->btnLayout->addWidget(this->editBtn);
    this->btnLayout->addWidget(this->removeBtn);

    this->libraryLayout->addWidget(this->libraryDetails);
    this->libraryLayout->addLayout(this->btnLayout);
    this->setLayout(this->libraryLayout);
}

void LibraryWidget::loadLibraryDetails()
{
    this->itm = new QTreeWidgetItem();
    this->itm->setText(0,"Library ID");
    this->itm->setText(1,"Library Name");

    this->libraryDetails->setHeaderHidden(true);
    this->libraryDetails->addTopLevelItem(this->itm);
    QString gname, gid;
    for(uint i=0; i<this->libraryData.size(); i++)
    {
        QTreeWidgetItem *item;
        item = new QTreeWidgetItem();
        gname = QString::number(this->libraryData[i]->getLibraryId());
        gid = QString::fromStdString(this->libraryData[i]->getLibraryName());

        item->setText(0,gname);
        item->setText(1,gid);

        this->libraryDetails->addTopLevelItem(item);
    }
}

void LibraryWidget::Signals_slots()
{
    connect(this->addBtn,SIGNAL(clicked()),this,SLOT(addLibraryClicked()));
    connect(this->editBtn,SIGNAL(clicked()),this,SLOT(editLibraryClicked()));
    connect(this->addOkBtn,SIGNAL(clicked()),this,SLOT(addLibrary()));
    connect(this->editOkBtn,SIGNAL(clicked()),this,SLOT(editLibrary()));
    connect(this->removeBtn,SIGNAL(clicked()),this,SLOT(removeLibrary()));
}

void LibraryWidget::initAddLibraryWidget()
{
    this->addLibraryId->setValidator(this->libraryIdValidator);

    this->addLibraryLayout->addWidget(this->libraryId,0,0);
    this->addLibraryLayout->addWidget(this->libraryName,1,0);
    this->addLibraryLayout->addWidget(this->addLibraryId,0,1);
    this->addLibraryLayout->addWidget(this->addLibraryName,1,1);
    this->addLibraryLayout->addWidget(this->addOkBtn,2,0,2,0);

    this->addLibraryWidget->setLayout(this->addLibraryLayout);
}

void LibraryWidget::initEditLibraryWidget()
{
    this->editLibraryId->setValidator(this->elibraryIdValidator);

    this->editLibraryLayout->addWidget(this->elibraryId,0,0);
    this->editLibraryLayout->addWidget(this->elibraryName,1,0);
    this->editLibraryLayout->addWidget(this->editLibraryId,0,1);
    this->editLibraryLayout->addWidget(this->editLibraryName,1,1);
    this->editLibraryLayout->addWidget(this->editOkBtn,2,0,2,0);

    this->editLibraryWidget->setLayout(this->editLibraryLayout);
}

void LibraryWidget::addLibraryClicked()
{
    this->addLibraryId->clear();
    this->addLibraryName->clear();
    this->addLibraryWidget->show();
}

void LibraryWidget::editLibraryClicked()
{
    int index =(this->libraryDetails->currentIndex().row())-1;
    if(index<0)
    {
        QMessageBox::information(this,"error","Please select and entry from the list");
        return;
    }
    this->editLibraryId->clear();
    this->editLibraryName->clear();
    this->editLibraryId->setPlaceholderText(QString::number(this->libraryData[index]->getLibraryId()));
    this->editLibraryName->setPlaceholderText(QString::fromStdString(this->libraryData[index]->getLibraryName()));

    this->editLibraryWidget->show();
}

void LibraryWidget::addLibrary()
{
    Library *tempLibrary;
    tempLibrary = new Library();
    tempLibrary->setLibraryId(this->addLibraryId->text().toInt());
    tempLibrary->setLibraryName(this->addLibraryName->text().toStdString());
    this->libraryData.push_back(tempLibrary);

    db.saveLibrary(*tempLibrary);

    this->addLibraryWidget->hide();
    this->libraryDetails->clear();
    this->loadLibraryDetails();
}

void LibraryWidget::editLibrary()
{
    int index=(this->libraryDetails->currentIndex().row())-1;
    int id = this->libraryData[index]->getLibraryId();
    this->libraryData[index]->setLibraryId(this->editLibraryId->text().toInt());
    this->libraryData[index]->setLibraryName(this->editLibraryName->text().toStdString());

    db.updateLibrary(id, *(this->libraryData[index]));

    this->editLibraryWidget->hide();
    this->libraryDetails->clear();
    this->loadLibraryDetails();
}

void LibraryWidget::removeLibrary()
{
    int index=(this->libraryDetails->currentIndex().row());
    if(index<0)
    {
        QMessageBox::information(this,"error","Please an entry from the list");
        return;
    }
    db.removeLibrary(this->libraryData[index]->getLibraryId());
    this->libraryData.erase(this->libraryData.begin()+index-1);
    this->libraryDetails->clear();
    this->loadLibraryDetails();
}

void LibraryWidget::loadLibraryData()
{
    this->libraryData = db.loadLibraries();
    /*
    Library *tempLibrary;
    string fileName = "library.txt";
    ifstream inData;
    inData.open(fileName);
    if(!inData.is_open())
    {
        return;
    }
    string iname;
    unsigned int iid;
    while(!inData.eof() && inData.peek()!=fstream::traits_type::eof())
    {
        tempLibrary = new Library();
        inData>>iid;
        getline(inData,iname,'\n');
        inData.ignore();
        tempLibrary->setLibraryId(iid).setLibraryName(iname);
        this->libraryData.push_back(tempLibrary);
    }
    inData.close();
    */
}

void LibraryWidget::saveLibraryData()
{
    /*
    string fileName = "library.txt";
    ofstream out;
    out.open(fileName, ofstream::out | ofstream::trunc);
    for(unsigned int i=0; i < this->libraryData.size(); i++)
    {
        out<<this->libraryData[i]->getLibraryId()<<" ";
        out<<this->libraryData[i]->getLibraryName()<<'\n';
    }
    out.close();
    */
}
