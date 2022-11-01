//
// Created by pedro on 31/10/2022.
//

#ifndef UNTITLED1_UNI_H
#define UNTITLED1_UNI_H


#include "Student.h"
#include "Class.h"

class Uni {
    vector<Student> students;
    vector<Class> classes;
    vector<Lesson> lessons;
public:
    Uni();
    const vector<Student> &getStudents() const;

    void setStudents(const vector<Student> &students);

    const vector<Class> &getClasses() const;

    void setClasses(const vector<Class> &classes);

    Uni operator = (Uni uni1);


};


#endif //UNTITLED1_UNI_H
