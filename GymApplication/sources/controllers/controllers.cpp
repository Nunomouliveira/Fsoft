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
    model = gym;
}
void Controller::run(){
    int op = -1;
    do{
        op=view.menuGym();
        switch(op){
            case 1:runClients();
                break;
            case 2:runEmployees();
                break;
            case 3:runClasses();
                break;
            case 4:runEnrolls();
                break;
            case 5:runLectures();
                break;
            case 6:runFeedback();
                break;
            default:
                break;
        }
    }while(op!=0);

}
void Controller::runClients() {
    int op = -1;
    do{
        op = view.menuClients();

        switch(op){
            case 1:	{
                Client client = clientView.getClient();
                ClientContainer& container = model.getClientContainer();
                container.add(client);
            }
                break;
            case 2:{
                int number;
                cout << "Enter Client Number: ";
                cin >> number;
                ClientContainer& container = model.getClientContainer();
                Client* client = container.get(number);
                if(client != NULL){
                    clientView.printClient(client);
                }else{
                    cout<<"Client does not exist."<<endl;
                }
            }
                break;
            case 3:{
                try{
                    int number;
                    cout << "Enter Client Number: ";
                    cin >> number;
                    ClientContainer& container = model.getClientContainer();
                    container.remove(number);
                }catch(DataConsistencyException& e){
                    string str(e.what());
                    cout<<str<<endl;
                }
            }
                break;
            case 4:
            {
                ClientContainer& container = model.getClientContainer();
                list<Client> clients = container.getAll();
                clientView.printClients(clients);
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
        op = view.menuEmployees();
        switch (op) {
            case 1: {
                Employee employee = employeeView.getEmployee();
                EmployeeContainer &container = model.getEmployeeContainer();
                container.add(employee);
            }
                break;
            case 2: {
                string initials;
                cout << "Enter Employee Initials: ";
                cin >> initials;
                EmployeeContainer &container = model.getEmployeeContainer();
                Employee* employee = container.get(initials);
                if (employee != NULL) {
                    employeeView.printEmployee(employee);
                } else {
                    cout << "Employee does not exist." << endl;
                }
            }
                break;
            case 3: {
                try {
                    string initials;
                    cout << "Enter Employee Initials: ";
                    cin >> initials;
                    EmployeeContainer &container = model.getEmployeeContainer();
                    container.remove(initials);
                } catch (DataConsistencyException &e) {
                    string str(e.what());
                    cout << str << endl;
                }
            }
                break;
            case 4: {
                EmployeeContainer container = model.getEmployeeContainer();
                list<Employee> employees = container.getAll();
                employeeView.printEmployees(employees);
            }
                break;

            default:
                break;
        }
    } while (op != 0);
}
void Controller::runClasses() {
    int op = -1;
    do{
        op = view.menuClasses();

        switch(op){
            case 1:	{
                Class classes = classView.getClass();
                ClassContainer& container = model.getClassContainer();
                container.add(classes);
            }
                break;
            case 2:{
                string initials;
                cout << "Enter Class Initials: ";
                cin >> initials;
                ClassContainer& container = model.getClassContainer();
                Class* classes = container.get(initials);
                if(classes != NULL){
                    classView.printClass(classes);
                }else{
                    cout<<"Class does not exist."<<endl;
                }
            }
                break;
            case 3:{
                try{
                    string initials;
                    cout << "Enter Class Initials: ";
                    cin >> initials;
                    ClassContainer& container = model.getClassContainer();
                    container.remove(initials);
                }catch(DataConsistencyException& e){
                    string str(e.what());
                    cout<<str<<endl;
                }
            }
                break;
            case 4:
            {
                ClassContainer container = model.getClassContainer();
                list<Class> classes = container.getAll();
                classView.printClasses(classes);
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
        op = view.menuEnrolls();

        switch(op){
            case 1:	{
                Enroll enroll = enrollView.getEnroll(model.getClientContainer(), model.getClassContainer());
                EnrollContainer& container = model.getEnrollContainer();
                container.add(enroll);
            }
                break;
            case 2:{
                int number;
                cout << "Enter Client Number: ";
                cin >> number;
                string initials;
                cout << "Enter Class Initials: ";
                cin >> initials;
                EnrollContainer& container = model.getEnrollContainer();
                Enroll* enroll = container.get(number, initials);
                if(enroll != NULL){
                    enrollView.printEnroll(enroll);
                }else{
                    cout<<"Enroll does not exist."<<endl;
                }
            }
                break;
            case 3:{
                try{
                    int number;
                    cout << "Enter Client Number: ";
                    cin >> number;
                    string initials;
                    cout << "Enter Class Initials: ";
                    cin >> initials;
                    EnrollContainer& container = model.getEnrollContainer();
                    container.remove(number, initials);
                }catch(DataConsistencyException& e){
                    string str(e.what());
                    cout<<str<<endl;
                }
            }
                break;
            case 4:
            {
                EnrollContainer container = model.getEnrollContainer();
                list<Enroll> enrolls = container.getAll();
                enrollView.printEnrolls(enrolls);

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
        op = view.menuLectures();

        switch(op){
            case 1:	{
                string initials;
                cout << "Enter the Employee Initials: ";
                cin >> initials;
                EmployeeContainer& container = model.getEmployeeContainer();
                Employee* employee = container.get(initials);
                if(employee != NULL){
                    Lecture lecture = lectureView.getLecture(model.getClassContainer());
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
                EmployeeContainer& container = model.getEmployeeContainer();
                Employee* employee = container.get(initials);
                if(employee != NULL){
                    LectureContainer& container1 = employee->getLectures();
                    list<Lecture> listLecture = container1.getAll();
                    lectureView.printLectures(employee, listLecture);
                }else{
                    cout<<"Employee does not exist."<<endl;
                }
            }
                break;
            case 3:	{
                string initials;
                cout << "Enter Employee Initials: ";
                cin >> initials;
                EmployeeContainer& container = model.getEmployeeContainer();
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



            default:
                break;
        }
    }while(op!=0);
}
void Controller::runFeedback() {
    int op = -1;
    do {
        op= view.menuFeedback();
        switch (op) {
            case 1:{
                Feedback feedback = feedbackView.getFeedback((model.getClientContainer()),(model.getClassContainer()));
                FeedbackContainer& container = model.getFeedbackContainer();
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
                FeedbackContainer& container = model.getFeedbackContainer();
                Feedback* feedback= container.getCla(number, initials);
                if(feedback != NULL){
                    this->feedbackView.printFeedback(feedback);
                }else{
                    cout<<"Feedback Error"<<endl;
                }
            }
            break;
            case 3:{
                FeedbackContainer container = model.getFeedbackContainer();
                list<Feedback> feedbacks = container.getAll();
                this->feedbackView.printFeedbacks(feedbacks);
            }
        }
    } while (op!=0);
}