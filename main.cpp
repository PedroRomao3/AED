#include <iostream>
#include "Uni.h"

#include <sstream>
#include <fstream>
using namespace std;

int main() {
    Uni *uni = new Uni();

    string myFilePath = "../schedule/classes.csv";
    ifstream in;

    in.open(myFilePath);

    if(in.fail()){
        cerr << "unable to open the file " << myFilePath << endl;
        return 1;
    }

    while(in.peek() != EOF){
        string records;

        float duration;
        string type;
        string day;
        string ucCode;
        string classCode;
        float start;

        for (int i = 0; i < 6;i++) {
            getline(in, records, ',');
            switch (i) {
                case 0:
                    classCode = records; break;
                case 1:
                    ucCode = records; break;
                case 2:
                    day = records; break;
                case 3:
                    start = stof(records); break;
                case 4:
                    duration = stof(records); break;
                case 5:
                    type = records; break;
            }

        Lesson tlesson = Lesson(ucCode,classCode,start,duration,type,day);
        uni->addto(tlesson);


        }
    }


    in.close();
    return 0;
}



/*
        iss >> classCode;
        iss >> ucCode;
        iss >> day;
        iss >> start;
        iss >> duration;
        iss >> type;
        Lesson tlesson = Lesson(ucCode,classCode,start,duration,type,day);
        vl.push_back(tlesson);
    }

    std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
{
    std::vector<std::string>   result;
    std::string                line;
    std::getline(str,line);

    std::stringstream          lineStream(line);
    std::string                cell;

    while(std::getline(lineStream,cell, ','))
    {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }
    return result;
}
    */

/*
    float duration;
    string type;
    string day;
    string ucCode;
    string classCode;
    float start;
    iss >> classCode;
    iss >> ucCode;
    iss >> day;
    iss >> start;
    iss >> duration;
    iss >> type;
    Lesson tlesson = Lesson(ucCode,classCode,start,duration,type,day);


    return 0;

}
*/