//
// Created by pedro on 30/10/2022.
//
#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H
#include <string>
using namespace std;

class Student {
    string name;
    int code;

public:
    Student(string x, int y){
        this->name = x;
        this->code = y;
    }

};


#endif //UNTITLED1_STUDENT_H
