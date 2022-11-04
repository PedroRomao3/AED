//
// Created by pedro on 30/10/2022.
//

#include "Student.h"

Student::Student(string name, int code) {
    this->name = name;
    this->code = code;
}
Student::Student(int code) {this->code=code;}

Student::Student(string name, int code, vector<Lesson> timetable) {
    this->name = name;
    this->code = code;
    this->timetable = timetable;
}

Student Student::operator=(Student s1) {
    this->code = s1.code;
    this->name = s1.name;
    this->timetable = s1.timetable;
    return *this;
}

string Student::getName(){
    return this->name;
}


bool Student::operator<(const Student& s1) const {
    return (s1.name>this->name);

}

bool Student::operator==(const Student& s1) {
    return (s1.code==this->code);
}

void Student::addLesson(Lesson l1) {
    this->timetable.push_back(l1);

}

vector<Lesson> Student::getLessons() const {
    return timetable;
}

int Student::getCode() const {
    return this->code;
}

void Student::setLessons(vector<Lesson> x) {
    this->timetable = x;
}

void Student::printTimetable() {
    //vector<Lesson> horario = student.timetable;
    for (Lesson lesson : timetable){
        lesson.printLesson();
    }
}

Student::Student() {
    this->code = 0;
}
