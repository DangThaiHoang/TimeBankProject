#include <iostream>
#include <utility>
#include <cstdlib>
#include <conio.h>
#include <fstream>


//Include header file
#include "header/System.h"
#include "header/Admin.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    System sys;

    
    //Load all data from file
    if (!sys.loadAllData()) {
        cout << "Error: Failed to load data from file." << endl;
        return -1;
    }
    sys.eraseNonAcceptedRequest();
    start: ;
    cout << "\033[2J\033[1;1H";
    cout << "EEET2482/COSC2082 Assignment" << endl;
    cout << "\"TIME BANK\" APPLICATION \n\n";
    cout << "Instructors: Mr. Tran Duc Linh" << endl;
    cout << "Group: Group No.3" << endl;
    cout << "s3975844, Student: Nguyen The Anh\n"
        << "s3990627, Student: Nguyen Hoang Son\n"
        << "s3981133, Student: Pham Thanh The\n"
        << "s3988412, Student: Dang Thai Hoang \n\n"
        << "Use the app as 1. Guest 2. Member 3. Admin 4. Exit\n\n";
  
  
  
  int choice = 0;
  cout << "Enter your choice: ";
  cin >> choice;
  switch (choice) {

    //Guest
    case 1:
      {
        startGuest: ;
        cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
        cout << "Welcome to Guest Page!" << endl;
        cout << "1. Register" << endl;
        cout << "2. View All Supporter" << endl;
        cout << "3. Exit \n\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
          case 1: {
            sys.memList.push_back(sys.registerMem());
            cout << "Register successfully!\n"
                << "Please choose 2 to login as a member."
                << "Press any key to return the main menu!" << endl;
            getch(); //Source: https://www.geeksforgeeks.org/cpp-wait-for-user-input/
            goto start;
            break;
          }
          case 2: {
            sys.showAllSupporters();
            cout << "If you want to book any supporter, you need to register as a member to book he/she."
                  << "\n\nPlease press any key to return to Guest Menu!";
            getch();
            goto startGuest;
            
            break;
          }
          case 3: {
            goto start;
          }
        }
        break;
      }
    
    //Member
    case 2: {
        cin.ignore();
        cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
        cout << "Welcome to Member Page!\n\n"
           << "1. Login\n"
            << "2. Reset Password\n" 
            << "3. Exit\n\n"
            << "Enter your choice: "; 
        int userChoice;
        cin >> userChoice;
        string username, pwd;
        switch (userChoice)
        {
            //Login
            case 1: {
                typeAgain: ;
                cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
                cout << "Login Page!\n\n" 
                    << "Enter your username: ";
                getline(cin >> std::ws, username);
                cout << "Enter your password: ";
                getline(cin >> std::ws, pwd);
                if (sys.isMemberLoginValid(username, pwd)) {
                    std::pair<string, string> currentMem;
                    currentMem.first = username;
                    currentMem.second = pwd;

                    Member currentMemInfo;

                    for (Member mem : sys.memList) {
                        if (mem.getUsername() == currentMem.first && mem.getPwd() == currentMem.second) {
                            currentMemInfo = mem;
                            break;
                        }
                    }

                    if (currentMemInfo.getPosition() != "Host") {
                        cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
                        if (sys.showSupporterMenu(currentMem.first) == 5) {
                            cout << "You need to login again to get the latest data!\n";
                            cout << "\n\nPlease press any key to go back to the main menu!";
                            getch();
                            goto start;
                        };
                        goto start;
                    } else {
                        cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
                        if (sys.showHostMenu(currentMem.first) == 2) {
                            cout << "You need to login again to get the latest data!\n";
                            cout << "\n\nPlease press any key to go back to the main menu!";
                            getch();
                            goto start;
                        };
                        goto start;
                    }
                } else {
                    cout << "\nwrong username or password !";
                    string resetChoice;
                    cout << "\nDo you want to type again? (Y/N): ";
                    getline(cin >> std::ws, resetChoice);
                    if (resetChoice == "Y") {
                        goto typeAgain;
                    } else {
                            cout << "\nDo you want to reset password? (Y/N): ";
                            getline(cin >> std::ws, resetChoice);

                                if (resetChoice == "Y") {
                                    if (sys.checkUsername(username)) {
                                        cout << "\n\nPlease wait for admin!\n\n";
                                        cout << "Press any key to back main menu!";

                                        std::ofstream myfile("data/resetPwdMem.txt");
                                        myfile << username;

                                        myfile.close();

                                        getch();
                                        goto start;
                                    } else {
                                        cout << "Your username does not exist!\n"
                                            << "Please press any key to go back to the main menu!";
                                        getch();
                                        goto start;
                                    }
                                } else {
                                    goto start;
                                }
                    }
                };
                break;
            }
          
            //Reset password
            case 2: {
                cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
                cout << "Reset password page!\n\n"
                    << "Enter your username: ";
                getline(cin >> std::ws, username);
                sys.changePwd(username);
                cout << "Please press any key to go back the main menu!";
                getch();
                goto start;
                break;
            }
            
            //Exit
            case 3: {
                goto start;
                break;
            }
        
            default: {
                cout << "Invalid choice!";
                goto typeAgain;
                break;
            }   
        }
        break;
    }

    //Admin
    case 3:
      {
        Admin Admin;

        if (!Admin.loadAdminInfo()) {
            cout << "Faile to load all admin info!" << endl;
            return -1;
        }

        //Check is correct admin account and show the admin menu
        if (Admin.login()) {
            bool flag = 1;
            while (flag) {
                cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
                cout << "\nWelcome to Admin page!" << endl;
                cout << "Admin Menu:" << endl;
                cout << "1. Reset Password" << endl;
                cout << "2. Exit\n\n";
                int choice = 0;
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    //Reset password
                    case 1: {
                        Admin.resetPwd();
                        getch();
                        break;
                    }
                    //Exit
                    case 2: {
                        cout << "Sign out successful! " << endl;
                        goto start;
                        flag = 0;
                        break;
                    }

                    default: {
                        cout << "Invalid choice!" << endl;
                        return -2;
                    }
                }
            }
        }

        goto start;
        break;
    }

    //Exit the main menu
    case 4: {
        cout << "Exiting the application..." << endl;
        if (!sys.saveAllData()) {
            cout << "Error: Failed to save data from file." << endl;
            return -2;
        }
      
        break;
    }

    default:
        cout << "Invalid choice" << endl;
    }

    std::cin.get(); 
    return 0;
}
