#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

#include "Request.h"

#define VNT (+7)

using std::cout;
using std::endl;

Request::Request(string hostUsername, string supUserName, string status ,double consumePoint, string timeReq, int id, int hostComment, int supComment) : hostUsername(hostUsername), supUserName(supUserName), timeReq(timeReq), status(status), consumePoint(consumePoint), id(id), hostComment(hostComment), supComment(supComment) {};

string Request::getHostUserName() {return hostUsername;};

string Request::getSupUserName() {return supUserName;};

string Request::getTimeReq() {return timeReq;};

string Request::getStatus() {return status;};

double Request::getConsumePoint() {return consumePoint;};

int Request::getId() {return id;};

bool Request::getHostComment() {return hostComment;};

bool Request::getSupComment() {return supComment;};

//Setter
void Request::setHostComment(bool hostComment) {this->hostComment = hostComment;};

void Request::setSupComment(bool supComment) {this->supComment = supComment;};

void Request::setTimeReq(string timeReq) { this->timeReq = timeReq; };
    
void Request::setStatus(string status) { this->status = status;};
     

RequestList::RequestList(){};

void RequestList::GenerateRequest(const string &hostName, const string &supName, const double &consumePoint) {
    //Get the current time
    time_t rawtime;

    time (&rawtime);

	string timeTemp = ctime(&rawtime);

    //Delete the last character of the string
	while (timeTemp[timeTemp.length() - 1] == '\t' || timeTemp[timeTemp.length() - 1] == '\n') {
		timeTemp.pop_back();
	}

    requestListInfo.push_back(Request(hostName, supName, "Waiting", consumePoint,  timeTemp, requestListInfo.size() + 1));
}

bool RequestList::SaveRequestData() {
    std::ofstream outputFile("data/RequestInfo.txt", std::ios::out);
    if (!outputFile.is_open()) {
        cout << "Error: File not found.\n";
        return false;
    }

    for (Request &req : requestListInfo) {
        outputFile << req.getId() << "\t"
                    << req.getTimeReq() << "\t"
                    << req.getHostUserName() << "\t"
                   << req.getSupUserName() << "\t"
                   << req.getStatus() << "\t"
                    << req.getConsumePoint() << "\t"
                    << req.getHostComment() << "\t"
                    << req.getSupComment() << endl;
    }

    outputFile.close();
    return true;
}

bool RequestList::LoadAllData() {
    std::ifstream inputFile("data/RequestInfo.txt", std::ios::in);

    if (!inputFile.is_open()) {
        cout << "Error: File not found.\n";
        return false;
    }

     //Read file line by line and insert value to list
    while (!inputFile.eof()) {
        string str;
        getline(inputFile, str);
        if (!inputFile) break;
        std::stringstream sts(str);
        string hostUsernameTemp, supUserNameTemp, timeTemp, consumePointTemp, statusTemp, idTemp, hostCommentTemp, supCommentTemp;
        getline(sts, idTemp, '\t');
        getline(sts, timeTemp, '\t');
        getline(sts, hostUsernameTemp, '\t');
        getline(sts, supUserNameTemp, '\t');
        getline(sts, statusTemp, '\t');
        getline(sts, consumePointTemp, '\t');
        getline(sts, hostCommentTemp, '\t');
        getline(sts, supCommentTemp);
        
        requestListInfo.push_back(Request(hostUsernameTemp, supUserNameTemp, statusTemp, std::stod(consumePointTemp), timeTemp, std::stoi(idTemp), std::stoi(hostCommentTemp), std::stoi(supCommentTemp)));
    }

    inputFile.close();
    return true;
}

   