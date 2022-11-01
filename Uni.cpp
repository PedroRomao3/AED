//
// Created by pedro on 31/10/2022.
//

#include "Uni.h"

const vector<Student> &Uni::getStudents() const {
    return students;
}

void Uni::setStudents(const vector<Student> &students) {
    Uni::students = students;
}

const vector<Class> &Uni::getClasses() const {
    return classes;
}

void Uni::setClasses(const vector<Class> &classes) {
    Uni::classes = classes;
}

Uni::Uni() {
    vector<Student> noth;
    vector<Class> noth1;
    vector<Lesson> noth2;
    this->students = noth;
    this->classes = noth1;
    this->lessons = noth2;
}
Uni Uni::operator=(Uni uni1) {
    this->students = uni1.students;
    this->classes = uni1.classes;
    this->lessons = uni1.lessons;
    return *this;
}
