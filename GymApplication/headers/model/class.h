//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_CLASS_H
#define GYMAPPLICATION_CLASS_H
#include <string>
using namespace std;
class Class {
private:
    string initials;
    string denomination;
public:
    Class(string initials, string denomination);
    Class(const Class& obj);
    ~Class();
    const string& getDenomination() const;
    void setDenomination(const string &denomination);
    const string& getInitials() const;
    void setInitials(const string &initials);
    bool operator == (const Class& obj) const;
    bool operator == (const string& str) const;
    bool ValidInitials(const string& initials);
};

#endif //GYMAPPLICATION_CLASS_H
