//
// Created by migue on 09/06/2022.
//
#include "DataConsistencyException.h"


DataConsistencyException::DataConsistencyException(string data){
    this->data = "Error: ["+ data + "] consistency!!";
}

const char* DataConsistencyException::what(){
    return this->data.c_str();
}


