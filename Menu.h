//
// Created by pedro on 05/11/2022.
//

#ifndef PROJAED_MENU_H
#define PROJAED_MENU_H
#include "Uni.h"


class Menu: public Uni {
public:
    /*!
     * constructor creates a new Menu object
     */

    Menu();
    /*!
     * runs the terminal interface that controls entire schedule manager
     * @param uni Uni class object passed on to the menu so that it has all the information to process user requests
     */
    void runMenu(Uni *uni);
    /*!
     * prints a separator on the menu to make the menu more organized
     */
    void menuSeparator();
    /*!
     * checks if a certain user input for an option of the menu is valid and will not cause any problems
     * @param option a number that defines the option the user chose
     * @param optionsNumber total nu,ber of options
     */
    void validOption(int &option,int optionsNumber);

};


#endif //PROJAED_MENU_H
