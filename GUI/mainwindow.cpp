#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QPalette>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Library Management System");
    this->setWindowIcon(QIcon(":/rsc/icons/logo.jpg"));
    this->resize(1000,600);

    Database db;
    db.init();

    QPixmap bkgnd(":/rsc/icons/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->stackedWidget = new QStackedWidget();
    this->loginWidget = new PasswordWidget();
    this->borrowWidget = new BorrowWidget();

    this->Design();
    this->setCentralWidget(this->stackedWidget);
    this->stackedWidget->setCurrentIndex(LOGIN_WIDGET);
    this->Signals_slots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Design()
{
    this->stackedWidget->addWidget(this->loginWidget);
    this->stackedWidget->addWidget(this->borrowWidget);
}

void MainWindow::Signals_slots()
{
    connect(this->loginWidget,SIGNAL(changeCurrentWidget()),this,SLOT(alterCurrentWidget()));
}


void MainWindow::alterCurrentWidget()
{
    this->stackedWidget->setCurrentIndex(BORROW_WIDGET);
}

void MainWindow::closeEvent(QCloseEvent *even)
{
    this->borrowWidget->saveData();
    qApp->quit();
}
