//
// Created by migue on 09/06/2022.
//

#include "InvalidDataException.h"


InvalidDataException::InvalidDataException(string data){
    this->data = data;
}

const char* InvalidDataException::what(){
    string msg = "Error: ["+ data + "] is not valid!!";
    return msg.c_str();
}

