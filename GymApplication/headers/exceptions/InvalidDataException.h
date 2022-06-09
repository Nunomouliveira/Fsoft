//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_INVALIDDATAEXCEPTION_H
#define GYMAPPLICATION_INVALIDDATAEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class InvalidDataException :public exception{
private:
    string data;
public:
    InvalidDataException(string data);
    const char* what();
};


#endif //GYMAPPLICATION_INVALIDDATAEXCEPTION_H
