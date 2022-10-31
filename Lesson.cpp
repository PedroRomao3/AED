//
// Created by pedro on 30/10/2022.
//

#include "Lesson.h"

Lesson::Lesson(string ucCode,string classCode, float start, float duration, string type, string day) {
    this->ucCode = ucCode;
    this->classCode = classCode;
    this->start = start;
    this->duration = duration;
    this->type = type;
    this->day = day;
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
