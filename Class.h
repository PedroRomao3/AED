//
// Created by pedro on 31/10/2022.
//

#ifndef PROJAED_CLASS_H
#define PROJAED_CLASS_H

#include <string>
#include "Lesson.h"

using namespace std;

class Class {
    string classCode;
    vector<Lesson> lessons;

public:
    /*!
     * Creates a new Class object with a given code and default lessons(no lessons)
     * @param classCode a string representing the class code
     */
    explicit Class(string classCode);
    /*!
     * Creates a new Class object with given code and given lessons
     * @param classCode a string representing the class code
     * @param lessons a vector of lessons representing the classes lessons
     */

    Class(string classCode, vector<Lesson> lessons);
    /*!
     * returns the code of the class
     * @return a string representing the class code
     */

    const string &getClassCode() const;
    /*!
     * changes the class code to a given new code
     * @param classCode a string representing the class code
     */

    void setClassCode(string classCode);
    /*!
     * returns all the lessons that the caller class has
     * @return a vector of lessons representing all the lessons of the caller class
     */

    const vector<Lesson> getLessons() const;
    /*!
     * changes the classes lessons to a given vector of lessons
     * @param lessons a vector of lessons representing the new classes lessons
     */

    void setLessons(vector<Lesson> lessons);

    /*!
     * defines the operator = which will pass on to the class on the left of the operator the information of the one on the right
     * @param s1 a class that represents the class that will give values to the one on the left of the operator
     * @return a class that represents the class that will receive values from the one on the right of the operator
     */

    Class operator=(Class s1);
    /*!
     * overloads the operator < when comparing two classes (Class objects)
     * @param s1 a class that represents the class on the right side of the operator
     * @return boolean value, true when the class on the right is bigger than the one on the left of the operator based on the class code
     */

    bool operator<(Class s1) const;
    /*!
     * overloads operator == when comparing two classes (class Class objects)
     * @param s1 Class object that represents the class on the right side of the operator
     * @return boolean value, true when both classes are equal based on class code
     */

    bool operator==(Class s1);


};

#endif //PROJAED_CLASS_H