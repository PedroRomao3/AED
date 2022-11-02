//
// Created by pedro on 02/11/2022.
//

#ifndef PROJAED_READFILES_H
#define PROJAED_READFILES_H

#include <fstream>
#include <sstream>
#include "Lesson.h"

using namespace std;

void readfile1(string file, Uni *uni){

    ifstream in;
    in.open(file);

    string line = "";
    getline(in,line);
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
void readfile2(string file, Uni *uni){

}

#endif //PROJAED_READFILES_H
