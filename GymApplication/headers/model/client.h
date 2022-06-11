//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_CLIENT_H
#define GYMAPPLICATION_CLIENT_H
#include "person.h"
using namespace std;
class Client : public Person{
private:
    static int NUMBER;
    int number;
    string age;
public:
    Client(const string& name, const string& age);
    Client(const Client& client);
    ~Client();
    int getNumber() const ;
    void setNumber(int number);
    string getAge() const;
    void setAge(string age);
    bool operator == (const Client& obj) const;
    bool operator == (int nr) const;
    bool ValidAge(const string &age);
    bool operator == (const string name);
};


#endif //GYMAPPLICATION_CLIENT_H
