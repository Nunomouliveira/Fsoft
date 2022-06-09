//
// Created by migue on 09/06/2022.
//
#include "DuplicatedDataException.h"


DuplicatedDataException::DuplicatedDataException(string data){
    this->data = "Error: ["+ data + "] duplicated!!";
}

const char* DuplicatedDataException::what(){
    return this->data.c_str();
}

