//
// Created by pedro on 31/10/2022.
//

#include "Class.h"
Class::Class(string classCode, vector<Lesson> timetable) {
    this->classCode = classCode;
    this->timetable = timetable;
}

const string &Class::getClassCode() const {
    return classCode;
}
void Class::setClassCode(const string &classCode) {
    Class::classCode = classCode;
}
const vector<Lesson> &Class::getTimetable() const {
    return timetable;
}
void Class::setTimetable(const vector<Lesson> &timetable) {
    Class::timetable = timetable;
}

Class::Class(string classCode) {
    this->classCode = classCode;
}
