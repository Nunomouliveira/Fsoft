//
// Created by migue on 09/06/2022.
//
#include "mockdata.h"
#include "DuplicatedDataException.h"


void  mockdata::insertClasses(ClassContainer& container){
    for (size_t  i = 0; i < this->n_classes.size();i++){
        Class obj(this->n_i_cla[i],this->n_classes[i]);
        try{
            container.add(obj);
        }catch(DuplicatedDataException& e){

        }
    }
}

void  mockdata::insertClients(ClientContainer& container){
    for (size_t i = 0; i < n_clients.size();i++){
        Client obj(n_clients[i],age[i]);
        container.add(obj);
    }
}

void  mockdata::insertEmployees(EmployeeContainer &container) {
    for (size_t i = 0; i < n_emp.size();i++){
        employee obj(n_i_emp[i],n_emp[i]);
        try{
            container.add(obj);
        }catch(DuplicatedDataException& e){

        }
    }
}

Class * mockdata::getRandomClass(ClassContainer &classes) {
    list<Class> listClass = classes.getAll();
    list<Class>::iterator it = listClass.begin();
    int is = rand() % listClass.size();
    for(int i = 0; i < is; i++){
        it++;
    }
    //it = it + is;
    string initials = it->getInitials();
    Class * ptr = classes.get(initials);
    return ptr;
}
void  mockdata::insertEnrolls(ClientContainer& clients, ClassContainer& classet, EnrollContainer & container){
    list<Client> listClient = clients.getAll();
    for(list<Client>::iterator it = listClient.begin(); it != listClient.end(); ++it){
        Client * client =  clients.get(it->getNumber());
        int n = 1 + rand() % ENROLLS_NR;
        for(int i = 0; i < n; i++){
            Class * classes = getRandomClass(classet);
            int grade = 10 + rand() % 11;
            try{
                Enroll enroll( classes, client);
                container.add(enroll);
            }catch (DuplicatedDataException& e){
            }

        }
    }
}
/*void  mockdata::insertFeedbackCla(ClientContainer& clients, ClassContainer& classet, FeedbackContainer & container){
    list<Client> listClient = clients.getAll();
    for(list<Client>::iterator it = listClient.begin(); it != listClient.end(); ++it){
        Client * client =  clients.get(it->getNumber());
        int n = 1 + rand() % FEEDBACK_NR;
        for(int i = 0; i < n; i++){
            Class * classes = getRandomClass(classet);
            int grade = 10 + rand() % 11;
            try{
                Feedback feedback(classes, client,feed[i]);
                container.add(feedback);
            }catch (DuplicatedDataException& e){
            }

        }
    }
}*/

void  mockdata::insertLecture(ClassContainer & classes, EmployeeContainer & employees ){
    list<employee> listEmployee = employees.getAll();
    for (list<employee>::iterator it=listEmployee.begin(); it != listEmployee.end(); ++it){
        employee * ptr = employees.get(it->getInitials());
        LectureContainer& container = ptr->getLectures();
        int n = 1 + rand() % LECTURES_NR;
        for(int i = 0; i < n; i++){
            Class * classet = getRandomClass(classes);
            try{
                Lecture lecture(classet);
                container.add(lecture);
            }catch (DuplicatedDataException& e){
            }
        }
    }
}

void  mockdata::generateData(gym& gym){
    srand (time(NULL));
    insertClasses(gym.getClassContainer());
    insertClients(gym.getClientContainer());
    insertEmployees(gym.getEmployeeContainer());
    insertEnrolls(gym.getClientContainer(), gym.getClassContainer(),gym.getEnrollContainer());
    insertLecture( gym.getClassContainer(), gym.getEmployeeContainer());



}


