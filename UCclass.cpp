//
// Created by pedro on 03/11/2022.
//

#include "UCclass.h"

UCclass::UCclass(const string &ucCode, const string &classCode) : ucCode(ucCode), classCode(classCode) {this->NumStudents=0;}

UCclass::UCclass(const string &ucCode, const string &classCode, int numStudents) : ucCode(ucCode), classCode(classCode),
                                                                                   NumStudents(numStudents) {}

const string &UCclass::getUcCode() const {
    return ucCode;
}



const string &UCclass::getClassCode() const {
    return classCode;
}



int UCclass::getNumStudents() const {
    return NumStudents;
}

void UCclass::setNumStudents(int numStudents) {
    NumStudents = numStudents;
}

UCclass::UCclass(const string &ucCode, const string &classCode, int numStudents, const vector<Lesson> &lessons)
        : ucCode(ucCode), classCode(classCode), NumStudents(numStudents), lessons(lessons) {}

UCclass UCclass::operator=(UCclass uc1) {
    this->ucCode=uc1.ucCode;
    this->classCode=uc1.classCode;
    this->NumStudents=uc1.NumStudents;
    this->lessons=uc1.lessons;
    return *this;
}

bool UCclass::operator<(UCclass uc1) const {
    if(uc1.classCode == this->classCode){
        return (uc1.ucCode < this->ucCode);
    }
    else{return (uc1.classCode < this->classCode);}
}

bool UCclass::operator==(UCclass uc1) {
    return (uc1.classCode == this->classCode && uc1.ucCode == this->ucCode);
}

const vector<Lesson> &UCclass::getLessons() const {
    return lessons;
}

void UCclass::setLessons(const vector<Lesson> &lessons) {
    UCclass::lessons = lessons;
}
