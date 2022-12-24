#include "subscriber.h"

using namespace std;

Subscriber::Subscriber()
{
    this->id = -1;
    this->type = false;
    this->name = "N/A";
    this->address = "N/A";
    this->phone = 0;
    this->email = "N/A";
}
Subscriber::Subscriber(int id,string name,bool type,string address,unsigned long int phone,string email)
{
    this->id = id;
    this->type = type;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->email = email;
}
void Subscriber::updateSubscriber(int id,string name,bool type,string address,unsigned long int phone,string email)
{
    this->id = id;
    this->type = type;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->email = email;
}

//=========getters========
Subscriber& Subscriber::setId(int ID)
{
    this->id = ID;
    return *this;
}
Subscriber& Subscriber::setType(bool TYPE)
{
    this->type = TYPE;
    return *this;
}
Subscriber& Subscriber::setName(string Name)
{
    this->name = Name;
    return *this;
}
Subscriber& Subscriber::setAddress(string Address)
{
    this->address = Address;
    return *this;
}
Subscriber& Subscriber::setPhone(unsigned long int Phone)
{
    this->phone = Phone;
    return *this;
}
Subscriber& Subscriber::setEmail(string Email)
{
    this->email = Email;
    return *this;
}

//=======setters========
int Subscriber::getId() const
{
    return this->id;
}
bool Subscriber::getType() const
{
    return this->type;
}
string Subscriber::getName() const
{
    return this->name;
}
string Subscriber::getAddress() const
{
    return this->address;
}
unsigned long int Subscriber::getPhone() const
{
    return this->phone;
}
string Subscriber::getEmail() const
{
    return this->email;
}

