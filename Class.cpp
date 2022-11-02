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
void Class::setClassCode(const string classCode) {
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
bool Class::operator<(Class s1) const{
    return true;
}

bool Class::operator==(const Class s1) {
    return s1.classCode==this->classCode;
}