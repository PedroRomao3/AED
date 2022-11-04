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


void Uni::studentsMoreThenUc() {
    int n;
    cout << "Mininum uc: ";
    cin >> n;
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
            string ucCode;
            string classCode;
            set<Student> studentshelper;
            ucCode=l.getUcCode();
            classCode=l.getClasscode();
            UCclass turmauc = UCclass(ucCode, classCode);
            auto it1 = this->uClasses.find(turmauc);
            if(it1!=this->uClasses.end()){
                UCclass turmauc1 = *it1;
                studentshelper = turmauc1.getStudents();
                studentshelper.insert(s);
                turmauc1.setStudents(studentshelper);
                vector<Lesson> lesSons;
                UCclass helperclass= UCclass("","");
                this->uClasses.erase(*it1);
                this->uClasses.insert(turmauc1);
                for(Lesson l1:lesSons){
                    if(l1.equals(l)){
                        goto label;
                    }
                }
                lesSons = turmauc1.getLessons();
                lesSons.push_back(l);
                turmauc1.setLessons(lesSons);
                helperclass = turmauc1;
                this->uClasses.erase(turmauc1);
                this->uClasses.insert(helperclass);
                label:

                continue;
            }

        }
    }
}

void Uni::removeStudentClass(Student s, UCclass uc){
    set<Student> setSt = uc.getStudents();
    setSt.erase(s);
    uc.setStudents(setSt);
    vector<Lesson> timet = s.getLessons();
    auto it = timet.begin();
    while (it != timet.end()){
        Lesson lesson = *it;
        if (lesson.getClasscode()==uc.getClassCode() && lesson.getUcCode() == uc.getUcCode()){
            timet.erase(it);
        }
        it++;
    }
    s.setLessons(timet);
}

const set<UCclass> &Uni::getUClasses() const {
    return uClasses;
}

void Uni::setUClasses(const set<UCclass> &uClasses) {
    Uni::uClasses = uClasses;
}

const queue<Request> &Uni::getRequests() const {
    return requests;
}

void Uni::setRequests(const queue<Request> &requests) {
    Uni::requests = requests;
}
void Uni::requestmaker() {
    cout<<"enter request code\n";
    int request;
    cin>>request;
    if (request == 1) {


        cout << "insert student code\n";
        int studentcode;
        cin >> studentcode;
        cout << "insert class code\n";
        string classcode;
        cin >> classcode;
        cout << "insert uc code\n";
        string uccode;
        cin >> uccode;
        UCclass a = UCclass(uccode, classcode);
        auto it = this->getUClasses().find(a);
        UCclass b = *it;
        vector<UCclass> classes;
        classes.push_back(b);
        Student s = Student(studentcode);
        auto ite = this->getStudents().find(s);
        Student c = *ite;
        Request request1 = Request(1, c, classes);
        this->requests.push(request1);
    }

    else if (request == 2){
            cout<<"insert student code\n";
            int studentcode;
            cin>>studentcode;
            cout<<"insert class code\n";
            string classcode;
            cin>>classcode;
            cout<<"insert uc code\n";
            string uccode;
            cin>>uccode;
            UCclass a = UCclass(uccode,classcode);
            auto it = this->getUClasses().find(a);
            UCclass b = *it;
            vector<UCclass> classes;
            classes.push_back(b);
            Student s = Student(studentcode);
            auto ite = this->getStudents().find(s);
            Student c = *ite;
            Request request1 = Request(2,c,classes);
            this->requests.push(request1);

    }

    else if (request == 3){
        cout<<"insert student code\n";
        int studentcode;
        cin>>studentcode;

        cout<<"insert first class code\n";
        string classcode;
        cin>>classcode;
        cout<<"insert first uc code\n";
        string uccode;
        cin>>uccode;

        cout<<"insert 2nd class code\n";
        string classcode2;
        cin>>classcode2;
        cout<<"insert 2nd uc code\n";
        string uccode2;
        cin>>uccode2;

        UCclass a = UCclass(uccode,classcode);
        UCclass j = UCclass(uccode2,classcode2);
        auto it = this->getUClasses().find(a);
        auto it1 = this->getUClasses().find(j);
        UCclass k = *it1;
        UCclass b = *it;
        vector<UCclass> classes1;
        classes1.push_back(b);
        classes1.push_back(k);
        Student s = Student(studentcode);
        auto ite = this->getStudents().find(s);
        Student c = *ite;
        Request request1 = Request(3,c,classes1);
        this->requests.push(request1);
    }

    else if (request == 4) {
        cout << "insert student code\n";
        int studentcode;
        cin >> studentcode;
        Student s = Student(studentcode);
        auto ite = this->getStudents().find(s);
        Student c = *ite;
        while (true) {
            cout << "insert first class code if done inserting insert q\n";
            string classcode;
            cin >> classcode;
            if (classcode == "q") break;
            cout << "insert first uc code\n";
            string uccode;
            cin >> uccode;

            cout << "insert 2nd class code\n";
            string classcode2;
            cin >> classcode2;
            cout << "insert 2nd uc code\n";
            string uccode2;
            cin >> uccode2;

            UCclass a = UCclass(uccode, classcode);
            UCclass j = UCclass(uccode2, classcode2);
            auto it = this->getUClasses().find(a);
            auto it1 = this->getUClasses().find(j);
            UCclass k = *it1;
            UCclass b = *it;
            vector<UCclass> classes1;
            classes1.push_back(b);
            classes1.push_back(k);

            Request request1 = Request(4, c, classes1);
            this->requests.push(request1);

        }
    }
}

void Uni::requestHandler() {


    this->requests.front();


}