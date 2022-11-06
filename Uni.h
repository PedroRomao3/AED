//
// Created by pedro on 31/10/2022.
//

#ifndef PROJAED_UNI_H
#define PROJAED_UNI_H

#include <stack>
#include <queue>
#include "Student.h"
#include "Class.h"
#include "UCclass.h"
#include "Request.h"

class Uni {
    set<Student> students;
    set<Class> classes;
    vector<Lesson> lessons;
    set<UCclass> uClasses;
    queue<Request> requests;
    stack<Request> invalidrequest;


public:

    Uni();

    const set<Student> &getStudents() const;

    void validClassCode(string &code);

    void setStudents(const set<Student> &students);

    void validUCode(string &code);

    void validyear(string &code);

    const set<Class> getClasses() const;

    void validminimumuc(int &code);

    void validrequest(int &code);

    void setClasses(const set<Class> &classes);

    void removeClass(Class c);

    void removeStudent(Student s1);

    void removeStudentClass(Student s, UCclass uc);

    void UclassOcupationByStudentCode();

    void addStudentClass(Student s, UCclass uc);

    bool isCompatible(vector<Lesson> timetable, vector<Lesson> classLessons );

    bool balanced(UCclass uc, Student s);

    void addtol(Lesson l);

    const vector<Lesson> &getLessons() const;

    void setLessons(const vector<Lesson> &lessons);

    void addtoc(Class c);

    void addtos(Student s);

    void addtou(UCclass uc);

    void timeTableStudent();

    void classOcupationandStudents();

    void classOcupationandStudentsbyStudentcode();

    void UclassOcupationandStudents();

    void studentsMoreThenUc();

    void ucOcupation();

    void yearStudent();

    void fillUCclasses();

    const set<UCclass> &getUClasses() const;

    void setUClasses(const set<UCclass> &uClasses);

    const queue<Request> &getRequests() const;

    void setRequests(const queue<Request> &requests);

    void requestmaker();

    void validStudentCode(int &code);

    Student returnStudent(int code);

    void requestHandler();

    void writeTimeTableStudent();

    void saveAndExit(string filename1,string filename2,string filename3);
};


#endif //PROJAED_UNI_H
