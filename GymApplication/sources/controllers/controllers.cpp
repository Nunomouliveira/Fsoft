//
// Created by raulr on 09/06/2022.
//
#include <iostream>
#include <string>
#include "controllers.h"
#include "utils.h"
#include "DataConsistencyException.h"
using namespace std;

Controller::Controller(Gym& gym){
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
            case 5:runFeedback();
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
                Client* client = container.get(number);
                if(client != NULL){
                    this->clientView.printClient(client);
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
                Employee employee = this->employeeView.getEmployee();
                EmployeeContainer &container = this->model.getEmployeeContainer();
                container.add(employee);
            }
                break;
            case 2: {
                string initials = Utils::getString("Enter the Employee Initials");
                EmployeeContainer &container = this->model.getEmployeeContainer();
                Employee* employee = container.get(initials);
                if (employee != NULL) {
                    this->employeeView.printEmployee(employee);
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
                EmployeeContainer container = this->model.getEmployeeContainer();
                list<Employee> employees = container.getAll();
                this->employeeView.printEmployees(employees);
            }
                break;
            case 5:
                runLectures();
                break;
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
                Class* classes = container.get(initials);
                if(classes != NULL){
                    this->classView.printClass(classes);
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
                ClassContainer container = this->model.getClassContainer();
                list<Class> classes = container.getAll();
                this->classView.printClasses(classes);
            }
                break;
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
                Enroll* enroll = container.get(number, denomination);
                if(enroll != NULL){
                    this->enrollView.printEnroll(enroll);
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
                string initials;
                cout << "Enter the Employee Initials";
                cin >> initials;
                EmployeeContainer& container = this->model.getEmployeeContainer();
                Employee* employee = container.get(initials);
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
                string initials;
                cout << "Enter Employee Initials: ";
                cin >> initials;
                EmployeeContainer& container = this->model.getEmployeeContainer();
                Employee * employee = container.get(initials);
                if(employee != NULL){
                    string initials1;
                    cout << "Enter Class Initials: ";
                    cin >> initials1;
                    LectureContainer& container1 = employee->getLectures();
                    container1.remove(initials1);
                }else{
                    cout<<"Employee does not exist."<<endl;
                }
            }
                break;
            case 3:	{
                string initials;
                cout << "Enter Employee Initials: ";
                cin >> initials;
                EmployeeContainer& container = this->model.getEmployeeContainer();
                Employee* employee = container.get(initials);
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
}
void Controller::runFeedback() {
    int op = -1;
    do {
        op= this->view.menuFeedback();
        switch (op) {
            case 1:{
                Feedback feedback = this->feedbackView.getFeedback((this->model.getClientContainer()),(this->model.getClassContainer()),(this->model.getFeedbackContainer()));
                FeedbackContainer& container = this->model.getFeedbackContainer();
                container.add(feedback);
            }
            break;
            case 2:{
                int number;
                cout << "Enter Client Number: ";
                cin >> number;
                string initials;
                cout << "Enter Class Initials: ";
                cin >> initials;
                FeedbackContainer& container = this->model.getFeedbackContainer();
                Feedback* feedback= container.getCla(number, initials);
                if(feedback != NULL){
                    this->feedbackView.printFeedback(feedback);
                }else{
                    cout<<"Feedback Error"<<endl;
                }
            }
            break;
            case 3:{
                FeedbackContainer container = this->model.getFeedbackContainer();
                list<Feedback> feedbacks = container.getAll();
                this->feedbackView.printFeedbacks(feedbacks);
            }
        }
    } while (op!=0);
}