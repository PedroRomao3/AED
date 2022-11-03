//
// Created by pedro on 31/10/2022.
//

#include <iostream>
#include <algorithm>
#include <list>
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

void Uni::classOcupationandStudents(){
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

bool comPSC(Student s1, Student s2){
    return s1.getCode() < s2.getCode();

}
void Uni::classOcupationandStudentsbyStudentcode() {
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

    list<Student> listaestudantes;

    for (Student s : estudantesnaturma){
        listaestudantes.push_back(s);
    }

    listaestudantes.sort(comPSC);

    for (Student element : listaestudantes){
        cout << element.getCode() << "    " << element.getName() << endl;
    }
    cout << "Class " << id << " has " << counter << " students";
}


void Uni::ucOcupation() {
    cout << "UCcode: ";
    string id;
    int counter;
    cin >> id;
    set<Student> estudantesnauc;
    for (Student s : this->students){
        for(Lesson les : s.getLessons()){
            if (les.getUcCode() == id) {
                estudantesnauc.insert(s);
                counter++;
                break;
            }
        }
    }

    for (Student element : estudantesnauc){
        cout << element.getCode() << "    " << element.getName() << endl;
    }
    cout << "The UC " << id << " has " << counter << " students";

}

