#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include<iostream>
using namespace std;

class Subscriber
{
private:
    int id;
    std::string name, address, email;
    bool type;
    unsigned long int phone;
public:
    Subscriber();
    Subscriber(int id,std::string name,bool type,std::string address,unsigned long int phone,std::string email);
    void updateSubscriber(int id,std::string name,bool type,std::string address,unsigned long int phone,std::string email);

    //========setters=======
    Subscriber& setId(int ID);
    Subscriber& setType(bool TYPE);
    Subscriber& setName(std::string Name);
    Subscriber& setAddress(std::string Address);
    Subscriber& setPhone(unsigned long int Phone);
    Subscriber& setEmail(std::string Email);

    //========getters========
    int getId() const;
    bool getType() const;
    std::string getName() const;
    std::string getAddress() const;
    unsigned long int getPhone() const;
    std::string getEmail() const;


};

#endif // SUBSCRIBER_H
