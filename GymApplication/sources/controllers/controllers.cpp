#include <iostream>
#include <string>
#include "controller.h"
#include "utils.h"
#include "DataConsistencyException.h"
using namespace std;

Controller::Controller(gym& gym){
    this->model = gym;
}
void Controller::run(){
    int op = -1;
    do{
        op=this->view.menuGym();
        switch(op){
            case 1:runClients();
                break;
            case 2:runEmployees();
                break;
            case 3:runClasses();
                break;
            case 4:runEnrolls();
                break;
            default:
                break;
        }
    }while(op!=0);

}
void Controller::runClients() {
    int op = -1;
    do{
        op = this->view.menuClients();

        switch(op){
            case 1:	{
                Client client = this->clientView.getClient();
                ClientContainer& container = this->model.getClientContainer();
                container.add(client);
            }
                break;
            case 2:{
                int number = Utils::getNumber("Enter the Client Number");
                ClientContainer& container = this->model.getClientContainer();
                Client * ptr = container.get(number);
                if(ptr != NULL){
                    this->clientView.printClient(ptr);
                }else{
                    cout<<"Client does not exist."<<endl;
                }
            }
                break;
            case 3:{
                try{
                    int number = Utils::getNumber("Enter the Client Number");
                    ClientContainer& container = this->model.getClientContainer();
                    container.remove(number);
                }catch(DataConsistencyException& e){
                    string str(e.what());
                    cout<<str<<endl;
                }
            }
                break;
            case 4:
            {
                cout<<this->model.getName()<<endl;
                ClientContainer container = this->model.getClientContainer();
                list<Client> clients = container.getAll();
                this->clientView.printClients(clients);
            }
                break;
            default:
                break;
        }
    }while(op!=0);
}
void Controller::runEmployees() {

    int op = -1;
    do {
        op = this->view.menuEmployees();
        switch (op) {
            case 1: {
                employee employee = this->employeeView.getEmployee();
                EmployeeContainer &container = this->model.getEmployeeContainer();
                container.add(employee);
            }
                break;
            case 2: {
                string initials = Utils::getString("Enter the Employee Initials");
                EmployeeContainer &container = this->model.getEmployeeContainer();
                employee *ptr = container.get(initials);
                if (ptr != NULL) {
                    this->employeeView.printEmployee(ptr);
                } else {
                    cout << "Employee does not exist." << endl;
                }
            }
                break;
            case 3: {
                try {
                    string initials = Utils::getString("Enter the Employee Initials");
                    EmployeeContainer &container = this->model.getEmployeeContainer();
                    container.remove(initials);
                } catch (DataConsistencyException &e) {
                    string str(e.what());
                    cout << str << endl;
                }
            }
                break;
            case 4: {
                cout << this->model.getName() << endl;
                EmployeeContainer container = this->model.getEmployeeContainer();
                list<employee> employees = container.getAll();
                this->employeeView.printEmployees(employees);

            }
                break;
            case 5:
                runLectures();
                break;
                /*case 6:
                    runEmployeesFeedback();
                    break;*/
            default:
                break;
        }
    } while (op != 0);
}
void Controller::runClasses() {
    int op = -1;
    do{
        op = this->view.menuClasses();

        switch(op){
            case 1:	{
                Class classes = this->classView.getClass();
                ClassContainer& container = this->model.getClassContainer();
                container.add(classes);
            }
                break;
            case 2:{
                string initials = Utils::getString("Enter the Class Initials");
                ClassContainer& container = this->model.getClassContainer();
                Class * ptr = container.get(initials);
                if(ptr != NULL){
                    this->classView.printClass(ptr);
                }else{
                    cout<<"Class does not exist."<<endl;
                }
            }
                break;
            case 3:{
                try{
                    string initials = Utils::getString("Enter the Class Initials");
                    ClassContainer& container = this->model.getClassContainer();
                    container.remove(initials);
                }catch(DataConsistencyException& e){
                    string str(e.what());
                    cout<<str<<endl;
                }
            }
                break;
            case 4:
            {
                cout << this->model.getName() << endl;
                ClassContainer container = this->model.getClassContainer();
                list<Class> classes = container.getAll();
                this->classView.printClasses(classes);

            }
                break;
                /*case 5: runClassesFeedback();
                    break;*/
            default:
                break;
        }
    }while(op!=0);
}
void Controller::runEnrolls(){
    int op = -1;
    do{
        op = this->view.menuEnrolls();

        switch(op){
            case 1:	{
                Enroll enroll = this->enrollView.getEnroll(this->model.getClientContainer(), this->model.getClassContainer());
                EnrollContainer& container = this->model.getEnrollContainer();
                container.add(enroll);
            }
                break;
            case 2:{
                int number = Utils::getNumber("Enter Client IDNumber");
                string denomination = Utils::getString("Enter Class Initials");
                EnrollContainer& container = this->model.getEnrollContainer();
                Enroll * ptr = container.get(number, denomination);
                if(ptr != NULL){
                    this->enrollView.printEnroll(ptr);
                }else{
                    cout<<"Enroll does not exist."<<endl;
                }
            }
                break;
            case 3:{
                try{
                    int number = Utils::getNumber("Enter Client Number");
                    string denomination = Utils::getString("Enter Class Initials");
                    EnrollContainer& container = this->model.getEnrollContainer();
                    container.remove(number, denomination);
                }catch(DataConsistencyException& e){
                    string str(e.what());
                    cout<<str<<endl;
                }
            }
                break;
            case 4:
            {
                cout<<this->model.getName()<<endl;
                EnrollContainer container = this->model.getEnrollContainer();
                list<Enroll> enrolls = container.getAll();
                this->enrollView.printEnrolls(enrolls);

            }
                break;


            default:
                break;
        }
    }while(op!=0);
}
void Controller::runLectures(){
    int op = -1;
    do{
        op = this->view.menuLectures();

        switch(op){
            case 1:	{
                string name = Utils::getString("Enter the Employee Initials");
                EmployeeContainer& container = this->model.getEmployeeContainer();
                employee * employee = container.get(name);
                if(employee != NULL){
                    Lecture lecture = this->lectureView.getLecture(this->model.getClassContainer());
                    LectureContainer& container1 = employee->getLectures();
                    container1.add(lecture);
                }else{
                    cout<<"Employee does not exist."<<endl;
                }
            }
                break;
            case 2:{
                string name = Utils::getString("Enter the Employee Initials");
                EmployeeContainer& container = this->model.getEmployeeContainer();
                employee * employee = container.get(name);
                if(employee != NULL){
                    string denomination1 = Utils::getString("Enter the Class Initials");
                    LectureContainer& container1 = employee->getLectures();
                    container1.remove(denomination1);
                }else{
                    cout<<"Employee does not exist."<<endl;
                }
            }
                break;
            case 3:	{
                string name = Utils::getString("Enter the Employee Initials");
                EmployeeContainer& container = this->model.getEmployeeContainer();
                employee * employee = container.get(name);
                if(employee != NULL){
                    LectureContainer& container1 = employee->getLectures();
                    list<Lecture> listLecture = container1.getAll();
                    this->lectureView.printLectures(employee, listLecture);
                }else{
                    cout<<"Employee does not exist."<<endl;
                }
            }
                break;



            default:
                break;
        }
    }while(op!=0);
}//
// Created by raulr on 09/06/2022.
//

