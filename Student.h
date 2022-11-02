//
// Created by pedro on 30/10/2022.
//
#ifndef PROJAED_STUDENT_H
#define PROJAED_STUDENT_H

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

    Student operator=(Student s1);

    string getName();
};

#endif //PROJAED_STUDENT_H
