#include "subscriberwidget.h"
#include <fstream>

SubscriberWidget::SubscriberWidget()
{

//    db.init();
    this->subscriberDetails = new QTreeWidget();
    this->subscriberDetails->setColumnCount(6);

    this->addBtn = new QPushButton("Add Subscriber");
    this->editBtn = new QPushButton("Edit Subscriber");
    this->removeBtn = new QPushButton("Remove Subscriber");
    this->btnLayout = new QHBoxLayout();
    this->subscriberLayout = new QVBoxLayout();

    this->addSubscriberWidget = new QWidget();
    this->addSubscriberWidget->setWindowTitle("Add Subscriber");
    this->id = new QLabel("id");
    this->name = new QLabel("Name");
    this->address = new QLabel("Address");
    this->phone = new QLabel("Phone");
    this->email = new QLabel("Email");
    this->addId = new QLineEdit();
    this->addName = new QLineEdit();
    this->addEmail = new QLineEdit();
    this->addPhone = new QLineEdit();
    this->addAddress = new QLineEdit();
    this->phoneValidator = new QIntValidator(0,999999999);
    this->idValidator = new QIntValidator(0,10000000);
    this->addGolden = new QRadioButton("Golden");
    this->addRegular = new QRadioButton("Regular");
    this->addOkBtn = new QPushButton("ok");
    this->addSubscriberLayout = new QGridLayout();

    this->editSubscriberWidget = new QWidget();
    this->editSubscriberWidget->setWindowTitle("Edit Subscriber");
    this->eid = new QLabel("Id");
    this->ename = new QLabel("Name");
    this->eaddress = new QLabel("Address");
    this->ephone = new QLabel("Phone");
    this->eemail = new QLabel("Email");
    this->editId = new QLineEdit();
    this->editName = new QLineEdit();
    this->editEmail = new QLineEdit();
    this->editPhone = new QLineEdit();
    this->editAddress = new QLineEdit();
    this->ephoneValidator = new QIntValidator(0,99999999);
    this->eidValidator = new QIntValidator(0,10000000);
    this->editGolden = new QRadioButton("Golden");
    this->editRegular = new QRadioButton("Regular");
    this->editOkBtn = new QPushButton("ok");
    this->editSubscriberLayout = new QGridLayout();

    this->selectSubscriberWidget = new QWidget();
    this->selectLayout = new QVBoxLayout();
    this->selectBtn = new QPushButton("Select");
    this->selectTreeWidget = new QTreeWidget();
    this->selectTreeWidget->setColumnCount(6);

    this->Signals_slots();
    this->loadSubscriberData();
    this->loadSubscriberDetails(this->subscriberDetails);
    this->initAddSubscriberWidget();
    this->initEditSubscriberWidget();
    this->Design();
}
SubscriberWidget::~SubscriberWidget()
{

}

void SubscriberWidget::Design()
{
    this->btnLayout->addWidget(this->addBtn);
    this->btnLayout->addWidget(this->editBtn);
    this->btnLayout->addWidget(this->removeBtn);

    this->subscriberLayout->addWidget(this->subscriberDetails);
    this->subscriberLayout->addLayout(this->btnLayout);
    this->setLayout(this->subscriberLayout);
}

void SubscriberWidget::loadSubscriberDetails(QTreeWidget* treeWidget)
{
    QTreeWidgetItem *itm;
    itm = new QTreeWidgetItem();
    itm->setText(0,"Subscriber ID");
    itm->setText(1,"Name");
    itm->setText(2,"Type");
    itm->setText(3,"Address");
    itm->setText(4,"Phone");
    itm->setText(5,"EMail");

    treeWidget->setHeaderHidden(true);
    treeWidget->addTopLevelItem(itm);
    QString gname, gaddress, gphone, gemail, gtype;
    for(uint i=0; i<this->subscriberData.size(); i++)
    {
        QTreeWidgetItem *item;
        item = new QTreeWidgetItem();
        gname = QString::fromStdString(this->subscriberData[i]->getName());
        gaddress = QString::fromStdString(this->subscriberData[i]->getAddress());
        gemail = QString::fromStdString(this->subscriberData[i]->getEmail());
        gphone = QString::number(this->subscriberData[i]->getPhone());

        if(this->subscriberData[i]->getType())
            gtype = ":/rsc/icons/golden.png";
        else
            gtype = ":/rsc/icons/silver.png";

        item->setText(0,QString::number(this->subscriberData[i]->getId()));
        item->setText(1,gname);
        item->setIcon(2,QIcon(gtype));
        item->setText(3,gaddress);
        item->setText(4,gphone);
        item->setText(5,gemail);

        treeWidget->addTopLevelItem(item);
    }
}


void SubscriberWidget::Signals_slots()
{
    connect(this->addBtn,SIGNAL(clicked()),this,SLOT(addSubscriberClicked()));
    connect(this->editBtn,SIGNAL(clicked()),this,SLOT(editSubscriberClicked()));
    connect(this->addOkBtn,SIGNAL(clicked()),this,SLOT(addSubscriber()));
    connect(this->editOkBtn,SIGNAL(clicked()),this,SLOT(editSubscriber()));
    connect(this->removeBtn,SIGNAL(clicked()),this,SLOT(removeSubscriber()));
    connect(this->selectBtn,SIGNAL(clicked()),this,SLOT(selectBtnClicked()));
}

void SubscriberWidget::initAddSubscriberWidget()
{
    this->addId->setValidator(this->idValidator);
    this->addPhone->setValidator(this->phoneValidator);

    this->addSubscriberLayout->addWidget(this->id,0,0);
    this->addSubscriberLayout->addWidget(this->name,1,0);
    this->addSubscriberLayout->addWidget(this->address,2,0);
    this->addSubscriberLayout->addWidget(this->phone,3,0);
    this->addSubscriberLayout->addWidget(this->email,4,0);
    this->addSubscriberLayout->addWidget(this->addId,0,1);
    this->addSubscriberLayout->addWidget(this->addName,1,1);
    this->addSubscriberLayout->addWidget(this->addAddress,2,1);
    this->addSubscriberLayout->addWidget(this->addPhone,3,1);
    this->addSubscriberLayout->addWidget(this->addEmail,4,1);
    this->addSubscriberLayout->addWidget(this->addGolden,5,0);
    this->addSubscriberLayout->addWidget(this->addRegular,5,1);
    this->addSubscriberLayout->addWidget(this->addOkBtn,6,0,2,0);

    this->addSubscriberWidget->setLayout(this->addSubscriberLayout);
}

void SubscriberWidget::initEditSubscriberWidget()
{
    this->editId->setValidator(this->eidValidator);
    this->editPhone->setValidator(this->ephoneValidator);

    this->editSubscriberLayout->addWidget(this->eid,0,0);
    this->editSubscriberLayout->addWidget(this->ename,1,0);
    this->editSubscriberLayout->addWidget(this->eaddress,2,0);
    this->editSubscriberLayout->addWidget(this->ephone,3,0);
    this->editSubscriberLayout->addWidget(this->eemail,4,0);
    this->editSubscriberLayout->addWidget(this->editId,0,1);
    this->editSubscriberLayout->addWidget(this->editName,1,1);
    this->editSubscriberLayout->addWidget(this->editAddress,2,1);
    this->editSubscriberLayout->addWidget(this->editPhone,3,1);
    this->editSubscriberLayout->addWidget(this->editEmail,4,1);
    this->editSubscriberLayout->addWidget(this->editGolden,5,0);
    this->editSubscriberLayout->addWidget(this->editRegular,5,1);
    this->editSubscriberLayout->addWidget(this->editOkBtn,6,0,2,0);

    this->editSubscriberWidget->setLayout(this->editSubscriberLayout);
}

void SubscriberWidget::addSubscriberClicked()
{
    this->addId->clear();
    this->addName->clear();
    this->addAddress->clear();
    this->addEmail->clear();
    this->addPhone->clear();
    this->addSubscriberWidget->show();
}

void SubscriberWidget::editSubscriberClicked()
{
    int index =(this->subscriberDetails->currentIndex().row())-1;
    if(index<0)
    {
        QMessageBox::information(this,"error","Please select and entry from the list");
        return;
    }
    this->editId->clear();
    this->editName->clear();
    this->editAddress->clear();
    this->editEmail->clear();
    this->editPhone->clear();
    this->editId->setPlaceholderText(QString::number(this->subscriberData[index]->getId()));
    this->editName->setPlaceholderText(QString::fromStdString(this->subscriberData[index]->getName()));
    this->editAddress->setPlaceholderText(QString::fromStdString(this->subscriberData[index]->getAddress()));
    this->editEmail->setPlaceholderText(QString::fromStdString(this->subscriberData[index]->getEmail()));
    this->editPhone->setPlaceholderText(QString::number(this->subscriberData[index]->getPhone()));
    this->editSubscriberWidget->show();
}

void SubscriberWidget::addSubscriber()
{
    Subscriber *tempSubscriber;
    bool type;
    if(this->addGolden->isChecked())
        type=true;
    else
        type=false;
    tempSubscriber = new Subscriber();
    tempSubscriber->setId(this->addId->text().toInt());
    tempSubscriber->setName(this->addName->text().toStdString());
    tempSubscriber->setEmail(this->addEmail->text().toStdString());
    tempSubscriber->setAddress(this->addAddress->text().toStdString());
    tempSubscriber->setPhone(this->addPhone->text().toULong());
    tempSubscriber->setType(type);
    this->subscriberData.push_back(tempSubscriber);
    db.saveSubscriber(*tempSubscriber);
    this->addSubscriberWidget->hide();
    this->subscriberDetails->clear();
    this->loadSubscriberDetails(this->subscriberDetails);
}

void SubscriberWidget::editSubscriber()
{
    bool etype;
    int index=(this->subscriberDetails->currentIndex().row())-1;
    int id = this->subscriberData[index]->getId();
    this->subscriberData[index]->setId(this->editId->text().toInt());
    this->subscriberData[index]->setName(this->editName->text().toStdString());
    this->subscriberData[index]->setEmail(this->editEmail->text().toStdString());
    this->subscriberData[index]->setAddress(this->editAddress->text().toStdString());
    if(this->editGolden->isChecked())
        etype=true;
    else
        etype=false;
    this->subscriberData[index]->setType(etype);
    this->subscriberData[index]->setPhone(this->editPhone->text().toULong());

    db.updateSubscriber(id, *(this->subscriberData[index]));

    this->editSubscriberWidget->hide();
    this->subscriberDetails->clear();
    this->loadSubscriberDetails(this->subscriberDetails);
}

void SubscriberWidget::removeSubscriber()
{
    int index=(this->subscriberDetails->currentIndex().row())-1;
    if(index<0)
    {
        QMessageBox::information(this,"error","Please an entry from the list");
        return;
    }
    db.removeSubscriber(this->subscriberData[index]->getId());
    this->subscriberData.erase(this->subscriberData.begin()+index);
    this->subscriberDetails->clear();
    this->loadSubscriberDetails(this->subscriberDetails);
}

void SubscriberWidget::loadSubscriberData()
{
    this->subscriberData = db.loadSubscribers();

    /*
    Subscriber *tempSubscriber;


    string fileName = "subscriber.txt";
    ifstream inData;
    inData.open(fileName);
    if(!inData.is_open())
    {
        return;
    }
    string iname, iaddress, iemail;
    unsigned int iid;
    unsigned long int iphone;
    bool itype;
    while(!inData.eof() && inData.peek()!=fstream::traits_type::eof())
    {
        tempSubscriber = new Subscriber();
        inData>>iid>>iphone>>itype;
        inData.ignore();
        getline(inData,iname,'\0');
        getline(inData,iaddress,'\0');
        getline(inData,iemail,'\0');
        inData.ignore();

        tempSubscriber->setId(iid).setName(iname).setType(itype).setEmail(iemail).setAddress(iaddress).setPhone(iphone);

        this->subscriberData.push_back(tempSubscriber);
    }
    inData.close();
    */
}

void SubscriberWidget::saveSubscriberData()
{
    /*
    string fileName = "subscriber.txt";
    ofstream out;
    out.open(fileName, ofstream::out | ofstream::trunc);
    for(unsigned int i=0; i < this->subscriberData.size(); i++)
    {
        out<<this->subscriberData[i]->getId()<<" ";
        out<<this->subscriberData[i]->getPhone()<<" ";
        out<<this->subscriberData[i]->getType()<<" ";
        out<<this->subscriberData[i]->getName()<<'\0';
        out<<this->subscriberData[i]->getAddress()<<'\0';
        out<<this->subscriberData[i]->getEmail()<<'\0'<<'\n';
    }
    out.close();
    */
}

void SubscriberWidget::showSelectSubscriberWidget()
{
    this->selectSubscriberWidget->setWindowTitle("Select Subscriber");
    this->selectSubscriberWidget->resize(800,400);
    this->selectTreeWidget->clear();
    this->loadSubscriberDetails(this->selectTreeWidget);
    this->selectLayout->addWidget(this->selectTreeWidget);
    this->selectLayout->addWidget(this->selectBtn);
    this->selectSubscriberWidget->setLayout(this->selectLayout);
    this->selectSubscriberWidget->show();
}
void SubscriberWidget::selectBtnClicked()
{
    int index = (this->selectTreeWidget->currentIndex().row())-1;
    if(index<0)
        QMessageBox::information(this,"error","Please select one entry");
    else{
        emit subscriberSelected(this->subscriberData[index]->getId(),this->subscriberData[index]->getType());
        this->selectSubscriberWidget->hide();
    }
}

