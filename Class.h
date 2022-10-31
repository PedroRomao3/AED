//
// Created by pedro on 30/10/2022.
//

#ifndef UNTITLED1_CLASS_H
#define UNTITLED1_CLASS_H
#include <vector>
#include <string>
#include "Student.h"

using namespace std;


class Class {
    string code;
    vector<Student> vector;
    float beginning;
    float duration;
    string type;
    string day;
public:
    Class(string x, std::vector<Student> y, float z, float i, string t, string h){
        this->code = x;
        this->vector = y;
        this->beginning = z;
        this->duration = i;
        this->type = t;
        this->day = h;
    }


};


#endif //UNTITLED1_CLASS_H
