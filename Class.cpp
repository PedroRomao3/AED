//
// Created by pedro on 31/10/2022.
//

#include "Class.h"

Class::Class(string classCode) {
    this->classCode = classCode;
}

Class::Class(string classCode, vector<Lesson> lessons) {
    this->classCode = classCode;
    this->lessons = lessons;
}

const string &Class::getClassCode() const {
    return classCode;
}
void Class::setClassCode(const string &classCode) {
    Class::classCode = classCode;
}
const vector<Lesson> Class::getLessons() const {
    return lessons;
}
void Class::setLessons(const vector<Lesson> lessons) {
    Class::lessons = lessons;
}

Class Class::operator=(Class s1) {
    this->classCode = s1.classCode;
    this->lessons = s1.lessons;
    return *this;
}

bool Class::operator<(const Class &s1) const {
    return true;
    /*string r1,r2;
    r1=s1.classCode.substr(4,2);
    r2=Class::classCode.substr(4,2);
    if () {
        return (stoi(r1) > stoi(r2));
    }*/
}

bool Class::operator==(const Class &s1) const {
    return s1.classCode==this->classCode;
}

