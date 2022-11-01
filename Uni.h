//
// Created by pedro on 31/10/2022.
//

#ifndef UNTITLED1_UNI_H
#define UNTITLED1_UNI_H


#include "Student.h"
#include "Class.h"

class Uni {
    vector<Student> students;
    set<Class> classes;
    vector<Lesson> lessons;
public:
    const vector<Student> &getStudents() const;

    void setStudents(const vector<Student> &students);

    const set<Class> &getClasses() const;

    void setClasses(const set<Class> &classes);

    void addto(Lesson l);

};


#endif //UNTITLED1_UNI_H
