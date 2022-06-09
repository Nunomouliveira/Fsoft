//
// Created by nunon on 09/06/2022.
//

#ifndef FSOFT2022_1A_4_CLIENTVIEW_H
#define FSOFT2022_1A_4_CLIENTVIEW_H
#include <list>
#include "../model/client.h"

class ClientView{
public:

    Client getClient();
    void printClient(Client *client);
    void printClients(list<Client>& clients);
};

#endif //FSOFT2022_1A_4_CLIENTVIEW_H
