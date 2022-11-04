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


void Uni::addtou(UCclass uc) {
    Uni::uClasses.insert(uc);
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

void Uni::yearStudent() {
    cout << "Year: ";
    char id;
    int counter;
    cin >> id;
    string ano;
    switch(id){
        case '1':
            ano = "first";
            break;
        case '2':
            ano = "second";
            break;
        case '3':
            ano = "third";
            break;
    }

    set<Student> estudantesnoano;
    for (Student s : this->students){
        for(Lesson les : s.getLessons()){
            if (les.getClasscode()[0] == id) {
                estudantesnoano.insert(s);
                counter++;
                break;
            }
        }
    }

    for (Student element : estudantesnoano){
        cout << element.getCode() << "    " << element.getName() << endl;
    }
    cout << "The " << ano << " year (" << id << ") has " << counter << " students";
}


void Uni::studentsMoreThenUc(int n) {
    cout<<"The following students have more than " << n << " UCs:\n";
    set<string> ucs;
    set<Student> more;
    for (Student s : this->students) {
        ucs.clear();
        for (Lesson l : s.getLessons()){
            string st = l.getUcCode();
            ucs.insert(st);
        }
        if(ucs.size()>n){
            more.insert(s);
            cout<<s.getCode()<< "    " <<s.getName()<< " has " << ucs.size() << " UCs\n";
        }

    }

    cout<< "There are " << more.size() <<" students with more than "<<n<<" UCs";
}

void Uni::fillUCclasses() {
    for(Student s : this->students){
        for(Lesson l : s.getLessons()){
            string h1;
            string h2;
            h1=l.getUcCode();
            h2=l.getClasscode();
            UCclass turmauc = UCclass(h1,h2);
            auto it1 = this->uClasses.find(turmauc);
            if(it1!=this->uClasses.end()){
                UCclass helper = *it1;
                vector<Lesson> helper2 = helper.getLessons();
                for(Lesson l1:helper2){
                    if(l1.equals(l)){
                        goto label;
                    }
                }
                helper2.push_back(l);
                helper.setLessons(helper2);
                this->uClasses.erase(*it1);
                this->uClasses.insert(helper);
                label:
                continue;
            }

        }
    }
}


