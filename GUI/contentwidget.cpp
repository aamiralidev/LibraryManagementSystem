#include "contentwidget.h"
#include <fstream>
#include <string>

using namespace std;

ContentWidget::ContentWidget()
{
    this->contentDetails = new QTreeWidget();
    this->contentDetails->setColumnCount(9);

    this->addBtn = new QPushButton("Add Content");
    this->editBtn = new QPushButton("Edit Content");
    this->removeBtn = new QPushButton("Remove Content");
    this->btnLayout = new QHBoxLayout();
    this->contentLayout = new QVBoxLayout();

    this->addContentWidget = new QWidget();
    this->addContentWidget->setWindowTitle("Add Content");
    this->itemId = new QLabel("Item Id");
    this->libraryId = new QLabel("Library Id");
    this->title = new QLabel("Title");
    this->author = new QLabel("Author");
    this->publisher = new QLabel("Publisher");
    this->productionYear = new QLabel("Production Year");
    this->copies = new QLabel("Copies");

    this->addItemId = new QLineEdit();
    this->addLibraryId = new QLineEdit();
    this->addTitle = new QLineEdit();
    this->addAuthor = new QLineEdit();
    this->addPublisher = new QLineEdit();
    this->addProductionYear = new QLineEdit();
    this->addCopies = new QLineEdit();
    this->itemIdValidator = new QIntValidator(0,10000000);
    this->libraryIdValidator = new QIntValidator(0,1000);
    this->productionYearValidator = new QIntValidator(0,1000);
    this->copiesValidator = new QIntValidator(0,100);
    this->addBook = new QRadioButton("Book");
    this->addArticle = new QRadioButton("Article");
    this->addDigitalMedia = new QRadioButton("Digital Media");
    this->onShelf = new QRadioButton("on shelf");
    this->notAvailable = new QRadioButton("not available");
    this->addOkBtn = new QPushButton("ok");
    this->addContentLayout = new QGridLayout();
    this->categoryLayout = new QHBoxLayout();

    this->editContentWidget = new QWidget();
    this->editContentWidget->setWindowTitle("Edit Content");
    this->eitemId = new QLabel("Item Id");
    this->elibraryId = new QLabel("Library Id");
    this->etitle = new QLabel("Title");
    this->eauthor = new QLabel("Author");
    this->epublisher = new QLabel("Publisher");
    this->eproductionYear = new QLabel("Production Year");
    this->ecopies = new QLabel("Copise");
    this->editItemId = new QLineEdit();
    this->editLibraryId = new QLineEdit();
    this->editTitle = new QLineEdit();
    this->editAuthor = new QLineEdit();
    this->editPublisher = new QLineEdit();
    this->editCopies = new QLineEdit();
    this->editProductionYear = new QLineEdit();
    this->eitemIdValidator = new QIntValidator(0,100000000);
    this->elibraryIdValidator = new QIntValidator(0,1000);
    this->ecopiesValidator = new QIntValidator(0,100);
    this->eproductionYearValidator = new QIntValidator(0,1000);
    this->editBook = new QRadioButton("Book");
    this->editArticle = new QRadioButton("Article");
    this->editDigitalMedia = new QRadioButton("Digital Media");
    this->editOnShelf = new QRadioButton("On Shelf");
    this->editNotAvailable = new QRadioButton("Not Available");
    this->editOkBtn = new QPushButton("ok");
    this->editContentLayout = new QGridLayout();
    this->ecategoryLayout = new QHBoxLayout();

    this->selectContentWidget = new QWidget();
    this->selectBtn = new QPushButton("Select");
    this->selectLayout = new QVBoxLayout();
    this->selectTreeWidget = new QTreeWidget();
    this->selectTreeWidget->setColumnCount(9);


    this->Signals_slots();
    this->loadContentData();
    this->loadContentDetails(this->contentDetails);
    this->initAddContentWidget();
    this->initEditContentWidget();
    this->Design();
}
ContentWidget::~ContentWidget()
{

}

void ContentWidget::Design()
{
    this->btnLayout->addWidget(this->addBtn);
    this->btnLayout->addWidget(this->editBtn);
    this->btnLayout->addWidget(this->removeBtn);

    this->contentLayout->addWidget(this->contentDetails);
    this->contentLayout->addLayout(this->btnLayout);
    this->setLayout(this->contentLayout);
}

void ContentWidget::Signals_slots()
{
    connect(this->addBtn,SIGNAL(clicked()),this,SLOT(addContentClicked()));
    connect(this->editBtn,SIGNAL(clicked()),this,SLOT(editContentClicked()));
    connect(this->addOkBtn,SIGNAL(clicked()),this,SLOT(addContent()));
    connect(this->editOkBtn,SIGNAL(clicked()),this,SLOT(editContent()));
    connect(this->removeBtn,SIGNAL(clicked()),this,SLOT(removeContent()));
    connect(this->selectBtn,SIGNAL(clicked()),this,SLOT(selectBtnClicked()));
}
void ContentWidget::initAddContentWidget()
{
    this->addItemId->setValidator(this->itemIdValidator);
    this->addLibraryId->setValidator(this->libraryIdValidator);
    this->addCopies->setValidator(this->copiesValidator);
    this->addProductionYear->setValidator(this->productionYearValidator);

    this->categoryLayout->addWidget(this->addBook);
    this->categoryLayout->addWidget(this->addArticle);
    this->categoryLayout->addWidget(this->addDigitalMedia);

    this->addContentLayout->addLayout(this->categoryLayout,0,0,2,0);
    this->addContentLayout->addWidget(this->libraryId,2,0);
    this->addContentLayout->addWidget(this->itemId,3,0);
    this->addContentLayout->addWidget(this->title,4,0);
    this->addContentLayout->addWidget(this->author,5,0);
    this->addContentLayout->addWidget(this->publisher,6,0);
    this->addContentLayout->addWidget(this->productionYear,7,0);
    this->addContentLayout->addWidget(this->copies,8,0);

    this->addContentLayout->addWidget(this->addLibraryId,2,1);
    this->addContentLayout->addWidget(this->addItemId,3,1);
    this->addContentLayout->addWidget(this->addTitle,4,1);
    this->addContentLayout->addWidget(this->addAuthor,5,1);
    this->addContentLayout->addWidget(this->addPublisher,6,1);
    this->addContentLayout->addWidget(this->addProductionYear,7,1);
    this->addContentLayout->addWidget(this->addCopies,8,1);
    this->addContentLayout->addWidget(this->onShelf,9,0);
    this->addContentLayout->addWidget(this->notAvailable,9,1);
    this->addContentLayout->addWidget(this->addOkBtn,10,0,2,0);

    this->addContentWidget->setLayout(this->addContentLayout);
}

void ContentWidget::initEditContentWidget()
{
    this->editItemId->setValidator(this->eitemIdValidator);
    this->editLibraryId->setValidator(this->elibraryIdValidator);
    this->editCopies->setValidator(this->ecopiesValidator);
    this->editProductionYear->setValidator(this->eproductionYearValidator);

    this->ecategoryLayout->addWidget(this->editBook);
    this->ecategoryLayout->addWidget(this->editArticle);
    this->ecategoryLayout->addWidget(this->editDigitalMedia);

    this->editContentLayout->addLayout(this->ecategoryLayout,0,0,2,0);
    this->editContentLayout->addWidget(this->elibraryId,2,0);
    this->editContentLayout->addWidget(this->eitemId,3,0);
    this->editContentLayout->addWidget(this->etitle,4,0);
    this->editContentLayout->addWidget(this->eauthor,5,0);
    this->editContentLayout->addWidget(this->epublisher,6,0);
    this->editContentLayout->addWidget(this->eproductionYear,7,0);
    this->editContentLayout->addWidget(this->ecopies,8,0);
    this->editContentLayout->addWidget(this->editLibraryId,2,1);
    this->editContentLayout->addWidget(this->editItemId,3,1);
    this->editContentLayout->addWidget(this->editTitle,4,1);
    this->editContentLayout->addWidget(this->editAuthor,5,1);
    this->editContentLayout->addWidget(this->editPublisher,6,1);
    this->editContentLayout->addWidget(this->editProductionYear,7,1);
    this->editContentLayout->addWidget(this->editCopies,8,1);
    this->editContentLayout->addWidget(this->editOnShelf,9,0);
    this->editContentLayout->addWidget(this->editNotAvailable,9,1);
    this->editContentLayout->addWidget(this->editOkBtn,10,0,2,0);

    this->editContentWidget->setLayout(this->editContentLayout);
}

void ContentWidget::loadContentDetails(QTreeWidget* treeWidget)
{
    QTreeWidgetItem *itm;
    itm = new QTreeWidgetItem();
    itm->setText(0,"Item Id");
    itm->setText(1,"Library Id");
    itm->setText(2,"Category");
    itm->setText(3,"Title");
    itm->setText(4,"Author");
    itm->setText(5,"Publisher");
    itm->setText(6,"Production Year");
    itm->setText(7,"Status");
    itm->setText(8,"Copies");

    treeWidget->setHeaderHidden(true);
    treeWidget->addTopLevelItem(itm);
    QString gtitle, gauthor, gpublisher, gitemId, glibraryId, gcategory, gproductionYear, gstatus, gcopies;
    for(uint i=0; i<this->contentData.size(); i++)
    {
        QTreeWidgetItem *item;
        item = new QTreeWidgetItem();
        gtitle = QString::fromStdString(this->contentData[i]->getTitle());
        gauthor = QString::fromStdString(this->contentData[i]->getAuthor());
        gpublisher = QString::fromStdString(this->contentData[i]->getPublisher());
        gitemId = QString::number(this->contentData[i]->getItemId());
        glibraryId = QString::number(this->contentData[i]->getLibraryId());
        gproductionYear = QString::number(this->contentData[i]->getProductionYear());
        gcopies = QString::number(this->contentData[i]->getCopies());

        if(this->contentData[i]->getStatus())
            gstatus = "on shelf";
        else
            gstatus = "not available";

        if(this->contentData[i]->getCategory()==1)
            gcategory = "Book";
        else if(this->contentData[i]->getCategory()==2)
            gcategory = "Artical";
        else
            gcategory = "Digital Media";

        item->setText(0,gitemId);
        item->setText(1,glibraryId);
        item->setText(2,gcategory);
        item->setText(3,gtitle);
        item->setText(4,gauthor);
        item->setText(5,gpublisher);
        item->setText(6,gproductionYear);
        item->setText(7,gstatus);
        item->setText(8,gcopies);

        treeWidget->addTopLevelItem(item);
    }
}
void ContentWidget::addContentClicked()
{
    this->addItemId->clear();
    this->addLibraryId->clear();
    this->addTitle->clear();
    this->addAuthor->clear();
    this->addPublisher->clear();
    this->addProductionYear->clear();
    this->addCopies->clear();
    this->addContentWidget->show();
}

void ContentWidget::editContentClicked()
{
    int index =(this->contentDetails->currentIndex().row())-1;
    if(index<0)
    {
        QMessageBox::information(this,"error","Please select and entry from the list");
        return;
    }
    this->editItemId->clear();
    this->editLibraryId->clear();
    this->editTitle->clear();
    this->editAuthor->clear();
    this->editPublisher->clear();
    this->editProductionYear->clear();
    this->editCopies->clear();
    this->editItemId->setPlaceholderText(QString::number(this->contentData[index]->getItemId()));
    this->editLibraryId->setPlaceholderText(QString::number(this->contentData[index]->getLibraryId()));
    this->editTitle->setPlaceholderText(QString::fromStdString(this->contentData[index]->getTitle()));
    this->editAuthor->setPlaceholderText(QString::fromStdString(this->contentData[index]->getAuthor()));
    this->editPublisher->setPlaceholderText(QString::fromStdString(this->contentData[index]->getPublisher()));
    this->editProductionYear->setPlaceholderText(QString::number(this->contentData[index]->getProductionYear()));
    this->editCopies->setPlaceholderText(QString::number(this->contentData[index]->getCopies()));
    this->editContentWidget->show();
}

void ContentWidget::addContent()
{
    Content *tempContent;
    bool tstatus;
    int tcategory;
    if(this->onShelf->isChecked())
        tstatus=true;
    else
        tstatus=false;

    if(this->addBook->isChecked())
        tcategory = 1;
    else if(this->addArticle->isChecked())
        tcategory = 2;
    else
        tcategory = 3;

    tempContent = new Content();
    tempContent->setItemId(this->addItemId->text().toInt());
    tempContent->setLibraryId(this->addLibraryId->text().toInt());
    tempContent->setProductionYear(this->addProductionYear->text().toInt());
    tempContent->setCopies(this->addCopies->text().toInt());
    tempContent->setTitle(this->addTitle->text().toStdString());
    tempContent->setAuthor(this->addAuthor->text().toStdString());
    tempContent->setPublisher(this->addPublisher->text().toStdString());
    tempContent->setStatus(tstatus);
    tempContent->setCategory(tcategory);
    this->contentData.push_back(tempContent);
    this->addContentWidget->hide();
    this->contentDetails->clear();
    this->loadContentDetails(this->contentDetails);
}

void ContentWidget::editContent()
{
    bool tstatus;
    int tcategory;
    int index=(this->contentDetails->currentIndex().row())-1;
    this->contentData[index]->setItemId(this->editItemId->text().toInt());
    this->contentData[index]->setLibraryId(this->editLibraryId->text().toInt());
    this->contentData[index]->setProductionYear(this->editProductionYear->text().toInt());
    this->contentData[index]->setCopies(this->editCopies->text().toInt());
    this->contentData[index]->setTitle(this->editTitle->text().toStdString());
    this->contentData[index]->setAuthor(this->editAuthor->text().toStdString());
    this->contentData[index]->setPublisher(this->editPublisher->text().toStdString());

    if(this->onShelf->isChecked())
        tstatus=true;
    else
        tstatus=false;

    if(this->editBook->isChecked())
        tcategory = 1;
    else if(this->editArticle->isChecked())
        tcategory = 2;
    else
        tcategory = 3;

    this->contentData[index]->setStatus(tstatus);
    this->contentData[index]->setCategory(tcategory);

    this->editContentWidget->hide();
    this->contentDetails->clear();
    this->loadContentDetails(contentDetails);
}

void ContentWidget::removeContent()
{
    int index=(this->contentDetails->currentIndex().row())-1;
    if(index<0)
    {
        QMessageBox::information(this,"error","Please an entry from the list");
        return;
    }
    this->contentData.erase(this->contentData.begin()+index-1);
    this->contentDetails->clear();
    this->loadContentDetails(this->contentDetails);
}

void ContentWidget::loadContentData()
{
    Content *tempContent;
    string fileName = "items.txt";
    ifstream inData;
    inData.open(fileName);
    if(!inData.is_open())
    {
        return;
    }
    string ititle, iauthor, ipublisher;
    unsigned int iitemId, ilibraryId, icategory, iproductionYear, icopies;
    bool istatus;
    while(!inData.eof() && inData.peek()!=fstream::traits_type::eof())
    {
        tempContent = new Content();
        inData>>iitemId>>ilibraryId>>icopies>>iproductionYear>>istatus>>icategory;
        inData.ignore();
        getline(inData,ititle,'\0');
        getline(inData,iauthor,'\0');
        getline(inData,ipublisher,'\0');
        inData.ignore();

        tempContent->setTitle(ititle).setAuthor(iauthor).setCopies(icopies).setItemId(iitemId).setStatus(istatus);
        tempContent->setStatus(icategory).setLibraryId(ilibraryId).setPublisher(ipublisher).setProductionYear(iproductionYear);

        this->contentData.push_back(tempContent);
    }
    inData.close();
}

void ContentWidget::saveContentData()
{
    string fileName = "items.txt";
    ofstream out;
    out.open(fileName, ofstream::out | ofstream::trunc);
    for(unsigned int i=0; i < this->contentData.size(); i++)
    {
        out<<this->contentData[i]->getItemId()<<" ";
        out<<this->contentData[i]->getLibraryId()<<" ";
        out<<this->contentData[i]->getCopies()<<" ";
        out<<this->contentData[i]->getProductionYear()<<" ";
        out<<this->contentData[i]->getStatus()<<" ";
        out<<this->contentData[i]->getCategory()<<" ";
        out<<this->contentData[i]->getTitle()<<'\0';
        out<<this->contentData[i]->getAuthor()<<'\0';
        out<<this->contentData[i]->getPublisher()<<'\0'<<'\n';
    }
    out.close();
}
void ContentWidget::showSelectContentWidget()
{
    this->selectContentWidget->setWindowTitle("Select Content");
    this->selectContentWidget->resize(800,400);
    this->selectTreeWidget->clear();
    this->loadContentDetails(this->selectTreeWidget);
    this->selectLayout->addWidget(this->selectTreeWidget);
    this->selectLayout->addWidget(this->selectBtn);
    this->selectContentWidget->setLayout(this->selectLayout);
    this->selectContentWidget->show();
}
void ContentWidget::selectBtnClicked()
{
    int index = (this->selectTreeWidget->currentIndex().row())-1;
    if(index<0)
    {
        QMessageBox::information(this,"error","Please select one entry");
        return;
    }
    emit contentSelected(this->contentData[index]->getItemId());
    this->selectContentWidget->hide();
}
