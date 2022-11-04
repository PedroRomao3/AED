//
// Created by pedro on 03/11/2022.
//

#ifndef PROJAED_UCCLASS_H
#define PROJAED_UCCLASS_H

#include <string>
#include <vector>
#include "Lesson.h"
#include "Student.h"

using namespace std;



class UCclass {
    string ucCode;
    string classCode;
    set<Student> students;
    vector<Lesson> lessons;
public:
    UCclass(const string &ucCode, const string &classCode, int numStudents, const vector<Lesson> &lessons);

    UCclass(const string &ucCode, const string &classCode);

    UCclass(const string &ucCode, const string &classCode, int numStudents);

    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    const string &getClassCode() const;

    void setClassCode(const string &classCode);

    const set<Student> &getStudents() const;

    void setStudents(const set<Student> &students);

    UCclass operator=(UCclass uc1);

    bool operator<(UCclass uc1) const;

    bool operator==(UCclass uc1);

    const vector<Lesson> &getLessons() const;

    void setLessons(const vector<Lesson> &lessons);

};


#endif //PROJAED_UCCLASS_H
