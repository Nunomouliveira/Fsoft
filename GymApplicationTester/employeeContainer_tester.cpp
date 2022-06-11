//
// Created by migue on 09/06/2022.
//
#include "gtest/gtest.h"
#include "DuplicatedDataException.h"
#include "DataConsistencyException.h"
#include "employeeContainer.h"


TEST(EmployeeContainerAddTest, ValidEmployee) {
    Employee employee ("MIEL", "Miguel");
    EmployeeContainer container;
    bool flag = true;
    try{
        container.add(employee);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    if(flag == true){
        string initials = employee.getInitials();
        Employee * ptr = container.get(initials);
        flag = (*ptr) == employee;
    }
    EXPECT_TRUE(flag);
}
TEST(StudentContainerAddTest, DuplicateStudent) {

    Employee employee ("MIEL", "MIGUEL");
    EmployeeContainer container;
    bool flag = true;
    try{
        container.add(employee);
        container.add(employee);
    }catch(DuplicatedDataException& e){
        flag = false;
    }
    EXPECT_FALSE(flag);
}

TEST(EmployeeContainerRemoveTest, NoDataConsistencyProblem) {
    Employee employee1 ("MIEL", "Miguel");
    Employee employee2 ("NOLI", "Nuno");
    Class classes ("XXXX", "XXXXXXXXXXXXXXXXXXXX");
    Lecture lecture(&classes);
    LectureContainer lectureContainer;
    lectureContainer.add(lecture);
    EmployeeContainer container;
    container.add(employee1);
    container.add(employee2);
    string initials = employee1.getInitials();
    bool flag = true;
    try{
        container.remove(initials);
    }catch(DataConsistencyException& e){
        flag = false;
    }
    if(flag == true){
        Employee * ptr = container.get(initials);
        if(ptr != NULL)
            flag = false;
    }
    EXPECT_TRUE(flag);
}

TEST(EmployeeContainerRemoveTest, DataConsistencyProblem) {
    Employee employee ("MIEL", "Miguel");
    EmployeeContainer container;
    container.add(employee);
    const string& initials = employee.getInitials();
    bool flag = true;
    try{
        container.remove(initials);
    }catch(DataConsistencyException& e){
        flag = false;
    }

    EXPECT_FALSE(flag);
}





