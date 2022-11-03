//
// Created by pedro on 30/10/2022.
//

#include "Student.h"

Student::Student(string name, int code) {
    this->name = name;
    this->code = code;
}

Student::Student(string name, int code, vector<Lesson> timetable) {
    this->name = name;
    this->code = code;
    this->timetable = timetable;
}

Student Student::operator=(Student s1) {
    this->code = s1.code;
    this->name = s1.name;
    this->timetable = s1.timetable;
    return *this;
}

string Student::getName(){
    return this->name;
}

int Student::getId(){
    return this->code;
}
