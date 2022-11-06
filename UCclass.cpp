//
// Created by pedro on 03/11/2022.
//

#include "UCclass.h"

UCclass::UCclass(const string &ucCode, const string &classCode) : ucCode(ucCode), classCode(classCode) {}

UCclass::UCclass(const string &ucCode, const string &classCode, int numStudents) : ucCode(ucCode), classCode(classCode){}

const string &UCclass::getUcCode() const {
    return ucCode;
}



const string &UCclass::getClassCode() const {
    return classCode;
}







UCclass::UCclass(const string &ucCode, const string &classCode, int numStudents, const vector<Lesson> &lessons)
        : ucCode(ucCode), classCode(classCode),  lessons(lessons) {}

UCclass UCclass::operator=(UCclass uc1) {
    this->ucCode=uc1.ucCode;
    this->classCode=uc1.classCode;
    this->students = uc1.students;
    this->lessons=uc1.lessons;
    return *this;
}

bool UCclass::operator<(UCclass uc1) const {
    if(uc1.ucCode == this->ucCode){
        return (uc1.classCode > this->classCode);
    }
    else{return (uc1.ucCode > this->ucCode);}
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

const set<Student> &UCclass::getStudents() const {
    return students;
}

void UCclass::setStudents(const set<Student> &students) {
    UCclass::students = students;
}
