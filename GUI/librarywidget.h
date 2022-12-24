#ifndef LIBRARYWIDGET_H
#define LIBRARYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QIntValidator>

#include <vector>

#include "library.h"

class LibraryWidget: public QWidget
{
    Q_OBJECT
public:
    LibraryWidget();
    ~LibraryWidget();
    void Design();
    void Signals_slots();
    void initAddLibraryWidget();
    void initEditLibraryWidget();
    void loadLibraryData();
    void loadLibraryDetails();
    void saveLibraryData();

private:
    QTreeWidget *libraryDetails;
    QTreeWidgetItem *itm;
    QPushButton *addBtn, *editBtn, *removeBtn;
    QVBoxLayout *libraryLayout;
    QHBoxLayout *btnLayout;
    std::vector<Library*> libraryData;

    QWidget *addLibraryWidget;
    QLabel *libraryId, *libraryName;
    QLineEdit *addLibraryId, *addLibraryName;
    QGridLayout *addLibraryLayout;
    QPushButton *addOkBtn;
    QIntValidator *libraryIdValidator;

    QWidget *editLibraryWidget;
    QLabel *elibraryId, *elibraryName;
    QLineEdit *editLibraryId, *editLibraryName;
    QGridLayout *editLibraryLayout;
    QPushButton *editOkBtn;
    QIntValidator *elibraryIdValidator;

public slots:
    void editLibraryClicked();
    void addLibraryClicked();
    void addLibrary();
    void editLibrary();
    void removeLibrary();

};

#endif // LIBRARYWIDGET_H
