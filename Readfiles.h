//
// Created by pedro on 02/11/2022.
//

#ifndef PROJAED_READFILES_H
#define PROJAED_READFILES_H

#include <fstream>
#include <sstream>
#include <algorithm>
#include "Lesson.h"
#include "Uni.h"

using namespace std;

void readfile1(string file, Uni *uni) {

    ifstream in;
    in.open(file);

    string line = "";
    getline(in, line);


    while (getline(in, line)) {
        float duration;
        string type;
        string day;
        string ucCode;
        string classCode;
        float start;
        string tmp;
        vector<Lesson> lessons;

        stringstream inputString(line);

        getline(inputString, classCode, ',');
        getline(inputString, ucCode, ',');
        getline(inputString, day, ',');
        getline(inputString, tmp, ',');
        start = atof(tmp.c_str());
        getline(inputString, tmp, ',');
        duration = atof(tmp.c_str());
        getline(inputString, type, ',');

        Lesson lesson = Lesson(ucCode, classCode, start, duration, type, day);
        uni->addtol(lesson);
        lessons.push_back(lesson);
        Class newClass = Class(classCode);
        set<Class> lessonS = uni->getClasses();
        auto iter1 = lessonS.find(newClass);
        auto iter2 = lessonS.end();
        if (iter1 == iter2) {
            Class newClass1 = Class(classCode, lessons);
            uni->addtoc(newClass1);
        } else {
            Class helper = *uni->getClasses().find(newClass);
            vector<Lesson> a = helper.getLessons();
            a.push_back(lesson);
            helper.setLessons(a);
            Class newClass1 = Class(classCode, a);
            uni->removeClass(newClass1);
            uni->addtoc(newClass1);

        }

    }

}


void readfile2(string file, Uni *uni) {

    ifstream in;
    in.open(file);

    string line = "";
    getline(in, line);
    while (getline(in, line)) {
        int StudentCode;
        string StudentName;
        string tmp;
        string ucCode;
        string classCode;

        stringstream inputString(line);

        getline(inputString, tmp, ',');
        StudentCode = atoi(tmp.c_str());
        getline(inputString, StudentName, ',');
        getline(inputString, ucCode, ',');
        getline(inputString, classCode, ',');

        Student newstudent = Student(StudentName, StudentCode);
        set<Student> studentS = uni->getStudents();
        auto iter1 = studentS.find(newstudent);
        auto iter2 = studentS.end();
        if (iter1 == iter2) {
            const Lesson newLesson = Lesson(ucCode,classCode);
            auto it = uni->getLessons().begin();
            while (it != uni->getLessons().end()){
                //find lesson with same(class code e uc code) e adicionar a student  lessons
                if(*it==newLesson){
                    newstudent.addLesson(*it);
                }
                it++;
            }
            uni->addtos(newstudent);
        }
        else{
            Student student1 = *iter1;
            vector<Lesson> newlessons1= student1.getLessons();
            const Lesson newLesson = Lesson(ucCode,classCode);
            auto it = uni->getLessons().begin();
            while (it != uni->getLessons().end()){
                //find lesson with same(class code e uc code) e adicionar a student  lessons
                if(*it==newLesson){
                    newlessons1.push_back(*it);
                }
                it++;
            }
            Student student2 = Student(student1.getName(),student1.getCode(),newlessons1);
            //remover student1
            uni->removeStudent(student1);
            uni->addtos(student2);



        }



    }

}


void readfile3(string file, Uni *uni) {

    ifstream in;
    in.open(file);

    string line = "";
    getline(in, line);
    while (getline(in, line)) {
        string ucCode;
        string classCode;

        stringstream inputString(line);

        getline(inputString, ucCode, ',');
        getline(inputString, classCode, ',');

        UCclass newUCclass = UCclass(ucCode, classCode);
        uni->addtou(newUCclass);


    }
    uni->fillUCclasses();




}



#endif //PROJAED_READFILES_H