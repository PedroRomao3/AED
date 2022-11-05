#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Uni.h"
#include "Readfiles.h"

using namespace std;
int CAP = 30;
int main() {
    cout << "Welcome to the schedule management system!\n";
    Uni *uni = new Uni();
    string myFile1Path = "../schedule/classes.csv";
    string myFile2Path = "../schedule/students_classes.csv";
    string myFile3Path = "../schedule/classes_per_uc.csv";
    readfile1(myFile1Path, uni);
    readfile2(myFile2Path,uni);
    readfile3(myFile3Path, uni);
    /*
        3LEIC08
        L.EIC022
        3LEIC04
        L.EIC021
      */
    /*
        cout << "If you want to: " << endl;
        cout << "Print timetable of student"<< endl;


        */

    //uni->writeTimeTableStudent();
    //uni->timeTableStudent();
    uni->timeTableStudent();
    uni->requestmaker();
    //uni->timeTableStudent();JUNGLE
    uni->requestHandler();
    uni->timeTableStudent();
    //uni->writeTimeTableStudent();
    //uni->timeTableStudent();
    //uni->timeTableStudent();
    //202025572,Adelaide,L.EIC002,1LEIC13
    //requestmake();
    //requestHandle(queue requests);

    //while (true){}
    //uni->studentsMoreThenUc(2);
    //1,202040617,3LEIC12,L.EIC021
    //2,202040617,L.EIC003,1LEIC13

    //uni->timeTableStudent();
    //uni->classOcupationandStudents();
    //uni->classOcupationandStudentsbyStudentcode();
    //uni->ucOcupation();
    //uni->yearStudent();
    return 0;
}



/*
0 - horario do aluno (codigo do estudante)timetablestudent
1 - ocupacao ucclass e estudantes (codigo uc,codigo class-->set.size) uclass occupation
2 - estudantes com mais de n ucs(n) studentsmorethen
3 - get studant timetable on txt file (student code)writetimetablestudent
4 - fazer pedidos (cout 1-add student 2- remove ...)requestmaker
5- processar pedidos */
