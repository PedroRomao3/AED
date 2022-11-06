//
// Created by pedro on 30/10/2022.
//
#ifndef PROJAED_STUDENT_H
#define PROJAED_STUDENT_H

#include <string>
#include "Lesson.h"

using namespace std;

class Student {
    string name;
    int code;
    vector<Lesson> timetable;

public:


    /*!
    * Creates a new Student object with a given code and default timetable(no timetable)
    * @param code an integer representing the Student code
    */
    Student(int code);


    /*!
    * Creates a new Student object with a default name(no name), default code(no code) and default timetable(no timetable)
    */
    Student();

    /*!
     * Creates a new Student object with a given name and a given code and a default timetable(no timetable)
     * @param name a string representing the student name
     * @param code an integer representing the student code
     */

    Student(string name, int code);


    /*!
     * Creates a new Student object with a given name, a given code and a timetable
     * @param name a string representing the student name
     * @param code an integer representing the student code
     * @param timetable a vector of lessons representing the student timetable
     */
    Student(string name, int code, vector<Lesson> timetable);


    /*!
     * defines the operator = which will pass on to the student on the left of the operator the information of the one on the right
     * @param s1 a student that represents the student that will give values to the one on the left of the operator
     * @return a student that represents the student that will receive values from the one on the right of the operator
     */
    Student operator=(Student s1);



    /*!
     * returns the name of the student
     * @return a string representing the student name
     */
    string getName();



    /*!
     * returns the code of the student
     * @return an integer representing the student code
     */
    int getCode() const;

    /*!
     * adds a lesson to the student's timetable
     * @param l1 class Lesson object that represents the lesson to be added to the student's timetable
     */
    void addLesson(Lesson l1);

    /*!
     * a getter that returns caller student's lessons
     * @return vector of lessons representing the students lessons
     */

    vector<Lesson> getLessons() const;
    /*!
     * a setter that sets students lessons to a given vector of lessons
     * @param x vector of Lesson objects representing lessons that will be set to the student
     */

    void setLessons(vector<Lesson> x) ;
    /*!
     * ovreloads operator < when comparing two students(class Student objects)
     * @param s1 a student that represents the student on the right side of the operator
     * @return boolean value, true if the student on the right side of the operator is bigger than the on on the left based on student code
     */

    bool operator<(const Student& s1) const;
    /*!
     * overloads operator == when comparing two students(class Student objects)
     * @param s1 a student
     * @return boolean value, true if students are equal based on student code
     */

    bool operator==(const Student& s1);
    /*!
     * prints all the lessons of the student
     */

    void printTimetable();

};

#endif //PROJAED_STUDENT_H
