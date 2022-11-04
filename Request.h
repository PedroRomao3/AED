//
// Created by migue on 04/11/2022.
//

#ifndef PROJAED_REQUEST_H
#define PROJAED_REQUEST_H

#include <string>
#include <iostream>
#include "Student.h"
#include "UCclass.h"

using namespace std;

class Request {
    int request;
    Student student;
    vector<UCclass> classinvolved;

public:
    Request(int request,Student student, const vector<UCclass> &classinvolved);

    int getRequest() ;

    void setRequest(int request);

    const vector<UCclass> &getClassinvolved() const;

    void setClassinvolved(const vector<UCclass> &classinvolved);

    const Student &getStudent() const;

    void setStudent(const Student &student);


};


#endif //PROJAED_REQUEST_H
