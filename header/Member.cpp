#ifndef _MEMBER_H_
#define _MEMBER_H_

#define fileName1 "memberProfile.txt"
#define fileName2 "supporterDetails.txt"
#define fileName3 "hostDetails.txt"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <map>

//include header file
#include "Member.h" 
#include "System.h"

using std::vector;
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::getline;

//Constructor
Member::Member(string username, string pwd, string fullname, 
    string email, string address, string status, 
    string bestSkill, std::string phoneNum, string position, int creditPoints, 
    double host_ratingScore, double skill_ratingScore, double supporter_ratingScore, string freeTime, int consumePoint, double miniumHostRatingScore) :
    username(username), pwd(pwd), fullname(fullname),
    email(email), address(address), status(status), 
    bestSkill(bestSkill), phoneNum(phoneNum), position(position), creditPoints(creditPoints), 
    host_ratingScore(host_ratingScore), skill_ratingScore(skill_ratingScore), supporter_ratingScore(supporter_ratingScore), freeTime(freeTime), consumePoint(consumePoint), miniumHostRatingScore(miniumHostRatingScore){};

//Show all information
void Member::showInfo() {
    cout << "Username: " << username 
        << "\nFullname: " << fullname 
        << "\nEmail: " << email 
        << "\nAddress: " << address 
        << "\nStatus: " << status 
        << "\nBest Skill: " << bestSkill 
        << "\nPhone Number: " << phoneNum 
        << "\nPosition: " << position 
        << "\nCredit Points: " << creditPoints 
        << "\nHost Rating Score: " << host_ratingScore 
        << "\nSkill Rating Score: " << skill_ratingScore 
        << "\nSupporter Rating Score: " << supporter_ratingScore 
        << "\nFree Time: " << freeTime 
        << "\nConsume Point: " << consumePoint 
        << "\nMinium Host Rating Score: " << miniumHostRatingScore << endl;
};

//Getter
string Member::getUsername() { return username;};

string Member::getPwd() {return pwd;};

string Member::getFullname() {return fullname;};

string Member::getEmail() { return email;};

string Member::getAddress() {return address;};

string Member::getStatus() {return status;};

string Member::getBestSkill() {return bestSkill;};

string Member::getPhoneNum() {return phoneNum;};

string Member::getPosition() {return position;};

int Member::getCreditPoints() {return creditPoints;};

double Member::getHostRatingScore() {return host_ratingScore;};

double Member::getSkillRatingScore() {return skill_ratingScore;};

double Member::getSupporterRatingScore() { return supporter_ratingScore;};

string Member::getFreeTime() {return freeTime;};

int Member::getConsumePoint() {return consumePoint;};

double Member::getMiniumHostRatingScore() {return miniumHostRatingScore;};



//Setter
void Member::setUsername(string username) {this->username = username;};

void Member::setPwd(string pwd) {this->pwd = pwd;};

void Member::setFullname(string fullname) {this->fullname = fullname;};

void Member::setEmail(string email) {this->email = email;};

void Member::setAddress(string address) {this->address = address;};

void Member::setStatus(string status) {this->status = status;};

void Member::setBestSkill(string skill) {this->bestSkill = skill;};

void Member::setPhoneNum(string phoneNum) {this->phoneNum = phoneNum;};

void Member::setCreditPoints(int creditPoints) {this->creditPoints = creditPoints;};

void Member::setHostRatingScore(double host_ratingScore) {this->host_ratingScore = host_ratingScore;};
 
void Member::setSkillRatingScore(double skill_ratingScore) {this->skill_ratingScore = skill_ratingScore;};

void Member::setSupporterRatingScore(double supporter_ratingScore) {this->supporter_ratingScore = supporter_ratingScore;};

void Member::setPosition(string position) {this->position = position;};

void Member::setFreeTime(string freeTime) {this->freeTime = freeTime;};

void Member::setConsumePoint(int consumePoint) {this->consumePoint = consumePoint;};

void Member::setMiniumHostRatingScore(double miniumHostRatingScore) {this->miniumHostRatingScore = miniumHostRatingScore;};

#endif