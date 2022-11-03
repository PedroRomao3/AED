//
// Created by pedro on 31/10/2022.
//

#include <iostream>
#include "Uni.h"

const set<Student> &Uni::getStudents() const {
    return this->students;
}

void Uni::setStudents(const set<Student> &students) {
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
    students = set<Student>();
}


void Uni::addtos(Student s) {
    Uni::students.insert(s);
}


void Uni::addtoc(Class c) {
    Uni::classes.insert(c);
}


void Uni::removeClass(Class c) {
    classes.erase(c);
}


const vector<Lesson> &Uni::getLessons() const {
    return lessons;
}

void Uni::setLessons(const vector<Lesson> &lessons) {
    Uni::lessons = lessons;
}

void Uni::removeStudent(Student s1) {
    students.erase(s1);
}

void Uni::timeTableStudent() {
    int teste;
    cout << "Insert code: " << endl;
    cin >> teste;
    set<Student> estudantes = this->students;
    for (Student c : estudantes){
        if (c.getCode() == teste){
            c.printTimetable();
        }
    }
}

void Uni::classOcupationandstudents(){
    cout << "Class Id: ";
    string id;
    int counter;
    cin >> id;
    set<Student> estudantesnaturma;
    for (Student s : students){
        for (Lesson les : s.getLessons()){
            if (les.getClasscode() == id){
                estudantesnaturma.insert(s);
                counter++;
                break;
            }
        }
    }
    for (Student element : estudantesnaturma){
        cout << element.getCode() << "    " << element.getName() << endl;
    }
    cout << "Class " << id << " has " << counter << " students";
}

