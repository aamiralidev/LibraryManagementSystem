#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QStackedWidget>
#include <string>
#include <QVBoxLayout>

#include "indexs.h"
#include "passwordWidget.h"
#include "subscriberwidget.h"
#include "contentwidget.h"
#include "librarywidget.h"
#include "transaction.h"
#include "borrowwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
protected:
    void closeEvent(QCloseEvent *even);
public:
    ~MainWindow();
    void Design();
    void Signals_slots();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    PasswordWidget *loginWidget;
    BorrowWidget *borrowWidget;




signals:
    void closingWindow();

public slots:
    void alterCurrentWidget();

};
#endif // MAINWINDOW_H
