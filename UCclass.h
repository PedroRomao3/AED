//
// Created by pedro on 03/11/2022.
//

#ifndef PROJAED_UCCLASS_H
#define PROJAED_UCCLASS_H

#include <string>
#include <vector>
#include "Lesson.h"

using namespace std;



class UCclass {
    string ucCode;
    string classCode;
    int NumStudents;
    vector<Lesson> lessons;
public:
    UCclass(const string &ucCode, const string &classCode, int numStudents, const vector<Lesson> &lessons);

    UCclass(const string &ucCode, const string &classCode);

    UCclass(const string &ucCode, const string &classCode, int numStudents);

    const string &getUcCode() const;

    void setUcCode(const string &ucCode);

    const string &getClassCode() const;

    void setClassCode(const string &classCode);

    int getNumStudents() const;

    void setNumStudents(int numStudents);

    UCclass operator=(UCclass uc1);

    bool operator<(UCclass uc1) const;

    bool operator==(UCclass uc1);

    const vector<Lesson> &getLessons() const;

    void setLessons(const vector<Lesson> &lessons);

};


#endif //PROJAED_UCCLASS_H
