#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Uni.h"
#include "Readfiles.h"
#include "Menu.h"

using namespace std;
int CAP = 30;
int main() {
    cout << "Loading schedule management system!\n";
    cout << "0              100\n";
    Uni *uni = new Uni();
    string myFile1Path = "../schedule/classes.csv";
    string myFile2Path = "../schedule/students_classes.csv";
    string myFile3Path = "../schedule/classes_per_uc.csv";
    cout << "40 =====       100\n";
    readfile1(myFile1Path, uni);
    cout << "80 =========   100\n";
    readfile2(myFile2Path,uni);
    cout << "90 ==========  100\n";
    readfile3(myFile3Path, uni);
    cout << "100=========== 100\n";
    Menu menu = Menu();

    menu.runMenu(uni);
    return 0;
}

