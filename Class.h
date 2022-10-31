//
// Created by pedro on 31/10/2022.
//

#ifndef UNTITLED1_CLASS_H
#define UNTITLED1_CLASS_H

#include <string>
#include "Lesson.h"

using namespace std;

class Class {
    string classCode;
    vector<Lesson> timetable;

public:
    Class(string classCode);

    Class(string classCode, vector<Lesson> timetable);

    const string &getClassCode() const;

    void setClassCode(const string &classCode);

    const vector<Lesson> &getTimetable() const;

    void setTimetable(const vector<Lesson> &timetable);
};

#endif //UNTITLED1_CLASS_H