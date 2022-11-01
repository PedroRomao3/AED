#include <iostream>
#include "Uni.h"

#include <sstream>
#include <fstream>
using namespace std;

int main() {
    Uni *uni = new Uni();

    string myFilePath = "../schedule/classes.csv";
    ifstream in;
    in.open(myFilePath);

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
        getline(inputString,ucCode,',');
        getline(inputString, day,',');
        getline(inputString,tmp,',');
        start = atof(tmp.c_str());
        getline(inputString,tmp,',');
        duration = atof(tmp.c_str());
        getline(inputString,type,',');

        Lesson tlesson = Lesson(ucCode,classCode,start,duration,type,day);
        uni->addto(tlesson);
    }


    return 0;
}