//
// Created by pedro on 02/11/2022.
//

#ifndef PROJAED_READFILES_H
#define PROJAED_READFILES_H

#include <fstream>
#include <sstream>
#include "Lesson.h"

using namespace std;

void readfile1(string file, Uni *uni) {

    ifstream in;
    in.open(file);

    string line = "";
    getline(in, line);

    /*
    while (getline(in,line)){
        float duration;
        string type;
        string day;
        string ucCode;
        string classCode;
        float start;
        string tmp;

        stringstream inputString(line);

        getline(inputString,classCode,',');
        Class oclass = Class(classCode);
        //uni->addtoc(oclass);

        getline(inputString,ucCode,',');
        getline(inputString, day,',');
        getline(inputString,tmp,',');
        start = atof(tmp.c_str());
        getline(inputString,tmp,',');
        duration = atof(tmp.c_str());
        getline(inputString,type,',');

        Lesson tlesson = Lesson(ucCode,classCode,start,duration,type,day);
        uni->addtol(tlesson);
    }
}
     */
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

            stringstream inputString(line);

            getline(inputString, tmp, ',');
            StudentCode = atoi(tmp.c_str());
            getline(inputString, StudentName, ',');

            Student newstudent = Student(StudentName, StudentCode);
            uni->addtos(newstudent);
        }

    }

#endif //PROJAED_READFILES_H
