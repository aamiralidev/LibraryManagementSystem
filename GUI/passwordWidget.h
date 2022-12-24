#ifndef CHECKPASSWORD_H
#define CHECKPASSWORD_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <string>



class PasswordWidget: public QWidget
{
    Q_OBJECT
private:
    QLabel *passLabel;
    QLineEdit *passEdit;
    QPushButton *passBtn;
    QVBoxLayout *passLayout;
    QMessageBox *passErr;

signals:
    void changeCurrentWidget();

public slots:
    void passBtnClicked();

public:
    PasswordWidget();
    ~PasswordWidget();
    void Design();
    void Signals_slots();
};

#endif // CHECKPASSWORD_H
