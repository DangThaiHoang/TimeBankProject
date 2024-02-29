#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class Admin{
private:
    string username;
    string password;
    map<string, string> AdminInfoList;

public:
    Admin(string username = "", string password = "");

    //Load all data from file
    bool loadAdminInfo();

    //Login to the system using admin acocunt
    bool login();

    //Generate temporary password, then save it to file
    void resetPwd();

    //Show admin menu
    bool showAdminMenu();
};

#endif