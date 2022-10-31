//
// Created by pedro on 31/10/2022.
//

#ifndef UNTITLED1_UC_H
#define UNTITLED1_UC_H

#include <string>
#include "Class.h"

using namespace std;

class Uc {
    string code;
    vector<Class> vector;
public:
    Uc(string x, std::vector<Class> y){
        this->code = x;
        this->vector = y;
    }

};


#endif //UNTITLED1_UC_H
