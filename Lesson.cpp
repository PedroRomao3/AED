//
// Created by pedro on 30/10/2022.
//

#include "Lesson.h"

#include <utility>
Lesson::Lesson(string ucCode,string classCode) {
    this->ucCode = std::move(ucCode);
    this->classCode = std::move(classCode);
}

Lesson::Lesson(string ucCode,string classCode, float start, float duration, string type, string day) {
    this->ucCode = std::move(ucCode);
    this->classCode = std::move(classCode);
    this->start = start;
    this->duration = duration;
    this->type = std::move(type);
    this->day = std::move(day);
}

const string &Lesson::getUcCode() const {
    return ucCode;
}

void Lesson::setUcCode(const string &ucCode) {
    Lesson::ucCode = ucCode;
}
float Lesson::getStart() const {
    return start;
}

void Lesson::setStart(float start) {
    Lesson::start = start;
}

float Lesson::getDuration() const {
    return duration;
}

void Lesson::setDuration(float duration) {
    Lesson::duration = duration;
}

const string &Lesson::getType() const {
    return type;
}

void Lesson::setType(const string &type) {
    Lesson::type = type;
}

const string &Lesson::getDay() const {
    return day;
}

void Lesson::setDay(const string &day) {
    Lesson::day = day;
}

bool Lesson::operator<(const Lesson &s1) const {
    if(s1.classCode == this->classCode){
        return (s1.ucCode < this->ucCode);
    }
    else{return (s1.classCode < this->classCode);}
}

bool Lesson::operator==(const Lesson &s1) const {
    return (s1.classCode == this->classCode && s1.ucCode == this->ucCode);
}


