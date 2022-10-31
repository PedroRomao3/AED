//
// Created by pedro on 30/10/2022.
//
#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H
#include <string>
#include "Lesson.h"

using namespace std;

class Student {
    string name;
    int code;
    vector<Lesson> timetable;

public:
    Student(string name, int code);
    Student(string name, int code, vector<Lesson> timetable);
    Student operator = (Student s1);

};


#endif //UNTITLED1_STUDENT_H
