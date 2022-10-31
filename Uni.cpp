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
