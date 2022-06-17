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
    int age;
public:
    Client(const string& name, int age);
    Client(const Client& client);
    ~Client();
    int getNumber() const ;
    int getAge() const;
    void setAge(int age);
    bool operator == (const Client& obj) const;
    bool operator == (int nr) const;
    bool ValidAge(int age);
};


#endif //GYMAPPLICATION_CLIENT_H
