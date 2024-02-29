#ifndef _COMMENT_H_
#define _COMMEMT_H_

#include <iostream>
#include <string>

using std::string;

class Comment {
private:
    string time;
    double skill_score, host_score, sup_score;
    string hostName;
    string supName;
    string comment;
    int idReq;

public: 
    //Constructor
    Comment(string time = "", string hostName = "", string supName = "", string comment = "", double skill_score = 0, double host_score = 0, double sup_score = 0, int idReq = 0);

    //Show supporter comment
    void showSupComment();

    //Show host comment
    void showHostComment();

    //Getter
    string getTime();

    double getSkillScore();

    double getHostScore();

    double getSupScore();

    string getHostName();

    string getSupName();
    
    string getComment();

};

#endif
