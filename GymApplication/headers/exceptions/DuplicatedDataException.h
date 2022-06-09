//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_DUPLICATEDDATAEXCEPTION_H
#define GYMAPPLICATION_DUPLICATEDDATAEXCEPTION_H
#include <exception>
#include <string>
using namespace std;

class DuplicatedDataException :public exception{
private:
    string data;
public:
    DuplicatedDataException(string data);
    //override what function
    const char* what();
};
#endif //GYMAPPLICATION_DUPLICATEDDATAEXCEPTION_H
