#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

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

#include <vector>

#include "content.h"
#include "database.h"

class ContentWidget: public QWidget
{
    Q_OBJECT
public:
    ContentWidget();
    ~ContentWidget();
    void Design();
    void Signals_slots();
    void initAddContentWidget();
    void initEditContentWidget();
    void loadContentData();
    void loadContentDetails(QTreeWidget* treeWidget);
    void saveContentData();
    void showSelectContentWidget();
private:

    Database db;

    QTreeWidget *contentDetails;
    QVBoxLayout *contentLayout;
    std::vector<Content*> contentData;
    QPushButton *addBtn, *editBtn, *removeBtn;
    QHBoxLayout *btnLayout;


    QWidget *addContentWidget;
    QLabel *productionYear, *publisher, *author, *title, *itemId, *libraryId, *copies;
    QLineEdit *addItemId, *addLibraryId, *addTitle, *addAuthor, *addPublisher, *addProductionYear, *addCopies;
    QIntValidator *itemIdValidator, *libraryIdValidator, *productionYearValidator, *copiesValidator;
    QGridLayout *addContentLayout;
    QPushButton *addOkBtn;
    QRadioButton *addBook, *addArticle, *addDigitalMedia, *onShelf, *notAvailable;
    QHBoxLayout *categoryLayout;

    QWidget *editContentWidget;
    QLabel *eproductionYear, *epublisher, *eauthor, *etitle, *eitemId, *elibraryId, *ecopies;
    QLineEdit *editItemId, *editLibraryId, *editTitle, *editAuthor, *editPublisher, *editProductionYear, *editCopies;
    QIntValidator *eitemIdValidator, *elibraryIdValidator, *eproductionYearValidator, *ecopiesValidator;
    QGridLayout *editContentLayout;
    QPushButton *editOkBtn;
    QRadioButton *editBook, *editArticle, *editDigitalMedia, *editOnShelf, *editNotAvailable;
    QHBoxLayout *ecategoryLayout;

    QWidget *selectContentWidget;
    QPushButton *selectBtn;
    QTreeWidget *selectTreeWidget;
    QVBoxLayout *selectLayout;

public slots:
    void editContentClicked();
    void addContentClicked();
    void addContent();
    void editContent();
    void removeContent();
    void selectBtnClicked();

signals:
    void contentSelected(int);

};

#endif // BOOKWIDGET_H
