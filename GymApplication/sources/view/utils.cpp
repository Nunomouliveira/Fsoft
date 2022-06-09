//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "Utils.h"
#include <limits>
using namespace std;



int Utils::getNumber(const string&  label){
    int number;
    bool flag = false;
    do{
        cout<<label<<": ";
        flag = false;
        cin >> number;
        if(cin.fail()){
            cout << "That's not a number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = true;
        }
    }while(flag == true);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}
string Utils::getString(const string&  label){
    string input;
    cout<<label<<": ";
    getline (cin, input);
    return input;
}
