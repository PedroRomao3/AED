//
// Created by pedro on 05/11/2022.
//

#include "Menu.h"
using namespace std;

Menu::Menu(){}

void Menu::menuSeparator() {
    cout << endl << endl;
    for (int i = 0; i <= 69; i++) { cout << "="; }
    cout << endl;
}
void Menu::validOption(int &option,int optionsNumber){
    while (cin.fail() || option < 0 || option > optionsNumber)
    {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(100, '\n');
        cin >> option;
    }
    cin.clear();
    cin.ignore(100, '\n');
}

void Menu::runMenu(Uni *uni) {
    int option;


    while (true) {
        menuSeparator();

        cout << "Welcome to the University schedule manager! What do you want to do?" << endl <<
             endl;
        cout << "Please choose what is your option:" << endl <<
             endl;

        cout << "Exit                                                               [0]" <<
             endl;
        cout << "Check student timetable                                            [1]" <<
             endl;
        cout << "Check class occupation and its correspondent students              [2]" <<
             endl;
        cout << "Check students with more than n uc                                 [3]" <<
             endl;
        cout << "Save student timetable on txt file                                 [4]" <<
             endl;
        cout << "Make new student requests                                          [5]" <<
             endl;
        cout << "Next day (Process student requests)                                [6]" <<
             endl;
        cout << "Check uc occupation and its correspondent students                 [7]" <<
             endl;
        cout << "Check students in specific year                                    [8]" <<
             endl;
        cout << "Check class occupation and its students by student code            [9]" <<
             endl;
        cout << "Save and exit                                                     [10]" <<
             endl;

        cout << "Insert the number correspondent to your option: ";
        cin >>
            option;
        validOption(option,
                    11);

        menuSeparator();

        if (option == 0) {
            exit(0);
        } else if (option == 1) {
            uni->timeTableStudent();

        } else if (option == 2) {
            uni->UclassOcupationandStudents();
        } else if (option == 3) {
            uni->studentsMoreThenUc();

        } else if (option == 4) {
            uni->writeTimeTableStudent();

        } else if (option == 5) {
            uni->requestmaker();

        } else if (option == 6) {
            uni->requestHandler();

        } else if (option == 7) {
            uni->ucOcupation();

        } else if (option == 8) {
            uni->yearStudent();

        } else if (option == 9) {
            uni->UclassOcupationByStudentCode();

        } else if (option == 10) {
            uni->saveAndExit("classes.csv","classes_per_uc.csv","students_classes.csv");
        }
    }
}