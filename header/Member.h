#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include <vector>

class System;


using std::string;
using std::vector;



class Member{
    private:
        string username, pwd, fullname;
        string email, address, status;
        string bestSkill;
        string phoneNum, position, freeTime;
        int creditPoints, consumePoint;
        double host_ratingScore, skill_ratingScore, supporter_ratingScore, miniumHostRatingScore;

    public: 
        //Constructor
        Member(string username = "N/A", string pwd = "N/A", string fullname = "N/A", 
                string email = "N/A", string address = "N/A", string status = "Unavailable", 
                string bestSkill = "N/A", 
                std::string phoneNum = "N/A", string position = "Supporter",
                int creditPoints = 20,  
                double host_ratingScore = 0, double skill_ratingScore = 0, double supporter_ratingScore = 0, string freeTime = "N/A", int consumePoint = 0, double miniumHostRatingScore = 0);
        
        //Show all information
        void showInfo();

        //Getter
        string getUsername();

        string getPwd();

        string getFullname();

        string getEmail();

        string getAddress();

        string getStatus();

        string getBestSkill();

        string getPhoneNum();

        string getPosition();

        int getCreditPoints();

        double getHostRatingScore();

        double getSkillRatingScore();

        double getSupporterRatingScore();

        string getFreeTime();

        int getConsumePoint();

        double getMiniumHostRatingScore();

        //Setter
        void setUsername(string username);

        void setPwd(string pwd);

        void setFullname(string fullname);

        void setEmail(string email);

        void setAddress(string address);

        void setStatus(string status);

        void setBestSkill(string skill);

        void setPhoneNum(string phoneNum);

        // void setSchedule(string time);

        void setCreditPoints(int creditPoints);

        void setHostRatingScore(double host_ratingScore);

        void setSkillRatingScore(double skill_ratingScore);

        void setSupporterRatingScore(double supporter_ratingScore);

        void setPosition(string position);

        void setFreeTime(string freeTime);

        void setConsumePoint(int consumePoint);

        void setMiniumHostRatingScore(double miniumHostRatingScore);

        

};

#endif