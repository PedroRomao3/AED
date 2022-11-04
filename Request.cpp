//
// Created by migue on 04/11/2022.
//

#include "Request.h"

Request::Request(int request,Student student, const vector<UCclass> &classinvolved) : request(request), student(student), classinvolved(classinvolved) {}

int Request::getRequest()  {
    return request;
}

void Request::setRequest(int request) {
    Request::request = request;
}

const vector<UCclass> &Request::getClassinvolved() const {
    return classinvolved;
}

void Request::setClassinvolved(const vector<UCclass> &classinvolved) {
    Request::classinvolved = classinvolved;
}

const Student &Request::getStudent() const {
    return student;
}

void Request::setStudent(const Student &student) {
    Request::student = student;
}
