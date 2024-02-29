#include <iostream>
#include <vector>


using std::string;
using std::vector;

class Request {
private:
    string hostUsername;
    string supUserName;
    string timeReq;
    string status;
    double consumePoint;
    int id;
    int hostComment, supComment;
public: 
    Request(string hostUsername = "N/A", string supUserName = "N/A", string status = "None", double consumePoint = 0, string timeReq = "N/A", int id = 0, int hostComment = 0, int supComment = 0);

    //Getter
    string getHostUserName();
    string getSupUserName();
    int getId();
    string getTimeReq();
    string getStatus();
    double getConsumePoint();
    bool getHostComment();
    bool getSupComment();

    //Setter
    void setTimeReq(string timeReq);
    void setStatus(string status);
    void setHostComment(bool hostComment);
    void setSupComment(bool supComment);
};

class RequestList {
public:
    vector<Request> requestListInfo;

    RequestList();

    void GenerateRequest(const string &hostName, const string &supName, const double &consumePoint);

    bool SaveRequestData();

    bool LoadAllData();
};