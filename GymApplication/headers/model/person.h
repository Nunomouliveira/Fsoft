//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_PERSON_H
#define GYMAPPLICATION_PERSON_H
#include <string>

using namespace std;

class Person{
protected:
    string name;
    bool ValidName(const string& name);
public:
    Person(const string& name);
    Person(const Person& person);
    ~Person();
    const string& getName() const;
    void setName(const string &name);
};


#endif //GYMAPPLICATION_PERSON_H
