#include <iostream>

#include "Comment.h"

using std::cout;
using std::endl;

//Constructor
Comment::Comment(string time, string hostName, string supName, string comment, double skill_score, double host_score, double sup_score, int idReq) : time(time), hostName(hostName), supName(supName), comment(comment), skill_score(skill_score), host_score(host_score), sup_score(sup_score), idReq(idReq) {};

//Show info
void Comment::showSupComment() {
    cout << time << "\tSkill score: " <<  skill_score << "\tSupporter Score: " << sup_score << "\tComment: " << comment << endl;
}

//Show info
void Comment::showHostComment() {
    cout << time << "\tHost score: " <<  host_score << "\tComment: " << comment << endl;
}

//Getter
    string Comment::getTime() { return time; };

    double Comment::getSkillScore() { return skill_score; };

    double Comment::getHostScore() { return host_score; };

    double Comment::getSupScore() { return sup_score; };

    string Comment::getHostName() { return hostName; };

    string Comment::getSupName() { return supName; };
    
    string Comment::getComment() { return comment; };


