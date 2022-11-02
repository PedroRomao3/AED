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

set<Class> Uni::getClasses() const {
    return classes;
}

void Uni::setClasses(const set<Class> &classes) {
    Uni::classes = classes;
}
void Uni::addtol(Lesson l){
    Uni::lessons.push_back(l);
}

Uni::Uni() {
    lessons = vector<Lesson>();
    classes = set<Class>();
    students = vector<Student>();
}

void Uni::addtoc(Class c) {
    Uni::classes.insert(c);
    //set<Class> a;
    //a.insert(c);
}

const vector<Lesson> &Uni::getLessons() const {
    return lessons;
}

void Uni::setLessons(const vector<Lesson> &lessons) {
    Uni::lessons = lessons;
}
