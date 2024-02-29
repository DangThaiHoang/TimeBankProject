#include <iostream>
#include "Admin.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::map;

//Constructor
Admin::Admin(string username, string pwd) : username(username), password(pwd){};

//Load all data in admin info file
bool Admin::loadAdminInfo() {
        std::ifstream inputFile("data/admin.txt", std::ios::in);
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
            string username, pwd;
            getline(sts, username, ' ');
            getline(sts, pwd);
            Admin::AdminInfoList.insert({username, pwd});
        }

        inputFile.close();
        return true;
            
}

//Login
bool Admin::login() {
    cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
    while (1) {
        cout << "Welcome to Admin Page!" << endl;
        cout << "> Please enter your username: ";
        string username , pwd;
        getline(cin >> std::ws, username);
        cout << "> Please enter your password: ";
        getline(cin >> std::ws, pwd);

        //Check if username and password exist
        if (Admin::AdminInfoList.find(username) != Admin::AdminInfoList.end()) {
            if (Admin::AdminInfoList.at(username) == pwd) {
                return true;
            }
        }  else {
                cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
                cout << "Your username/password is incorrect.\n" << endl;
        }
    }
    return false;

    
    return false;
}

// genearte temporary password
void Admin::resetPwd() {
    std::ifstream myfile("data/resetPwdMem.txt");
    std::vector<string> memResetPwd;
    while (!myfile.eof()) {
        string str;
            getline(myfile, str);
            if (!myfile) break;
            std::stringstream sts(str);
            string temp;
            getline(sts, temp);
            memResetPwd.push_back(temp);
    }
    myfile.close();

    for (int i = 0; i < memResetPwd.size(); i++) {
        cout << "Username " << i + 1 << " :\t\t\t" <<memResetPwd[i] << endl;
    }

    cout << "Please enter your username you want to make temporary password for he/she: ";
    string usernameTemp;
    getline(cin >> std::ws, usernameTemp);

    const char alphanum[] = "0123456789";
    
    // intialize the random generator (based on current time)
    srand(time(NULL));
    
    // Generate a random integer from 0 to N
    int const N = 9;
    int num = rand() % (N + 1);
    string tempPwd;
    for (int i = 0; i < 6; i++) {
        char temp = alphanum[rand() % (10 + 1)];
        if (isdigit(temp)) {
            tempPwd += temp;
        } else {
            i--;
        }
    }
    cout << "The temporary password for " << usernameTemp << " is " << tempPwd << endl;

    //Create map variable
    map<string, string> resetPwdList;

    std::ifstream inputFile("data/resetPwd.txt", std::ios::in);
    if (!inputFile.is_open()) {
            cout << "Error: File not found.\n";
            return;
    }

    //Read from file and insert value to resetPwdList
    while (!inputFile.eof()) {
        string str;
        getline(inputFile, str);
        if (!inputFile) break;
        std::stringstream sts(str);
        string username, pwdTemp;
        getline(sts, username, ' ');
        getline(sts, pwdTemp);
        resetPwdList.insert({username, pwdTemp});
    }
    inputFile.close();

    //Check is the username is exist
    if (resetPwdList.find(usernameTemp) != resetPwdList.end()) {
      resetPwdList.erase(usernameTemp);
    }

    //Insert new username and temPwd for reset password
    resetPwdList.insert({usernameTemp, tempPwd});

    std::ofstream outputFile("data/resetPwd.txt", std::ios::out);
    if (!outputFile.is_open()) {
            cout << "Error: Failed to open/create file.\n";
            return;
    }

    //Write all data to file
    for (auto const &pair : resetPwdList) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    
    outputFile.close();

    for (int i = 0; i < memResetPwd.size(); i++) {
        if (memResetPwd[i] == usernameTemp) {
            memResetPwd.erase(memResetPwd.begin() + i);
        }
    }

    //Save data to file
    std::ofstream outputFile1("data/resetPwdMem.txt", std::ios::out);
    if (!outputFile1.is_open()) {
            cout << "Error: Failed to open/create file.\n";
            return;
    }

     for (int i = 0; i < memResetPwd.size(); i++) {
        outputFile1 << memResetPwd[i] << endl;
    }
    
    outputFile1.close();
}

//Show all admin menu
bool Admin::showAdminMenu() {
    cout << "Welcome to Admin Page!" << endl;
    cout << "1. Reset password" << endl;
    cout << "2. Exit\n\n";
    cout << "Please enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            resetPwd();
            cout << "Reset password success!" << endl;
            return true;
            break;
        }
        case 2: {
            cout << "Thank you for using our service!" << endl;
            return true;
        }
        default: {
            cout << "Invalid choice!" << endl;
            return false;
        }
    }
}