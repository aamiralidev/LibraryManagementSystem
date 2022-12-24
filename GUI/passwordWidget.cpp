#include "passwordWidget.h"

using namespace std;

PasswordWidget::PasswordWidget()
{
    this->passLabel = new QLabel("Enter your password");
    this->passEdit = new QLineEdit(); this->passEdit->setEchoMode(QLineEdit::Password);
    this->passBtn = new QPushButton("ok");
    this->passLayout = new QVBoxLayout();
    this->passErr = new QMessageBox(); this->passErr->setWindowTitle("Password Error"); this->passErr->setWindowIcon(QIcon(":/rsc/icons/error.png"));
    this->Design();
    this->Signals_slots();
}
PasswordWidget::~PasswordWidget()
{

}

void PasswordWidget::Design()
{
    this->passLayout->addWidget(this->passLabel);
    this->passLayout->addWidget(this->passEdit);
    this->passLayout->addWidget(this->passBtn);
    this->setMaximumWidth(200);
    this->setMaximumHeight(100);
    this->setLayout(this->passLayout);
}

void PasswordWidget::Signals_slots()
{
    connect(this->passBtn,SIGNAL(clicked()),this,SLOT(passBtnClicked()));
}

void PasswordWidget::passBtnClicked()
{
    if(this->passEdit->text().toStdString()=="")
    {
        this->passErr->setText("password can't be empty");
        this->passErr->show();
    }
    else
    {
        if(this->passEdit->text().toStdString()=="admin")
        {
            emit changeCurrentWidget();
        }
        else
            QMessageBox::critical(this,"Password Error","Password you entered is not write");
    }
}
