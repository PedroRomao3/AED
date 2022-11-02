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


const set<Class> Uni::getClasses() const {
    return classes;
}

void Uni::setClasses(const set<Class> &classes) {
    Uni::classes = classes;
}

void Uni::addtol(Lesson l) {
    Uni::lessons.push_back(l);
}

Uni::Uni() {
    lessons = vector<Lesson>();
    classes = set<Class>();
    students = vector<Student>();
}


void Uni::addtos(Student s) {
    Uni::students.push_back(s);
}

void Uni::addtoc(Class c) {
    Uni::classes.insert(c);
}
