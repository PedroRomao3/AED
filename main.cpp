#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Uni.h"
using namespace std;

#include <sstream>
#include <fstream>
using namespace std;

int main() {
<<<<<<< HEAD
    /* C:/Users/migue/OneDrive/Desktop/Feup/FEUP/ano2_semestre1/AED/projeto_1/AED/schedule/classes.csv */
    string myFilePath = "..\\schedule\\classes.csv";
    ifstream in;

    in.open(myFilePath);

    if(in.fail()){
        cerr << "unable to open the file " << myFilePath << endl;
        return 1;
    }

    while(in.peek() != EOF){
        string records;
        getline(in, records, ',');
        cout << records << endl;
    }

    in.close();
=======
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


>>>>>>> 11aaa86dbca347187d95b26ddffd3e520ea415fd
    return 0;
}