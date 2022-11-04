//
// Created by pedro on 31/10/2022.
//

#ifndef PROJAED_UNI_H
#define PROJAED_UNI_H


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


public:

    Uni();

    const set<Student> &getStudents() const;

    void setStudents(const set<Student> &students);

    const set<Class> getClasses() const;

    void setClasses(const set<Class> &classes);

    void removeClass(Class c);

    void removeStudent(Student s1);

    void removeStudentClass(Student s, UCclass uc);

    void addtol(Lesson l);

    const vector<Lesson> &getLessons() const;

    void setLessons(const vector<Lesson> &lessons);

    void addtoc(Class c);

    void addtos(Student s);

    void addtou(UCclass uc);

    void timeTableStudent();

    void classOcupationandStudents();

    void classOcupationandStudentsbyStudentcode();

    void studentsMoreThenUc();

    void ucOcupation();

    void yearStudent();

    void fillUCclasses();

    const set<UCclass> &getUClasses() const;

    void setUClasses(const set<UCclass> &uClasses);

    const queue<Request> &getRequests() const;

    void setRequests(const queue<Request> &requests);

    void requestmaker();

    void requestHandler();
};


#endif //PROJAED_UNI_H
