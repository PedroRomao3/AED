//
// Created by pedro on 31/10/2022.
//

#ifndef PROJAED_UNI_H
#define PROJAED_UNI_H


#include "Student.h"
#include "Class.h"
#include "UCclass.h"

class Uni {
    set<Student> students;
    set<Class> classes;
    vector<Lesson> lessons;
    set<UCclass> uClasses;


public:

    Uni();

    const set<Student> &getStudents() const;

    void setStudents(const set<Student> &students);

    const set<Class> getClasses() const;

    void setClasses(const set<Class> &classes);

    void removeClass(Class c);

    void removeStudent(Student s1);

    void addtol(Lesson l);

    const vector<Lesson> &getLessons() const;

    void setLessons(const vector<Lesson> &lessons);

    void addtoc(Class c);

    void addtos(Student s);

    void addtou(UCclass uc);

    void timeTableStudent();

    void classOcupationandStudents();

    void classOcupationandStudentsbyStudentcode();

    void studentsMoreThenUc(int n);

    void ucOcupation();

    void yearStudent();

    void fillUCclasses();
};


#endif //PROJAED_UNI_H
