//
// Created by pedro on 30/10/2022.
//

#ifndef UNTITLED1_LESSON_H
#define UNTITLED1_LESSON_H

#include <vector>
#include <string>
#include <set>

using namespace std;


class Lesson {
private:
    float duration;
    string type;
    string day;
    string ucCode;
    string classCode;
    float start;
public:
    Lesson(string ucCode,string classCode, float start, float duration, string type,
           string day);

    const string &getUcCode() const;

    void setUcCode(const string &code);

    float getStart() const;

    void setStart(float start);

    float getDuration() const;

    void setDuration(float duration);

    const string &getType() const;

    void setType(const string &type);

    const string &getDay() const;

    void setDay(const string &day);
};


#endif //UNTITLED1_LESSON_H
