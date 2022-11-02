//
// Created by pedro on 31/10/2022.
//

#include "Class.h"

Class::Class(string classCode) {
    this->classCode = classCode;
}

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

Class Class::operator=(Class s1) {
    this->classCode = s1.classCode;
    this->timetable = s1.timetable;
    return *this;
}
bool Class::operator<(Class s1){
    string r1,r2;
    r1=this->classCode.substr(4,2);
    r2=s1.classCode.substr(4,2);
    return (stoi(r1)< stoi(r2));
}