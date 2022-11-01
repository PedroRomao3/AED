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
    Uni();
    const vector<Student> &getStudents() const;

    void setStudents(const vector<Student> &students);

    const set<Class> &getClasses() const;

    void setClasses(const set<Class> &classes);

<<<<<<< HEAD
    Uni operator = (Uni uni1);

=======
    void addto(Lesson l);
>>>>>>> 11aaa86dbca347187d95b26ddffd3e520ea415fd

};


#endif //UNTITLED1_UNI_H
