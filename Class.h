//
// Created by pedro on 31/10/2022.
//

#ifndef PROJAED_CLASS_H
#define PROJAED_CLASS_H

#include <string>
#include "Lesson.h"

using namespace std;

class Class {
    string classCode;
    vector<Lesson> lessons;

public:
    Class(string classCode);

    Class(string classCode, vector<Lesson> lessons);

    const string &getClassCode() const;

    void setClassCode(const string classCode);

    const vector<Lesson> getLessons() const;

    void setLessons(const vector<Lesson> lessons);

    Class operator=(Class s1);


    bool operator<(Class s1) const;

    bool operator==(Class s1);
    
};

#endif //PROJAED_CLASS_H