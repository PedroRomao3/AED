//
// Created by pedro on 30/10/2022.
//

#ifndef PROJAED_LESSON_H
#define PROJAED_LESSON_H

#include <vector>
#include <string>
#include <set>

using namespace std;


class Lesson {
private:
    float duration{};
    string type;
    string day;
    string ucCode;
    string classCode;
    float start{};
public:
    Lesson(string ucCode,string classCode, float start, float duration, string type,
           string day);
    Lesson(string ucCode,string classCode);

    const string &getUcCode() const;

    void setUcCode(const string &code);

    float getStart() const;

    string getClasscode() const;

    void setStart(float start);

    float getDuration() const;

    void setDuration(float duration);

    const string &getType() const;

    void setType(const string &type);

    const string &getDay() const;

    void setDay(const string &day);

    bool operator<(const Lesson& s1) const;

    bool operator==(const Lesson& s1) const;

    void printLesson();

    bool equals(Lesson l);
};


#endif //PROJAED_LESSON_H
