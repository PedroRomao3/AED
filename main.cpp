#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Uni.h"
using namespace std;

int main() {
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
    return 0;
}