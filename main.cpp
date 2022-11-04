#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Uni.h"
#include "Readfiles.h"

using namespace std;

int main() {
    Uni *uni = new Uni();
    string myFile1Path = "../schedule/classes.csv";
    string myFile2Path = "../schedule/students_classes.csv";
    string myFile3Path = "../schedule/classes_per_uc.csv";
    readfile1(myFile1Path, uni);
    readfile2(myFile2Path,uni);
    readfile3(myFile3Path, uni);

    //while (true){}
    //uni->studentsMoreThenUc(2);



    //uni->timeTableStudent();
    //uni->classOcupationandStudents();
    //uni->classOcupationandStudentsbyStudentcode();
    //uni->ucOcupation();
    //uni->yearStudent();
    return 0;
}
