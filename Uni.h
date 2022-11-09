//
// Created by pedro on 31/10/2022.
//

#ifndef PROJAED_UNI_H
#define PROJAED_UNI_H

#include <stack>
#include <queue>
#include "Student.h"
#include "Class.h"
#include "UCclass.h"
#include "Request.h"

class Uni {
    set<Student> students;
    set<Class> classes;
    vector<Lesson> lessons;
    set<UCclass> uClasses;
    queue<Request> requests;
    stack<Request> invalidrequest;


public:


    /*!
     * Creates a new Lesson object with default atributes
     */
    Uni();


    /*!
     * returns the students of the uni
     * @return a set of students of the uni
     */
    const set<Student> &getStudents() const;


    /*!
     * verifies if the class code is possible
     * @param code string representing a class code
     */
    void validClassCode(string &code);

    /*!
     * a setter that sets uni students
     * @param students a set of students representing the students that will be set to uni
     */
    void setStudents(const set<Student> &students);


    /*!
     * verifies if the UcCode is possible
     * @param code string representing a UcCode
     * Complexity(n)
     * */
    void validUCode(string &code);

    /*!
     * verifies if the Year is valid
     * @param code string representing the year
     * Complexity: O(n)
     */
    void validyear(string &code);

    /*!
     * returns the classes of the uni
     * @return a set of classes of the uni
     */
    const set<Class> getClasses() const;


    /*!
     * verifies if the minimum number of uc's is valid
     * @param code an integer representing the minimum number of uc's
     */
    void validminimumuc(int &code);

    /*!
     * verifies if the request is valid
     * @param code an integer representing the number of the request
     */
    void validrequest(int &code);

    /*!
     * a setter that sets uni classes
     * @param classes a set of classes representing the classes that will be set to uni
     */
    void setClasses(const set<Class> &classes);

    /*!
     * remove class from the uni
     * @param c a Class that we want to remove from the classes of the uni
     */
    void removeClass(Class c);

    /*!
     * remove student from uni
     * @param s1 a Student that we want to remove from the students of the uni
     * Complexity: O(n)
     */
    void removeStudent(Student s1);

    /*!
     *  removes student from class/UC
     * @param s a Student we want to remove
     * @param uc a UCclass representing the UCclass of the student
     * Complexity: O(n)
     */
    void removeStudentClass(Student s, UCclass uc);

    /*!
     * prints the students of the class and the uc by student code
     */
    void UclassOcupationByStudentCode();

    /*!
     * adds a student s to the class/UC
     * @param s a Student we want to add to a class/UC
     * @param uc a UCclass representing the uc we want the student to be added
     */
    void addStudentClass(Student s, UCclass uc);

    /*!
     * verivies is the timetable of the student is compatible with the timetable of the class
     * @param timetable a vector of lessons representing the timetable of the sudent
     * @param classLessons a vector of lessons representing the timetable of the class
     * @return a bool evaluating if the timetables are compatable or not
     */
    bool isCompatible(vector<Lesson> timetable, vector<Lesson> classLessons );

    /*!
     *checks if changing student S(2nd parameter) to the class uc(first argument) makes the classes of that UC unbalanced (difference of 4 students)
     * @param uc the class
     * @param s the student
     * @return boolean value, true when its possible to make the change because classes wont be unbalanced
     */
    bool balanced(UCclass uc, Student s);

    /*!
     * add a lesson to lessons
     * @param l represents a lesson we want to add
     */
    void addtol(Lesson l);
    /*!
     * returns  all the lessons
     * @return a vector of all lessons
     */

    const vector<Lesson> &getLessons() const;

    /*!
     * changes the university lessons to the ones received as parameter
     * @param lessons a vector of lessons representing the lessons we want to set
     */

    void setLessons(const vector<Lesson> &lessons);
    /*!
     * adds class c to the university classes
     * @param c a class to be added to the university classes
     */

    void addtoc(Class c);

    /*!
     * adds student given in the parameter to the university set of students
     * @param s
     */
    void addtos(Student s);

    /*!
     * adds an uc to the Uclasses
     * @param uc represents an uc we want to insert in the Uclasses
     */
    void addtou(UCclass uc);

    /*!
     * prints the timetable of the student, being passed by user input the code of the student
     */
    void timeTableStudent();

    /*!
     * prints the Students of the class and its ocupation, class being passed by user input
     */
    void classOcupationandStudents();

    /*!
     * prints the Students of the class ordered by student code and its ocupation, class being passed by user input
     */
    void classOcupationandStudentsbyStudentcode();


    /*!
     * prints the class/UC ocupation, class and UC being passed by user input
     */
    void UclassOcupationandStudents();


    /*!
     * prints the students with mone than n ucs, n being passed by user input
     */
    void studentsMoreThenUc();


    /*!
     * prints the uc ocupation, uc being passed by user input
     */
    void ucOcupation();

    /*!
     * prints the year of the student, year being passed by user input
     */
    void yearStudent();

    /*!
     * fills the uClasses of the uni
     */
    void fillUCclasses();


    /*!
     * returns the UCclasses of the uni
     * @return a set if UCclasses of the uni
     */
    const set<UCclass> &getUClasses() const;



    /*!
     * a setter that sets the Uclasses of the uni
     * @param uClasses a set of UCclass that will the set to the uni
     */
    void setUClasses(const set<UCclass> &uClasses);


    /*!
     * returns the requests of the uni
     * @return a queue of request representing the requests of the uni
     */
    const queue<Request> &getRequests() const;

    /*!
     *  a setter that sets the new queue of requests
     * @param requests a queue of requests that will be set to the uni requests
     */
    void setRequests(const queue<Request> &requests);


    /*!
     * makes the user requests and stores them in a queue for future handling
     */
    void requestmaker();
    /*!
     * checks if the student code provided by the input is valid if it is not asks for a new one until it is
     * @param code first code provded
     */

    void validStudentCode(int &code);
    /*!
     * returns a student based on student code
     * @param code the student code
     * @return the Student
     */

    Student returnStudent(int code);
    /*!
     * handles the requests made by the user all at once
     */

    void requestHandler();

    /*!
     * writes the timetable of the student on a file txt
     */
    void writeTimeTableStudent();
    /*!
     * exits the schedule manager and stores in files the information for future use
     * @param filename1 file number one where information will be stored
     * @param filename2 file number two where information will be stored
     * @param filename3 file number three where information will be stored
     */

    void saveAndExit(string filename1,string filename2,string filename3);
};


#endif //PROJAED_UNI_H
