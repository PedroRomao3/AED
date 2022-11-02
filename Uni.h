//
// Created by pedro on 31/10/2022.
//

#ifndef PROJAED_UNI_H
#define PROJAED_UNI_H


#include "Student.h"
#include "Class.h"

class Uni {
    vector<Student> students;
    set<Class> classes;
    vector<Lesson> lessons;


public:
    Uni();

    const vector<Student> &getStudents() const;

    void setStudents(const vector<Student> &students);

    const set<Class> getClasses() const;

    void setClasses(const set<Class> &classes);

    void addtol(Lesson l);

    void addtoc(Class c);

    void addtos(Student s);
};


#endif //PROJAED_UNI_H
