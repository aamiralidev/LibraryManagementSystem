#ifndef SUBSCRIBERWIDGET_H
#define SUBSCRIBERWIDGET_H

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
#include <QIntValidator>

#include <vector>

#include "subscriber.h"
#include "database.h"

class SubscriberWidget: public QWidget
{
    Q_OBJECT
private:

    Database db;

    QTreeWidget *subscriberDetails;
    QVBoxLayout *subscriberLayout;
    std::vector<Subscriber*> subscriberData;
    QPushButton *addBtn, *editBtn, *removeBtn;
    QHBoxLayout *btnLayout;


    QWidget *addSubscriberWidget;
    QLabel *name, *address, *phone, *email, *id;
    QLineEdit *addName, *addAddress, *addPhone, *addEmail, *addId;
    QIntValidator *phoneValidator, *idValidator;
    QGridLayout *addSubscriberLayout;
    QPushButton *addOkBtn;
    QRadioButton *addGolden, *addRegular;

    QWidget *editSubscriberWidget;
    QLabel *ename, *eaddress, *ephone, *eemail, *eid;
    QLineEdit *editName, *editAddress, *editPhone, *editEmail, *editId;
    QIntValidator *ephoneValidator, *eidValidator;
    QGridLayout *editSubscriberLayout;
    QPushButton *editOkBtn;
    QRadioButton *editGolden, *editRegular;

    QWidget *selectSubscriberWidget;
    QPushButton *selectBtn;
    QTreeWidget *selectTreeWidget;
    QVBoxLayout *selectLayout;

signals:
    void subscriberSelected(int,bool);

public slots:
    void editSubscriberClicked();
    void addSubscriberClicked();
    void addSubscriber();
    void editSubscriber();
    void removeSubscriber();
    void selectBtnClicked();

public:
    SubscriberWidget();
    ~SubscriberWidget();
    void Design();
    void Signals_slots();
    void initAddSubscriberWidget();
    void initEditSubscriberWidget();
    void loadSubscriberData();
    void loadSubscriberDetails(QTreeWidget* treeWidget);
    void saveSubscriberData();
    void showSelectSubscriberWidget();

};

#endif // SUBSCRIBERWIDGET_H
