//
// Created by pedro on 30/10/2022.
//

#ifndef PROJAED_LESSON_H
#define PROJAED_LESSON_H

#include <vector>
#include <string>
#include <set>

using namespace std;


class Lesson {
private:
    float duration{};
    string type;
    string day;
    string ucCode;
    string classCode;
    float start{};
public:


    /*!
     * Creates a new Lesson object with a given ucCode, classCode, start, duration, type, day
     * @param ucCode a string representing the lesson ucCode
     * @param classCode a string representing the lesson classCode
     * @param start a float representing the lesson start
     * @param duration a float representing the lesson duration
     * @param type a string representing the lesson type
     * @param day a string representing the lesson day
     */

    Lesson(string ucCode,string classCode, float start, float duration, string type,
           string day);



    /*!
     * Creates a new Lesson object with a given ucCode, classCode, start, duration, type, day
     * @param ucCode a string representing the lesson ucCode
     * @param classCode a string representing the lesson classCode
     */
    Lesson(string ucCode,string classCode);


    /*!
     *returns the ucCode of the lesson
     * @return a string representing the uccCode of the lesson
     */
    const string &getUcCode() const;




    /*!
     * a setter that sets lesson UcCode
     * @param code string representing ucCode that will be set to the lesson
     */

    void setUcCode(const string &code);

    /*!
     * returns the start of the lesson
     * @return a float representing the start of the lesson
     */
    float getStart() const;

    /*!
     * returns the Classcode of the lesson
     * @return a string representing the Classcode of the lesson
     */
    string getClasscode() const;


    /*!
     * a setter that sets the start of the lesson
     * @param start a string that reperesents the start of the lesson
     */
    void setStart(float start);

    /*!
     * returns the duration of the lesson
     * @return a float representing the lesson duration
     */
    float getDuration() const;


    /*!
     * a setter that sets the duration of the lesson
     * @param duration a float that represents the duration of the lesson
     */
    void setDuration(float duration);

    /*!
     * returns the type of the lesson
     * @return a string representing the type of the lesson
     */
    const string &getType() const;


    /*!
     * a setter that sets the type of the lesson
     * @param type a string that represents the type of the lesson
     */
    void setType(const string &type);

    /*!
     * returns the day of the lesson
     * @return a string representing the day of the lesson
     */
    const string &getDay() const;

    /*!
     * a setter that sets the day of the lesson
     * @param day a string that represents the type of the lesson
     */
    void setDay(const string &day);

    /*!
     * overloads the operator < when comparing two lessons (Lesson objects)
     * @param s1 a Lesson that represents the lesson on the right side of the operator
     * @return boolean value, true when the lesson on the right is bigger than the one on the left of the operator based on the lesson classcode and if they are equal on the ucCode
     */
    bool operator<(const Lesson& s1) const;




    /*!
     * overloads operator == when comparing two lessons (lesson Lesson objects)
     * @param s1 Lesson object that represents the lesson on the right side of the operator
     * @return boolean value, true when both classes are equal based on class code
     */
    bool operator==(const Lesson& s1) const;
    /*!
     * prints a lesson
     */


    void printLesson();
    /*!
     * comparative fuction checks if caller lesson and parameter lesson are completely the same(all parameters are equal)
     * @param l lesson to compare with the caller
     * @return boolean value true if the lessons are equal
     */


    bool equals(Lesson l);
};


#endif //PROJAED_LESSON_H
