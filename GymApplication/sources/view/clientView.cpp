//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "clientView.h"
#include "utils.h"
#include "InvalidDataException.h"
using namespace std;




Client ClientView::getClient(){

    Client client("Name", 18);
    bool flag = false;
    string name;
    int age;
    do{
        try{
            flag = false;
            cout << "Enter Client Name: ";
            cin >> name;
            client.setName(name);
            cout << "Enter Client Age: ";
            cin >> age;
            client.setAge(age);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return client;
}

void ClientView::printClient(Client *client){
    cout<<client->getNumber()<<". "<<"Nome: "<<client->getName()<<" - "<<client->getAge()<<" anos"<<endl;
}
void ClientView::printClients(list<Client>& clients){
    for (list<Client>::iterator it=clients.begin(); it != clients.end(); ++it){
        printClient(&*it);
    }
}
