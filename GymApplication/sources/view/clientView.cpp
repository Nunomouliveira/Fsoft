//
// Created by nunon on 09/06/2022.
//

#include <iostream>
#include "clientView.h"
#include "Utils.h"
#include "InvalidDataException.h"
using namespace std;

Client ClientView::getClient(){

    Client client("Name", "age");
    bool flag = false;
    do{
        try{
            flag = false;
            cout<<"Client"<<endl;
            string name = Utils::getString("Name ");
            client.setName(name);
            int age = Utils::getNumber("Age ");
            client.setAge(age);
        }catch(InvalidDataException& e){
            flag = true;
        }
    }while(flag == true);
    return client;
}

void ClientView::printClient(Client *client){
    cout<<client->getNumber()<<"-"<<"Nome: "<<client->getName()<<":"<<client->getAge()<<" anos"<<endl;
}
void ClientView::printClients(list<Client>& clients){
    for (list<Client>::iterator it=clients.begin(); it != clients.end(); ++it){
        printClient(&*it);
    }
}
