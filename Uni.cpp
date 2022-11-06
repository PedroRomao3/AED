//
// Created by pedro on 31/10/2022.
//

#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>
#include "Uni.h"
#include <iomanip>
extern int CAP;


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
    validStudentCode(teste);
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
    validClassCode(id);
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

void Uni::UclassOcupationandStudents(){
    cout << "Class Code: ";
    string id;
    string ucode;
    int counter;
    cin >> id;
    validClassCode(id);
    cout << "Class UCode: ";
    cin>>ucode;
    validUCode(ucode);
    UCclass turma = UCclass(ucode,id);
    UCclass turmavdd = *(uClasses.find(turma));
    int occupation = turmavdd.getStudents().size();
    for (Student element : turmavdd.getStudents()){
        cout << element.getCode() << "    " << element.getName() << endl;
    }
    cout << " the class " << id << " of the UC" << ucode << " has " << occupation << " students";
}

bool comPSC(Student s1, Student s2){
    return s1.getCode() < s2.getCode();

}
void Uni::classOcupationandStudentsbyStudentcode() {
    cout << "Class Id: ";
    string id;
    int counter;
    cin >> id;
    validClassCode(id);
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

void Uni::UclassOcupationByStudentCode(){
    cout << "Class Id: ";
    string id;
    cin >> id;
    validClassCode(id);
    cout<< "ucode";
    string ucode;
    cin >>ucode;
    validUCode(ucode);


    UCclass turma = UCclass(ucode,id);
    UCclass turmavdd = *(uClasses.find(turma));

    list<Student> listaestudantes;

    for (Student s : turmavdd.getStudents()){
        listaestudantes.push_back(s);
    }

    listaestudantes.sort(comPSC);

    for (Student element : listaestudantes){
        cout << element.getCode() << "    " << element.getName() << endl;
    }
    cout << "Class " << id <<"of the uc" << ucode << " has " << turmavdd.getStudents().size() << " students";
}


void Uni::ucOcupation() {
    cout << "UCcode: ";
    string id;
    int counter;
    cin >> id;
    validUCode(id);
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
    string year;
    int counter;
    cin >> year;
    validyear(year);
    string ano;
    int switchenter = stoi(year);
    switch(switchenter){
        case 1:
            ano = "first";
            break;
        case 2:
            ano = "second";
            break;
        case 3:
            ano = "third";
            break;
    }
    counter = 0;
    set<Student> estudantesnoano;
    for (Student s : this->students){
        for(Lesson les : s.getLessons()){

            if (les.getClasscode()[0] == year[0]) {
                estudantesnoano.insert(s);
                counter++;
                break;
            }
        }
    }

    for (Student element : estudantesnoano){
        cout << element.getCode() << "    " << element.getName() << endl;
    }
    cout << "The " << ano << " year (" << year << ") has " << counter << " students";
}


void Uni::studentsMoreThenUc() {
    int n;
    cout << "Mininum uc: ";
    cin >> n;
    validminimumuc(n);
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
                // adicinei estudante
                lesSons = turmauc1.getLessons();
                for(Lesson l1:lesSons){
                    if(l1.equals(l)){// se alguma das lesson da turma for igual a que eu quero adicionar
                        goto label;
                    }
                }
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
    UCclass cclass = uc;
    this->uClasses.erase(uc);
    this->uClasses.insert(cclass);
    vector<Lesson> timet = s.getLessons();
    auto it = timet.begin();
    while (it != timet.end()){
        Lesson lesson = *it;
        if (lesson.getClasscode()==uc.getClassCode() && lesson.getUcCode() == uc.getUcCode()){
            it = timet.erase(it);
        }
        else{it++;}
    }
    s.setLessons(timet);
    Student hji = s;
    this->students.erase(s);
    this->students.insert(hji);
    this->requests.front().setStudent(hji);
}
void Uni::addStudentClass(Student s, UCclass uc) {
    set<Student> setSt = uc.getStudents();
    setSt.insert(s);
    uc.setStudents(setSt);
    UCclass cclass = uc;
    this->uClasses.erase(uc);
    this->uClasses.insert(cclass);
    vector<Lesson> timet = s.getLessons();
    auto it = cclass.getLessons().begin();
    while (it != cclass.getLessons().end()){
        Lesson lesson = *it;
        timet.push_back(lesson);

        it++;
    }


    s.setLessons(timet);
    Student hji = s;
    this->students.erase(s);
    this->students.insert(hji);
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


    cout << "Remove  a student from a class                                     [1]" <<
         endl;
    cout << "Add student to a class                                             [2]" <<
         endl;
    cout << "Change student class                                               [3]" <<
         endl;
    cout << "Change various classes of a student                                [4]" <<
         endl;
    cout << "Go back                                                            [5]" <<
         endl;
    cout << "Please choose what is your option:" << endl <<
         endl;

    int request;
    cin>>request;
    validrequest(request);
    if (request == 5){ return;}
    if (request == 1) {


        cout << "insert student code\n";
        int studentcode;
        cin >> studentcode;
        validStudentCode(studentcode);
        cout << "insert class code\n";
        string classcode;
        cin >> classcode;
        validClassCode(classcode);
        cout << "insert uc code\n";
        string uccode;
        cin >> uccode;
        validUCode(uccode);
        UCclass a = UCclass(uccode, classcode);
        auto it = this->getUClasses().find(a);
        UCclass b = *it;
        vector<UCclass> classes;
        classes.push_back(b);
        Student s = Student(studentcode);
        for (Student s1:this->getStudents()){
            if (s1.getCode()== s.getCode()){
                s = s1;
                break;
            }
        }

        Request request1 = Request(1, s, classes);
        this->requests.push(request1);
    }

    else if (request == 2){
            cout<<"insert student code\n";
            int studentcode;
            cin>>studentcode;
            validStudentCode(studentcode);
            cout<<"insert class code\n";
            string classcode;
            cin>>classcode;
            validClassCode(classcode);
            cout<<"insert uc code\n";
            string uccode;
            cin>>uccode;
            validUCode(uccode);
            UCclass a = UCclass(uccode,classcode);
            auto it = this->getUClasses().find(a);
            UCclass b = *it;
            vector<Lesson> final;
            bool flag;
            for (Lesson less : b.getLessons()){
                flag = 1;
                if (final.empty()) final.push_back(less);
                for (Lesson lesss : final){
                    if (lesss.equals(less)) {flag = 0;}
                }
                if (flag) final.push_back(less);
            }
            b.setLessons(final);
            //end of modification
            vector<UCclass> classes;
            classes.push_back(b); //mudei aqui o b para final
            Student s = Student(studentcode);
            for (Student s1:this->getStudents()){
            if (s1.getCode()== s.getCode()){
                s = s1;
                break;
            }
            }
            Request request1 = Request(2,s,classes);
            this->requests.push(request1);

    }

    else if (request == 3){
        cout<<"insert student code\n";
        int studentcode;
        cin>>studentcode;
        validStudentCode(studentcode);

        cout<<"insert class code\n";
        string classcode;
        cin>>classcode;
        validClassCode(classcode);
        cout<<"insert uc code\n";
        string uccode;
        cin>>uccode;
        validUCode(uccode);
        UCclass a = UCclass(uccode,classcode);
        auto it = this->getUClasses().find(a);
        UCclass b = *it;
        vector<UCclass> classes1;
        classes1.push_back(b);
        Student s = Student(studentcode);
        for (Student s1:this->getStudents()){
            if (s1.getCode()== s.getCode()){
                s = s1;
                break;
            }
        }
        Request request1 = Request(3,s,classes1);
        this->requests.push(request1);
    }

    else if (request == 4) {
        cout << "insert student code\n";
        int studentcode;
        cin >> studentcode;
        validStudentCode(studentcode);
        Student s = Student(studentcode);
        for (Student s1:this->getStudents()){
            if (s1.getCode()== s.getCode()){
                s = s1;
                break;
            }
        }
        vector<UCclass> classes1;
        while (true) {
            cout << "insert class code if done inserting insert q\n";
            string classcode;
            cin >> classcode;
            validClassCode(classcode);
            if (classcode == "q") break;
            cout << "insert uc code\n";
            string uccode;
            cin >> uccode;
            validUCode(uccode);

            UCclass a = UCclass(uccode, classcode);
            auto it = this->getUClasses().find(a);
            UCclass b = *it;
            classes1.push_back(b);
        }


        Request request1 = Request(4, s, classes1);
        this->requests.push(request1);


    }
}

bool Uni::isCompatible(vector<Lesson> timetable, vector<Lesson> classLessons ){
    vector<Lesson> timetableTP;
    vector<Lesson> classTPLesson;
    for (Lesson les : timetable){
        if (les.getType() == "TP" || les.getType() == "PL"){
            bool unique = true;
            for (Lesson l :timetableTP){
                if (l.equals(les)){
                    unique = false;
                }
            }
            if(unique){
            timetableTP.push_back(les);
            }
        }
    }

    for (Lesson le : classLessons){
        if (le.getType() == "TP" || le.getType() == "PL"){
            bool unique = true;
            for (Lesson l :classTPLesson){
                if (l.equals(le)){
                    unique = false;
                }
            }
            if(unique){
                classTPLesson.push_back(le);
            }

        }
    }

    for(Lesson l : timetableTP){
        for(Lesson l1 :  classTPLesson) {
            if (l1.getDay()==l.getDay()) {
                float start1 = l.getStart();
                float end1 = start1 + l.getDuration();
                float start2 = l1.getStart();
                float end2 = start2 + l1.getDuration();
                if (start1 == start2 || end1 == end2) { return false; }
                else if ((end2 > start1) && (end2 < end1)) { return false; }
                else if ((start2 > start1) && (start2 < end1)) { return false; }
            }
        }
        }
    return true;
    }


void Uni::requestHandler() {
    while(!this->requests.empty()) {
        Request a = this->requests.front();

        if (a.getRequest() == 1) {
            int control = 1;
            for (Student s: a.getClassinvolved()[0].getStudents()) {
                if (s == a.getStudent()) {
                    Uni::removeStudentClass(a.getStudent(), a.getClassinvolved()[0]);
                    control =0;
                    this->requests.pop();
                    break;
                }
            }
            if(control) {
                cout << "Student is not in that class";
                this->invalidrequest.push(a);
            }
        } else if (a.getRequest() == 2) {
            if (a.getClassinvolved()[0].getStudents().size() <= CAP && isCompatible(a.getStudent().getLessons(), a.getClassinvolved()[0].getLessons()) && balanced(a.getClassinvolved()[0], a.getStudent())) {
                addStudentClass(a.getStudent(), a.getClassinvolved()[0]);
                this->requests.pop();
            } else {
                this->invalidrequest.push(a);
                this->requests.pop();
                cout << "Cannot add student to that class";
            }
        }else if (a.getRequest() == 3) {
            UCclass original=a.getClassinvolved()[0];
            int temp =1;
            for (UCclass uc2 : this->uClasses){
                auto it = uc2.getStudents().find(a.getStudent());
                if (it!= uc2.getStudents().end() && uc2.getUcCode() == a.getClassinvolved()[0].getUcCode()){
                    original = uc2;
                    temp = 0;
                }
            }
            if (temp){
                cout<<"invalid request type 3";
                this->invalidrequest.push(a);
                this->requests.pop();
                continue;
            }
            removeStudentClass(a.getStudent(),original);
            a = this->getRequests().front();
            //a.getclassinvolved().pop()
            if (a.getClassinvolved()[0].getStudents().size() < CAP && isCompatible(a.getStudent().getLessons(), a.getClassinvolved()[0].getLessons()) && balanced(a.getClassinvolved()[0], a.getStudent()))
            {
                addStudentClass(a.getStudent(), a.getClassinvolved()[0]);
            }
            else{
                addStudentClass(a.getStudent(), original);
                cout<<"invalid request type 3";
                this->invalidrequest.push(a);
                this->requests.pop();
            }
            this->requests.pop();


        }else if (a.getRequest() == 4){
            for(int i=0;i<a.getClassinvolved().size();i++){
                UCclass original=a.getClassinvolved()[i];
                for (UCclass uc2 : this->uClasses){
                    auto it = uc2.getStudents().find(a.getStudent());
                    if (it!= uc2.getStudents().end() && uc2.getUcCode() == a.getClassinvolved()[i].getUcCode()){
                        original = uc2;
                    }
                }
                removeStudentClass(a.getStudent(),original);
                original = *(this->uClasses.find(original));
                a = this->getRequests().front();
                if (a.getClassinvolved()[i].getStudents().size() < CAP &&
                    isCompatible(a.getStudent().getLessons(), a.getClassinvolved()[i].getLessons()) && balanced(a.getClassinvolved()[i], a.getStudent()))
                {
                    addStudentClass(a.getStudent(), a.getClassinvolved()[i]);
                }
                else{

                    addStudentClass(a.getStudent(), original);
                    cout<< "invalid type 4\n";
                    this->invalidrequest.push(a);
                }
            }

            this->requests.pop();
        }
    }
}

bool Uni::balanced(UCclass uc, Student s) {
    int a = uc.getStudents().size();
    int c;
    for (UCclass uc2 : this->uClasses){
        auto it = uc2.getStudents().find(s);
        if (it!= uc2.getStudents().end() && uc2.getUcCode() == uc.getUcCode()){
            UCclass b = uc2;
            c = b.getStudents().size();
            if(a-c >= 3){
                return false;
            }
        }
    }
    return true;
}

void Uni::writeTimeTableStudent() {
    int teste;
    cout << "Insert code: " << endl;
    cin >> teste;
    validStudentCode(teste);
    set<Student> estudantes = this->students;
    Student estudante;
    for (Student c : estudantes){
        if (c.getCode() == teste){
            estudante = c;
        }
    }
    string of = "../StudentsTimetables/timetable";
    int a = estudante.getCode();
    auto of1 = to_string(a);
    string of2 = ".txt";
    string offinal = of + of1 + of2;

    ofstream file (offinal);
    for (Lesson les : estudante.getLessons()){
         file << "Turma: " << les.getClasscode() << "   ";
         file << "Cadeira: " << les.getUcCode() << "   ";
         float fin = les.getStart() + les.getDuration();
         file << "Dia: " << les.getDay() << "   ";
         file << "Tipo: " << les.getType() << "   ";
         file << "Hora: " << les.getStart() << " -> " << fin << "\n";;
         }
    file.close();
    }

void Uni::saveAndExit(string filename1,string filename2,string filename3){
    ofstream classesFile("../schedule/" + filename1);
    classesFile << "classCode,ucCode,Weekday,StartHour,Duration,Type\n";
    for(UCclass uCclass:this->getUClasses()){
        for(Lesson l : uCclass.getLessons()){
            classesFile << l.getClasscode()<<",";
            classesFile << l.getUcCode()<<",";
            classesFile << l.getDay()<<",";

            classesFile << setprecision(2) << l.getStart() << ",";
            classesFile << setprecision(2) << l.getDuration() << ",";
            classesFile << l.getType()<<"\n";
        }
    }
    classesFile.close();

    ofstream classespucFile("../schedule/" + filename2);
    classespucFile << "ucCode,classCode\n";
    for(UCclass uCclass:this->getUClasses()){
        classespucFile << uCclass.getUcCode() << ",";
        classespucFile << uCclass.getClassCode() << "\n";
    }
    classespucFile.close();

    ofstream classesStudentFile("../schedule/" + filename3);
    classesStudentFile << "StudentCode,StudentName,ucCode,classCode\n";
    set<Lesson> setL;
    for(Student s : this->getStudents()){
        for (Lesson l : s.getLessons()) {
            if (l.getType() == "TP" || l.getType() == "PL") {

            classesStudentFile << to_string(s.getCode()) << ",";
            classesStudentFile << s.getName() << ",";
            classesStudentFile << l.getUcCode() << ",";
            classesStudentFile << l.getClasscode() << "\n";

            }

        }
    }

    classesStudentFile.close();
    exit(0);
}

void Uni::validStudentCode(int &code) {
    bool flag = 1;
    for (Student s: this->students ){
        if (s.getCode() == code) {flag = 0;}
    }
    while (cin.fail() || flag)
    {

        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> code;
        for (Student s: this->students ){
            if (s.getCode() == code) {flag = 0;}
        }
    }
    cin.clear();
    cin.ignore(100, '\n');
}

Student Uni::returnStudent(int code) {
    return Student(code);
}


void Uni::validClassCode(string &code) {
    bool flag = 1;
    for (Class s: this->classes){
        if (s.getClassCode() == code) {flag = 0;}
    }
    while (cin.fail() || flag)
    {

        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> code;
        for (Class s: this->classes){
            if (s.getClassCode() == code) {flag = 0;}
        }
    }
    cin.clear();
    cin.ignore(100, '\n');
}

void Uni::validUCode(string &code) {
    bool flag = 1;
    for (UCclass uc: this->uClasses) {
        if (uc.getUcCode() == code) { flag = 0; }
    }

        while (cin.fail() || flag) {

            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> code;
            for (UCclass uc: this->uClasses) {
                if (uc.getUcCode() == code) { flag = 0; }
            }
        }
        cin.clear();
        cin.ignore(100, '\n');
    }





void Uni::validyear(string &code) {
    bool flag = 1;
    if ((code == "1") || (code == "2") || (code == "3")) flag = 0;
        while (cin.fail() || flag){
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> code;
            if ((code == "1") || (code == "2") || (code == "3")) flag = 0;
        }
        cin.clear();
        cin.ignore(100, '\n');
}


void Uni::validminimumuc(int &code) {
    while (cin.fail() || code <= 0 || code > 20) {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> code;
    }
    cin.clear();
    cin.ignore(100, '\n');
}


void Uni::validrequest(int &code) {
    while (cin.fail() || code <= 0 || code > 5) {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> code;
    }
    cin.clear();
    cin.ignore(100, '\n');
}




