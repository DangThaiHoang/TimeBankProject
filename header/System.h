#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Member.h"
#include "Request.h"
#include "Comment.h"
#include "BlockMem.h"


using std::string;



class Request;

class System {
public:
        vector<Member> memList;
        vector<Comment> supCommentList;
        vector<Comment> hostCommentList;
        RequestList reqList;
        vector<BlockMem> blockMemList;
        
        //Constructor
        System(){};

        //Load all data from the memeber file
        bool loadMemData();

        //Find member depends on username
        int findMem(string username);

        //Find member depends on location
        int findAddress(string address);

        //Show all supporter member using by member
        void showAllSupporters(const string &username);

        //Show all supporter member using by guest
        void showAllSupporters();

        //Update status of the member
        bool updateStatus(const string &username);

        //Update host rating score
        bool updateHostRatingScore(const string &username, double score);

        //Update skill rating score
        bool updateSkillRatingScore(const string &username, double score);

        //Update supporter rating score
        bool updateSupporterRatingScore(const string &username, double score);

        //Save all data to file
        bool saveMemData();

        //Save all data to file
        bool saveAllData();
        
        //Read all data from file
        bool loadAllData();

        //Show the menu for the host member
        int showHostMenu(const string &username);

        //Show the menu for the supporter member
        int showSupporterMenu(const string &username);

        //View the status of the member
        void viewStatus(const string &username);

        //View the user profile
        void viewProfile(const string &username);

        //Update the user pofile
        bool updateProfile(const string &username);

        //Show the host score
        void showHostScore();

        //Show the supporter score
        void showSupporterScore();

        //Block the other supporter
        void blockSupporter(const string &username);

        //View the request from the host 
        bool viewBookedRequests(const string &username);

        //Search the supporter by their location
        void searchSupByLocation(const string &username);

        //Search the supporter by their location
        void searchSupByFreeTime(const string &username);

        //Check whether input information of account is correct or not
        bool isMemberLoginValid(const string &username1, const string &pwd1);

        //Finish the request
        bool finishRequest(const string &supName);

        //Register member account
        Member registerMem();

        //Check wether the username is exist in data file
        bool checkUsername(const string &username);
        
        //Change password of the member using temporary password
        bool changePwd(const string &username);

        //Book the suppporter
        void bookSup(const string &username);

        //Add credit point when the supporter complete the request
        bool addCreditPoints(const string &username);

        //Reduce credit point when the host book the supporter
        bool reduceCredit(const string &username);      

        //Add comment is used by host
        bool addHostComment(const string &hostName, const string &supName, const int idReq);

        //Add comment is used by supporter
        bool addSupComment(const string &hostName, const string &supName, const int idReq);

        //Load all comment from file
        bool loadSupComment();

        //Load all comment from file
        bool loadHostComment();

        //Find comment by the given host name
        bool findHostComment(const string &hostName);

        //Find comment by the given supporter name
        bool findSupComment(const string &supName);

        //Save all comment to file
        bool saveHostComment();

        //Save all comment to file
        bool saveSupComment();

        //Update position
        void updatePosition(const string &username);

        //reply the request
        bool replyRequest(const string &username);    

        //Get the current time
        string generateTime();

        //Find position of the request
        int findRequest(const string &hostName, const string &supName);

        //Add comment using by host
        void addCommentForHost(const string &username);

        //Add comment using by supporter
        void addCommentForSup(const string &username);

        //Show all pending request
        void showHostPendingRequest(const string &hostName);
        void showSupPendingRequest(const string &supName);

        //Load block member list
        bool loadBlockMem();

        //Save block member list
        bool saveBlockMem();

        //Erase non-accepted request with overllaped time
        void eraseNonAcceptedRequest();

        int findBlockedMem(const string &blockedMem, const string &memBlock);

};

#endif
