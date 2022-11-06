//
// Created by pedro on 05/11/2022.
//

#ifndef PROJAED_MENU_H
#define PROJAED_MENU_H
#include "Uni.h"


class Menu: public Uni {
public:
    Menu();
    void runMenu(Uni *uni);
    void menuSeparator();
    void validOption(int &option,int optionsNumber);

};


#endif //PROJAED_MENU_H
