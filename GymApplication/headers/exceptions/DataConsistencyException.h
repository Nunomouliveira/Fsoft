//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_DATACONSISTENCYEXCEPTION_H
#define GYMAPPLICATION_DATACONSISTENCYEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class DataConsistencyException :public exception{
private:
    string data;
public:
    DataConsistencyException(string data);
    const char* what();
};

#endif //GYMAPPLICATION_DATACONSISTENCYEXCEPTION_H
