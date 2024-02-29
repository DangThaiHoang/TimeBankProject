#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <limits>

#define VNT (+7)

#include "System.h"
#include "Member.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Load all data from the memeber file
bool System::loadMemData() {
  	// Open file to read data
  	std::ifstream inputFile;
  	inputFile.open("data/Member.txt", std::ios::in);

  	if (!inputFile.is_open()) {
    	cout << "Error: File not found.\n";
    	return false;
 	}

  	// Loop through file
 	while (!inputFile.eof()) {
    	string s;
    	getline(inputFile, s);
    	if (!inputFile) break;
        std::stringstream sts(s);
        string usernameTemp, pwdTemp, fullnameTemp, emailTemp, addressTemp,
        statusTemp, skillTemp, phoneNumTemp, positionTemp, freeTime, creditPointsTemp,
        host_ratingScoreTemp, skill_ratingScoreTemp, supporter_ratingScoreTemp, consumePointTemp, miniumHostRatingScoreTemp;
        getline(sts, usernameTemp, '\t');
        getline(sts, pwdTemp, '\t');
        getline(sts, fullnameTemp, '\t');
        getline(sts, emailTemp, '\t');
        getline(sts, addressTemp, '\t');
        getline(sts, statusTemp, '\t');
        getline(sts, skillTemp, '\t');
        getline(sts, phoneNumTemp, '\t');
        getline(sts, positionTemp, '\t');
        getline(sts, creditPointsTemp, '\t');
        getline(sts, host_ratingScoreTemp, '\t');
        getline(sts, skill_ratingScoreTemp, '\t');
        getline(sts, supporter_ratingScoreTemp, '\t');
        getline(sts, freeTime, '\t');
        getline(sts, consumePointTemp, '\t');
        getline(sts, miniumHostRatingScoreTemp);

        System::memList.push_back(Member(
            usernameTemp, pwdTemp, fullnameTemp, emailTemp, addressTemp, statusTemp,
            skillTemp, phoneNumTemp, positionTemp, std::stoi(creditPointsTemp),
            std::stod(host_ratingScoreTemp), std::stod(skill_ratingScoreTemp),
            std::stod(supporter_ratingScoreTemp), freeTime, std::stoi(consumePointTemp), std::stod(miniumHostRatingScoreTemp))
        );
    }
 	// Close file data
  	inputFile.close();
  	return true;
}

// Find member depends on username
int System::findMem(string username) {
  	for (int i = 0; i < memList.size(); i++) {
    	if (memList[i].getUsername() == username) {
      		return i;
    	}
  	}
  	return -1;
}

int System::findAddress(string address) {
  	for (int i = 0; i < memList.size(); i++) {
    	if (memList[i].getAddress() == address && memList[i].getStatus() == "Available") {
      		return i;
    	}
  	}
  	return -1;
}

// Update status of the member
bool System::updateStatus(const string &username) {
	cout << "\033[2J\033[1;1H"; //Clear screen
  	int choice;
  	string freeTimeTemp;
  	int consumePointTemp;
  	double miniumHostRatingScoreTemp;
  	cout << "Choose your status: " << endl;
  	cout << "1. Available" << endl;
  	cout << "2. UnAvailable" << endl;
  	cout << "Enter your choice: ";
  	cin >> choice;
  	int position = findMem(username);
  	switch (choice) {
  		case 1: {
			// Update status to available
    		if (position >= 0) {
    	  		memList[position].setStatus("Available");

				cout << "Enter your skill: ";	
				string skillTemp;
				getline(cin >> std::ws, skillTemp);
				memList[position].setBestSkill(skillTemp);


    	  		bool flag = true;
    	  		while (flag) {
    	    		cout << "Choose your free time: " << endl;
    	    		cout << "1. 8:00 - 10:00" << endl;
    	    		cout << "2. 10:00 - 12:00" << endl;
    	    		cout << "3. 13:00 - 15:00" << endl;
    	    		cout << "4. 15:00 - 17:00" << endl;
    	    		cout << "5. 17:00 - 19:00" << endl;
    	    		cout << "6. 19:00 - 21:00" << endl;
    	    		cout << "Enter your choice: ";
    	    		int choiceTime;
    	    		cin >> choiceTime;
	
    	  			switch (choiceTime) {
    	    			case 1: {
							freeTimeTemp = "8:00 - 10:00";
    	      				flag = false;
    	      				break;
						}
    	    			case 2: {
							freeTimeTemp = "10:00 - 12:00";
    	      				flag = false;
    	      				break;
						}
	
    	    			case 3: {
							freeTimeTemp = "13:00 - 15:00";
    	      				flag = false;
    	      				break;
						}
	
    	    			case 4: {
							freeTimeTemp = "15:00 - 17:00";
    	      				flag = false;
    	      				break;
						}

    	    			case 5: {
							freeTimeTemp = "17:00 - 19:00";
    	      				flag = false;
    	      				break;
						}

    	    			case 6: {
							freeTimeTemp = "19:00 - 21:00";
    	      				flag = false;
    	      				break;
						}	
    	    			default: {
							cout << "Invalid choice." << endl;
    	      				break;
						}

    	    		}
    	  		}
    	  		memList[position].setFreeTime(freeTimeTemp);

    	  		cout << "Enter your consume point: ";
    	  		cin >> consumePointTemp;
    	  		memList[position].setConsumePoint(consumePointTemp);

				char choiceMiniumHostRatingScore;
				while (1) {
					cout << "Do you want to set the minium host rating score? (Y/N): ";
					cin >> choiceMiniumHostRatingScore;
					if (choiceMiniumHostRatingScore != 'Y' && choiceMiniumHostRatingScore != 'N') {
						cout << "Invalid choice." << endl;
					} else {
						break;
					}
				}

				if (choiceMiniumHostRatingScore == 'Y') {
					cout << "Enter your minium host rating score (0-5): ";
    	  			cin >> miniumHostRatingScoreTemp;
				} else if (choiceMiniumHostRatingScore == 'N') {
					miniumHostRatingScoreTemp = 0;
				}

    	  		
    	  		memList[position].setMiniumHostRatingScore(miniumHostRatingScoreTemp);
    	  		return true;
    		} else {
    	  		cout << "Member not found." << endl;
    	  		return false;
    		}
    		break;
		}
	
  		case 2: {
			// Update status to unavailable
    		if (position >= 0) {
    	  		memList[position].setStatus("Unavailable");
    	  		memList[position].setFreeTime("N/A");
    	  		memList[position].setConsumePoint(0);
    	  		memList[position].setMiniumHostRatingScore(0);
    		} else {
    	  		cout << "Member not found." << endl;
    	  		return false;
    		}
    		break;
		}
	
  		default: {
			cout << "Invalid choice." << endl;
			return false;
		}
  	}
	cout << "\n\nPress any key to back main menu!";
	getch();
  	return false;
}

// Save all data to file
bool System::saveMemData() {
  	// Open file to save data
  	std::ofstream outputFile;

  	outputFile.open("data/Member.txt", std::ios::out);
  	if (!outputFile.is_open()) {
  	  	cout << "Error: Failed to create/open.\n";
  	  	return false;
  	}

  	// Store data to list of member
  	for (Member &mem : System::memList) {
  	  	outputFile << mem.getUsername() << "\t" << mem.getPwd() << "\t"
  	  	           << mem.getFullname() << "\t" << mem.getEmail() << "\t"
  	  	           << mem.getAddress() << "\t" << mem.getStatus() << "\t"
  	  	           << mem.getBestSkill() << "\t" << mem.getPhoneNum() << "\t" << mem.getPosition() << "\t"
  	  	           << mem.getCreditPoints() << "\t" << mem.getHostRatingScore()
  	  	           << "\t" << mem.getSkillRatingScore() << "\t"
  	  	           << mem.getSupporterRatingScore() << "\t"
  	  	           << mem.getFreeTime() << "\t"
  	  	           << mem.getConsumePoint() << "\t"
  	  	           << mem.getMiniumHostRatingScore() << "\n";
  	}

  	// Close file
  	outputFile.close();
  	return true;
}

int System::findBlockedMem(const string &blockedMem, const string &memBlock) {
	for (int i = 0; i < blockMemList.size(); i++) {
		if (blockMemList[i].blockedMem == blockedMem && blockMemList[i].MemBlock == memBlock) {
			return i;
		}
	}
	return -1;
}

// Show all supporter member for member
void System::showAllSupporters(const string &username) {
  	int id= 1;
	cout << "\033[2J\033[1;1H"; //Clear screen
  	cout << "Supporter List: " << endl;
  	for (Member &mem : memList) {
  	  	if (mem.getStatus() == "Available" && mem.getUsername() != username) {
			int position = findBlockedMem(username, mem.getUsername());
			if (position == -1) {
				cout << id << "   " << mem.getUsername() << "   "<< mem.getBestSkill() << "   " << mem.getAddress() << endl;
				id++;
			} else {
				continue;
			}
  	  	}
  	}	
	cout <<  "\n\nPress any key to back main menu!";
	getch();
}

// Show all supporter member for guest
void System::showAllSupporters() {
	cout << "\033[2J\033[1;1H"; //Clear screen
  	int id= 1;
  	cout << "Supporter List: " << endl;
  	for (Member &mem : memList) {
  	  	if (mem.getStatus() == "Available") {
  	  	  	cout << id << "   " << mem.getUsername() << "   "<< mem.getBestSkill() << "   " << mem.getAddress() << endl;
  	  	  	id++;
  	  	}
  	}
	
}



// Update host rating score
bool System::updateHostRatingScore(const string &username, double score) {
  	for (Member &mem : System::memList) {
  	  	if (mem.getUsername() == username) {
  	  	  	mem.setHostRatingScore((mem.getHostRatingScore() + score) / 2);
  	  	  	return true;
  	  	}
  	}
  	cout << "The username doesn't exist." << endl;
  	return false;
}

// Update skill rating score
bool System::updateSkillRatingScore(const string &username, double score) {
  	for (Member &mem : System::memList) {
  	  	if (mem.getUsername() == username) {
			if (mem.getSkillRatingScore() == 0) {
				mem.setSkillRatingScore(score);
				return true;
			} else {
				mem.setSkillRatingScore((mem.getSkillRatingScore() + score) / 2);
  	  	  		return true;
			}
  	  	}
  	}
  	cout << "The username doesn't exist." << endl;
  	return false;
}

// Update supporter rating score
bool System::updateSupporterRatingScore(const string &username, double score) {
  	for (Member &mem : System::memList) {
  	  	if (mem.getUsername() == username) {
			if (mem.getSupporterRatingScore() == 0) {
				mem.setSupporterRatingScore(score);
				return true;
			} else {
				mem.setSupporterRatingScore((mem.getSupporterRatingScore() + score) / 2);
  	  	  		return true;
			}
  	  	  	
  	  	}
  	}
  	cout << "The username doesn't exist." << endl;
  	return false;
}

string System::generateTime() {
	//Get the current time
    time_t rawtime;

    time (&rawtime);

	string temp = ctime(&rawtime);

	//Delete the last character of the string
	while (temp[temp.length() - 1] == '\t' || temp[temp.length() - 1] == '\n') {
		temp.pop_back();
	}

    return temp;
}

bool System::addSupComment(const string &hostName, const string &supName, const int idReq) {
	double skillScore = 0, supScore = 0;
	cout << "\033[2J\033[1;1H"; //Clear screen
    cout << "Enter your score for supporter skill: ";
    cin >> skillScore;

	//Updating the skill rating score
    updateSkillRatingScore(supName, skillScore);

    cout << "Enter your score for supporter: ";
    cin >> supScore;

	//Updating the supporter rating score
    updateSupporterRatingScore(supName, supScore);
    
  
    string comment;
    cout << "Enter your comment: ";
    getline(cin >> std::ws, comment);

    string temp = generateTime();

    while (temp[temp.length() - 1] == '\t' || temp[temp.length() - 1] == '\n') {
        temp.pop_back();
    }

    supCommentList.push_back(Comment(temp, hostName, supName, comment, skillScore, 0, supScore, idReq));
    return true;
return true;
}

bool System::addHostComment(const string &hostName, const string &supName, const int idReq) {
    double hostScore = 0;

	cout << "\033[2J\033[1;1H"; //Clear screen
    cout << "Enter your score for host: ";
    cin >> hostScore;

	//Updating the supporter rating score
    updateHostRatingScore(hostName, hostScore);
    
  
    string comment;
    cout << "Enter your comment: ";
    getline(cin >> std::ws, comment);

    string temp = generateTime();

    while (temp[temp.length() - 1] == '\t' || temp[temp.length() - 1] == '\n') {
        temp.pop_back();
    }

    hostCommentList.push_back(Comment(temp, hostName, supName, comment, 0 , hostScore, 0,idReq));
    return true;
}

//Change password of the member using temporary password
bool System::changePwd(const string &username){
	cout << "\033[2J\033[1;1H"; //Clear screen
  	std::map<string, string> changePwdMemList;
	
  	// Open file to read data
  	std::ifstream inputFile;
  	inputFile.open("data/resetPwd.txt", std::ios::in);

  	if (!inputFile.is_open()) {
  	  cout << "Error: File not found.\n";
  	  return false;
  	}

  	// Loop through file
  	while (!inputFile.eof()) {
  	  string s;
  	  getline(inputFile, s);
  	  if (!inputFile) break;
  	  std::stringstream sts(s);
  	  string usernameTemp, pwdTemp;
  	  getline(sts, usernameTemp, ' ');
  	  getline(sts, pwdTemp);

  	  changePwdMemList.insert({usernameTemp, pwdTemp});
  	}

  	inputFile.close();

  	bool flag = true;

  	while (flag) {
  	  	if (changePwdMemList.find(username) != changePwdMemList.end()) {

  	  	    string pwdTemporary;
  	  	    cout << "Please, enter your temporary password: ";
  	  	    getline(cin >> std::ws, pwdTemporary);

  	  	    while(1) {
  	  	        //Check whether the temporary password was generated by admin match the user input
  	  	        if (changePwdMemList.find(username)->second == pwdTemporary) {
  	  	            //Delete the info of username with the temporary password was generated by admin
  	  	            changePwdMemList.erase(username);

  	  	            //Save all data back to file
  	  	            std::ofstream outputFile("data/resetPwd.txt", std::ios::out);
  	  	            if (!outputFile.is_open()) {
  	  	                cout << "Error: Failed to open/create file.\n";
  	  	                return false;
  	  	            }

  	  	            //Write all data to file
  	  	            for (auto const &pair : changePwdMemList) {
  	  	                outputFile << pair.first << " " << pair.second << endl;
  	  	            }

  	  	            outputFile.close();

  	  	            //Get new password from user
  	  	            string pwd;
  	  	            cout << "Please enter your new password: ";
  	  	            getline(cin >> std::ws, pwd);

  	  	            //Check and change the password in the member data file
  	  	            for (Member &mem : memList) {
  	  	                if (mem.getUsername() == username) {
  	  	                mem.setPwd(pwd);
  	  	                flag = false;
  	  	                return true;
  	  	                }
  	  	            }

  	  	        } else {
  	  	            cout << "Your temporary password is incorrect!." << endl;
  	  	        }
  	  	    }   
  	  	} else {
  	      	cout << "The username doesn't exist." << endl;
  	      	return false;
  	  	}
  	}
  	return false;
}

void System::showHostPendingRequest(const string &hostName) {
	cout << "\033[2J\033[1;1H"; //Clear screen
	cout << "Pending request: " << endl;
	for (Request &req : reqList.requestListInfo) {
		if (req.getHostUserName() == hostName && req.getStatus() == "Pending") {
			cout << req.getTimeReq( )<< "    " << req.getSupUserName() << endl;
		}
	}
	cout << "\n\nPress any key to back main menu!";
	getch();
};

void System::showSupPendingRequest(const string &supName) {
	cout << "\033[2J\033[1;1H"; //Clear screen
	cout << "Pending request: " << endl;
	for (Request &req : reqList.requestListInfo) {
		if (req.getSupUserName() == supName && req.getStatus() == "Pending") {
			cout << req.getTimeReq( )<< "    " << req.getHostUserName() << endl;
		}
	}
	cout << "\n\nPress any key to back main menu!";
	getch();
};

//Book supporter
void System::bookSup(const string &username){
  	string supUsername;
  	cout << "Enter the username of the supporter: ";
  	cin >> supUsername;
  	int position = findMem(supUsername);
  	if (position >= 0) {
  	  	if (memList[position].getStatus() == "Available") {
			string time = generateTime();
  	  	  	reqList.GenerateRequest(username, supUsername, memList[position].getConsumePoint());
  	  	} else {
  	  	  	cout << "Supporter " << supUsername << " is not available." << endl;
  	  	}
  	}
}


//reply the request
bool System::replyRequest(const string &username) {
	cout << "\033[2J\033[1;1H"; //Clear screen
  	cout << "Request from: " << endl;
	
	int flag = 0;
  	for (Request &req : reqList.requestListInfo) {
		if(req.getSupUserName()	== username && req.getStatus() == "Waiting") {
			cout << req.getId() << "    " <<req.getHostUserName() << endl;
			flag = 1;
		}
  	}
	if (flag == 1) {
		cout << "Do you want to accept any request in the list? (Y/N): ";
		string choice;
		getline(cin >> std::ws, choice);
		if (choice == "Y" || choice == "y") {
			int id;
			while (1) {
				cout << "Enter the request's id which is created by the host you want to work with: ";
  				cin >> id;
				if (id < 0 && id > reqList.requestListInfo.size()) {
					cout << "Invalid choice." << endl;
					continue;
				} else {
					break;
				}
			}
  			  	cout << "Do you want to accept this request? (Y/N): ";
  			  	string choice;
  			  	cin >> choice;
  			  	if (choice == "Y") {
  			  	  	cout << "Request accepted." << endl;
  			  	  	for (Member &mem : memList) {
  			  	  	  	if (mem.getUsername() == username) {
  			  	  	  	  	mem.setStatus("Unavailable");
							for (Request &req : reqList.requestListInfo) {
								if(req.getId() == id) {
									req.setStatus("Pending");
									req.setTimeReq(generateTime());
								} else if (req.getSupUserName()	== username && req.getStatus() == "Waiting") {
									req.setStatus("Denied");
								}
							}
						}

  	  		  	  	  	}
  	  		  	} else {
  	    	  			cout << "Request denied." << endl;
  	    	  			for (Request &req : reqList.requestListInfo) {
							if(req.getId() == id) {
								req.setStatus("Denied");
								return true;
							}
						}
					return true;
  	    		} 
		} else {
			return true;
		}
	} else {
		cout << "You don't have any request." << endl;
		cout << "\n\nPress any key to back main menu!";
		getch();
	}
  	return false;
}

//Add credit point when the supporter complete the request
bool System::addCreditPoints(const string &username){
	cout << "\033[2J\033[1;1H"; //Clear screen
  	int creditPoints;
  	cout << "Enter the credit points: ";
  	cin >> creditPoints;
	cout << "Please enter your password: ";
	string pwd;
	getline(cin >> std::ws, pwd);
	for (Member &mem: memList) {
		if (mem.getUsername() == username && mem.getPwd() == pwd) {
			mem.setCreditPoints(mem.getCreditPoints() + creditPoints);
			cout << "Add credit point successfully!" << endl;
			cout << "\nPlease enter any key to back main menu!";
			getch();
			return true;
		}
	}
  	cout << "The username doesn't exist." << endl;
	cout << "Failed to add more credit point using money!" << endl;
	cout << "Please enter any key to back main menu!";
	getch();
  	return false;
}

//Reduce credit point when the host book the supporter
bool System::reduceCredit(const string &username){
  	for(Member &mem : System::memList){
  	  	if(mem.getUsername() == username){
  	  	  	if(mem.getCreditPoints() > 0){
  	  	  	  	mem.setCreditPoints(mem.getCreditPoints() - 1);
  	  	  	  	return true;
  	  	  	} else{
  	  	  	  	cout << "You don't have enough credit points to book the supporter." << endl;
  	  	  	  	cout << "You don't have enough credit points to utilize." << endl;
  	  	  	  	return false;
  	  	  	}
  	  	}
  	}
  	return false;
}

void System::updatePosition(const string &username) {
	cout << "\033[2J\033[1;1H"; //Clear screen
  	cout << "Choose your position: " << endl;
    cout << "1. Host" << endl;
    cout << "2. Supporter" << endl;
    cout << "Enter your choice: ";
    int choicePos;
    cin >> choicePos;
    string positionTemp;
    if (choicePos == 1) {
      positionTemp = "Host";
    } else if (choicePos == 2) {
      positionTemp = "Supporter";
    }
    for (int i = 0; i < memList.size(); i++) {
        if (memList[i].getUsername() == username) {
          memList[i].setPosition(positionTemp);
        }
    }
}


int System::findRequest(const string &hostName, const string &supName){
	for (int i = 0; i < reqList.requestListInfo.size(); i++) {
		if (reqList.requestListInfo[i].getHostUserName() == hostName && reqList.requestListInfo[i].getSupUserName() == supName) {
			return i;
		}
	}
	return -1;
};

void System::addCommentForHost(const string &username) {
	string supName;
	int flag = 0;
	cout << "\033[2J\033[1;1H"; //Clear screen
	cout << "Supporter worked with " << username << " before: " << endl;
	for (Request &req : reqList.requestListInfo) {
		if (req.getHostUserName() == username && req.getStatus() == "Finished" && req.getSupComment() == false) {
			cout << req.getId() << "   " << req.getSupUserName() << endl;
			flag = 1;
		}
	}
	
	if (flag == 0) {
		cout << "You haven't worked with any host yet." << endl;
		getch();
		return;
	} else {
		cout << "Enter your id of request which you want to rate its supporter: ";
		int choice;
		cin >> choice;
		for (Request &req : reqList.requestListInfo) {
			if (req.getId() == choice) {
				req.setSupComment(true);
				addSupComment(username, req.getSupUserName(), req.getId());
			}
		}
	}
};

//Add comment using by supporter
void System::addCommentForSup(const string &username) {
	string hostName;
	int flag = 0;
	cout << "\033[2J\033[1;1H"; //Clear screen
	cout << "Host worked with " << username << " before: " << endl;
	for (Request &req : reqList.requestListInfo) {
		if (req.getSupUserName() == username && req.getStatus() == "Finished" && req.getHostComment() == false) {
			cout << req.getId() << "    " <<req.getHostUserName() << endl;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "You haven't worked with any host yet." << endl;
		getch();
		return;
	} else {
		cout << "Enter your id of request which you want to rate its host: ";
		int choice;
		cin >> choice;
		for (Request &req : reqList.requestListInfo) {
			if (req.getId() == choice) {
				req.setHostComment(true);
				addHostComment( req.getHostUserName(), username, req.getId());
			}
		}
	}
};

//Show the menu for the host member
int System::showHostMenu(const string &username){
    int choice, temp;
    //REF
    bool returnToMain = false;

    //REF
    while(!returnToMain){
		cout << "\033[2J\033[1;1H"; //Clear screen
		cout << "Welcome to Host Member Page!\n";
        cout << "Menu for " << username << ":" << endl;
        cout << "1. View Profile" << endl; //Fix (Loop) (Fixed)
        cout << "2. Change Current Position (if you want to be booked by another supporter, you need to change your position to supporter)" << endl; //OK
        cout << "3. View Available Supporters" << endl; //Fix (chua xem dc)
        cout << "4. Search for Supporters by Location" << endl; //Fix (ko tra duoc)
		cout << "5. Search for Supporters by their free Time" << endl;
        cout << "6. Show all accepted request" << endl;
        cout << "7. Add comment for booked supporter" << endl;
		cout << "8. Show all your comment" << endl;
        cout << "9. Add Credit Points to Your Account" << endl; //OK
        cout << "10. Exit" << endl;
        cout << "Enter Your Choice (1-10): "; cin >> choice;
        if((choice < 1) || (choice > 10) || (!cin >> choice)){
            //REF
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "You have enter an INVALID input. Please Enter Your Choice again (from 1 to 10)!!" << endl;
            continue; // Skip the rest of the loop iteration and ask for input again
        }

		switch (choice) {
			case 1: {
				viewProfile(username);
				break;
			}
				
			case 2: {	
				updatePosition(username);
				returnToMain = true;
				temp = 2;
				break;
			}
			case 3:
				showAllSupporters(username);
				break;
			case 4:
				searchSupByLocation(username);
				break;
			case 5:
				searchSupByFreeTime(username);
				break;
			case 6:
				showHostPendingRequest(username);
				break;
			case 7: 
				addCommentForHost(username);	
				break;
			case 8:
				findHostComment(username);
				break;
			case 9:
				addCreditPoints(username);
				break;
			case 10: {
				cout << "\nClose " << username << "'s Menu. Have a good day!\n" << endl;
			    temp = 10;
				returnToMain = true;
				break;
				}
			default:
				break;
		}
	}
	return temp;
}



//Show the menu for the supporter member
int System::showSupporterMenu(const string &username){
    RequestList reqlist;
    reqlist.LoadAllData();
	int temp;
    int choice;
    //REF
    bool returnToMain = false;

    //REF
    while(!returnToMain){
		cout << "\033[2J\033[1;1H"; //Clear screen
		cout << "Welcome to Supporter Member Page!\n";
        cout << "Menu for " << username << ":" << endl;
		cout << "1.  View Profile" << endl;
        cout << "2.  View Current Status" << endl; //OK
        cout << "3.  Change Current Status (if you want to booked ,you need to change your status to available and list your skill, choose your free time, etc.)" << endl; // OK
        cout << "4.  View Pending Requests" << endl; // Chua biet
        cout << "5.  Change position (if you want to book other supporter, you need to change your position to host!!)" << endl;
        cout << "6.  View all waiting reply request" << endl;
        cout << "7.  Finish Request" << endl; // Chua Biet
        cout << "8.  Add comment for the host you worked with before" << endl;
		cout << "9.  Show all your comment" << endl;
        cout << "10. Add Credit Points to Your Account" << endl; //OK
		cout << "11. Block supporter" << endl;
		cout << "12. View all supporters" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter Your Choice (1-13): "; cin >> choice;
        if((choice < 1) || (choice > 13) || (!cin >> choice)){
            //REF
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "You have enter an INVALID input. Please Enter Your Choice again (from 1 to 13)!!" << endl;
            continue; // Skip the rest of the loop iteration and ask for input again
        }
		switch (choice)
		{
			case  1: {
				viewProfile(username);
				break;
			}
			case 2:
				viewStatus(username);
				break;
			case 3:
				updateStatus(username);
				break;
			case 4: {
				if (viewBookedRequests(username)) {
				} else {
					cout << "You haven't booked any host yet." << endl;
				};
				cout << "\n\nPress any key to back main menu!";
					getch();
				break;
			}
				
			case 5: {
				updatePosition(username);
				temp = 5;
				returnToMain = true;
				break;
			}
			case 6:
				replyRequest(username);
				break;
			case 7:
				finishRequest(username);
				break;
			case 8:
				addCommentForSup(username);
				break;
			case 9:
				findSupComment(username);
				break;
			case 10:
				addCreditPoints(username);
				break;
			case 11:
				blockSupporter(username);
				break;
			case 12: {
				showAllSupporters(username);
				break;
			}
			case 13: {
				cout << "\nClose " << username << "'s Menu. Have a good day!\n" << endl;
        	    temp = 13;
				returnToMain = true;
				break;
			}
			default:
				break;
			}
    }
	return temp;
}

//View the status of the member
void System::viewStatus(const string &username){
    for (Member mem : System::memList) {
        if (mem.getUsername() == username) {
            cout << "Your current status is: " << mem.getStatus() << endl;
			cout << "\nPress any key to back main menu!";
			getch();
            return;
        }
    }
}

//View the user profile
void System::viewProfile(const string &username) {
	cout << "\033[2J\033[1;1H"; //Clear screen
	int position = findMem(username);
	cout << "Your profile:";
	cout << "Username: " << memList[position].getUsername() << endl;
    cout << "Fullname: " << memList[position].getFullname() << endl;
    cout << "Email: " << memList[position].getEmail() << endl;
    cout << "Address: " << memList[position].getAddress() << endl;
    cout << "PhoneNum: " << memList[position].getPhoneNum()<< endl;
	cout << "CreditPoints: " << memList[position].getCreditPoints() << endl;
	cout << "Position: " << memList[position].getPosition() << endl;
	cout << "BestSkill: " << memList[position].getBestSkill() << endl;
	cout << "host rating score: " << memList[position].getHostRatingScore() << endl;
	cout << "skill rating score: " << memList[position].getSkillRatingScore() << endl;
	cout << "supporter rating score: " << memList[position].getSupporterRatingScore() << endl;


	cout << "Do you want to update your profile (Y/N):";
	string choice;
	getline(cin >> std::ws, choice);
	if (choice == "Y") {
		updateProfile(username);
	} else if (choice == "N") {
		return;
	} else {
		cout << "Invalid choice!";
		cout << "Please press any key to go back previous menu!" << endl;
		getch();
	}
}

//Update the user pofile
bool System::updateProfile(const string &username){
    int position = findMem(username);

	if (position >= 0) {
		

		cout << "\nWhich information you want to change:\n";
		cout << "1. Full name" << endl;
		cout << "2. Email" << endl;
		cout << "3. Address" << endl;
		cout << "4. Phone number" << endl;

		int choice;
		while (1) {
			cout << "Enter your choice: ";
			cin >> choice;
			if (choice > 0 && choice < 6) { 
				break;
			} else {
				cout << "Invalid choice!";
			} 
		}

		string newUsername, newFullname, newEmail, newAddress, newPhonenum;
		switch (choice) {
			case 1: {
				//Ask the user to input the fullname
    			cout << "Enter your fullname: ";
    			getline(cin >> std::ws, newFullname);
				memList[position].setFullname(newFullname);
				break;
			}
			case 2: {
				while (1) {
    			    cout << "Enter your email (example: abcdef@gmail.com): ";
    			    getline(cin >> std::ws, newEmail);
    				if (newEmail.find("@gmail.com") != string::npos && newEmail != memList[position].getEmail()) {
						memList[position].setEmail(newEmail);
    				    break;
    				} else {
    				    cout << "Invalid email or it is the same as your email before. Please enter again." << endl;
    				}
				}
				break;
			}
			case 3: {
				//Ask the user to input the address
    			while (1) {
    			    cout << "Enter your address (Ha Noi / Ho Chi Minh): ";
    			    getline(cin >> std::ws, newAddress);
    				if (newAddress == "Ha Noi" || newAddress == "Ho Chi Minh") {
						memList[position].setAddress(newAddress);
    				    break;
    				} else {
    				    cout << "Invalid address. Please enter again." << endl;
    				}
				}
				break;
			}
			case 4: {
				while (1) {
					restart: ;
    				cout << "Enter your phone number (Your phone number must be contain 10 numbers): ";
    				getline(cin >> std::ws, newPhonenum);
    				if (newPhonenum.length() != 10) {
    				    cout << "The phone number may contain 10 digits only. \n";
    				    goto restart;
    				} else {
    				    for (int i = 0; i < newPhonenum.length(); i++)
    				    {
    				        if (!isdigit(newPhonenum[i]))
    				        {
    				            cout << "The phone number should be only number!";
    				            goto restart;
    				        }
    				    }
    				}
    				break;
				}
				memList[position].setPhoneNum(newPhonenum);
				break;
			}
		}
	}
	return true;
}

//Show the supporter score
void System::showSupporterScore(){
    string temp_username;
    cout << "Enter Supporter's Username: ";
    getline(cin >> std::ws, temp_username);

    std::size_t position = findMem(temp_username);
    bool supporterFound = false;

    if (position < memList.size()) {
        cout << "Supporter " << temp_username << "  found." << endl;
        cout << "Supporter " << temp_username << " 's Score : " << endl;
        for (Member &mem : memList) {
            if(mem.getUsername() == temp_username && mem.getPosition() == "Supporter"){
                cout << "Skill Rating Score: " << mem.getSkillRatingScore() << endl;
                cout << "Supporter Rating Score: " << mem.getSupporterRatingScore() << endl;
                supporterFound = true;
            } else {
                cout << "Supporter " << temp_username << " not found." << endl;
            }
        }    
    } else if (position >= memList.size()) {
        cout << "Supporter " << temp_username << " not found." << endl;
        return;
    }
}

//Show the host score
void System::showHostScore(){
    string temp_username;
    cout << "Enter Host's Username: ";
    getline(cin >> std::ws, temp_username);

    std::size_t position = findMem(temp_username);
    bool hostFound = false;

    if (position < memList.size()) {
        cout << "Host " << temp_username << "  found." << endl;
        cout << "Host " << temp_username << " 's Score : " << endl;
        for (Member &mem : memList) {
            if (mem.getUsername() == temp_username && mem.getPosition() == "Host"){
                cout << "Host Rating Score: " << mem.getHostRatingScore() << endl;
                hostFound = true;
            } else {
                cout << "Host " << temp_username << " not found." << endl;
            }
        }    
    } else if (position >= memList.size()) {
        cout << "Host " << temp_username << " not found." << endl;
        return;
    }
}

bool System::loadBlockMem() {
	//Open file BlockMember.txt to read all data
    std::ifstream inputFile("data/BlockMember.txt");
    if (!inputFile.is_open()) {
        cout << "Error: File not found.\n";
        return false;
    }

    while (!inputFile.eof()) {
        string str;
        getline(inputFile, str);
        if (!inputFile) break;
        std::stringstream sts(str);
        string username, blockStatus;
        getline(sts, username, '\t');
        getline(sts, blockStatus);
		BlockMem blockMem(username, blockStatus);
        blockMemList.push_back(blockMem);
    }

    inputFile.close();
	return true;
}

bool System::saveBlockMem() {
	std::ofstream myFile2("data/BlockMember.txt");
    if (!myFile2.is_open()) {
        std::cerr << "Failed to create/open the file!" << endl;
        return false;
    } else {
        for (BlockMem &blockMem : blockMemList) {
			myFile2 << blockMem.blockedMem << "\t" << blockMem.MemBlock << endl;
		}
    } 
    myFile2.close();
    return true;
}

//Block the other supporter
void System::blockSupporter(const string &username){
    startBlockSupporter: ;
	cout << "\033[2J\033[1;1H"; //Source: https://stackoverflow.com/questions/17335816/clear-screen-using-c
    string supUsername;
	for (Member &mem : memList) {
		if (mem.getUsername() != username) {
			cout << mem.getUsername() << endl;
		}
	}
    cout << "Enter the username you want to block: ";
    getline(cin >> std::ws, supUsername);
    int position = findMem(supUsername);
    if (position >= 0) {
        if (findBlockedMem(supUsername , username) == -1) {
			BlockMem blockMem(supUsername, username);
			blockMemList.push_back(blockMem);
            cout << "The supporter has been blocked." << endl;
			cout << "\n\nPress any key to back main menu!";
			getch();
			return;
        } else {
			cout << "You have blocked this supporter before." << endl;
			cout << "\n\nPress any key to back main menu!";
			getch();
		}
    } else {
        cout << "The supporter doesn't exist." << endl;
        cout << "Do you want to try again? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            goto startBlockSupporter;
        }
    }
}

//View the request from the host 
bool System::viewBookedRequests(const string &username) {
	cout << "\033[2J\033[1;1H";
  	cout << "Booked Request List: " << endl;
	bool flag = false;
  	for (Request &req : reqList.requestListInfo) {
  	  	if (req.getSupUserName() == username && req.getStatus() == "Pending") {
  	  	  	cout << req.getId() << "\t" <<req.getHostUserName() << "\tGenerate at: " << req.getTimeReq() << endl;
			flag = true;
  	  	}
  	}
	return flag;
}

//Search the supporter by their location
void System::searchSupByLocation(const string &username) {
	cout << "\033[2J\033[1;1H";
    string temp_address;
	//Ask the user to input the address
    while (1) {
        cout << "Enter supporters' location(Ha Noi/ Ho Chi Minh): ";
        getline(cin >> std::ws, temp_address);
    if (temp_address == "Ha Noi" || temp_address == "Ho Chi Minh") {
        break;
    } else {
        cout << "Invalid address. Please enter again." << endl;
    }
    }

	int flag = 0;
    std::size_t position = findAddress(temp_address);
    double creditPointsTemp, hostRatingScoreTemp;
    if (position < memList.size()) {
        cout << "Supporters in " << temp_address << " found: " << endl;
		for (Member &mem : memList) {
			if (mem.getUsername() == username) {
                creditPointsTemp = mem.getCreditPoints();
				hostRatingScoreTemp = mem.getHostRatingScore();
                continue;
            }
		}
        for (int i = 0; i < memList.size(); i++) {
			if (blockMemList.size() > 0) {
				for (BlockMem &blockMem : blockMemList) {
					if (blockMem.blockedMem == username && blockMem.MemBlock == memList[i].getUsername()) {	
						i++;
					}
				}
			}
            if(memList[i].getAddress() == temp_address && memList[i].getPosition() == "Supporter" && memList[i].getConsumePoint() <= creditPointsTemp && memList[i].getStatus() == "Available" && memList[i].getMiniumHostRatingScore() <= hostRatingScoreTemp) {
                
							cout << "Username: " << memList[i].getUsername() << endl;
                			cout << "Fullname: " << memList[i].getFullname() << endl;
                			cout << "Address: " << memList[i].getAddress() << endl;
                			cout << "Email: " << memList[i].getEmail() << endl;
                			cout << "PhoneNum: " << memList[i].getPhoneNum() << endl;
                			cout << "Best Skill: " << memList[i].getBestSkill() << endl;
                			cout << "Skill Rating Score: " << memList[i].getHostRatingScore() << endl;
                			cout << "Supporter Rating Score: " << memList[i].getSupporterRatingScore() << endl;
							cout << "Time he/she can work: " << memList[i].getFreeTime() << endl;
							cout << "Consuming point per hour: " << memList[i].getConsumePoint() << endl;
                			cout << endl;
							flag = 1;
				} 
				
        }
	if (flag == 1) {
		cout << "Do you want to book any supporter in " << temp_address << "? (Y/N): ";
    	char choice;
    	cin >> choice;
    	if (choice == 'Y' || choice == 'y') {
    		bookSup(username);
    	} else {
    		return;
    	}
	} else {
		cout << "Cannot find any supporter in " << temp_address << endl;
		cout << "\n\nPress any key to continue! \n" ;
		getch();
	}
		
	} else {
		cout << "\033[2J\033[1;1H";
        cout << "Supporters in " << temp_address << " not found: " << endl;
		cout << "\n\nPress any key to continue! \n" ;
		getch();
		return;
	}
}

//Search the supporter by their location
void System::searchSupByFreeTime(const string &username) {
	cout << "\033[2J\033[1;1H";
	string freeTimeTemp;
    bool flag = true;
    	  		while (flag) {
    	    		cout << "Choose your free time: " << endl;
    	    		cout << "1. 8:00 - 10:00" << endl;
    	    		cout << "2. 10:00 - 12:00" << endl;
    	    		cout << "3. 13:00 - 15:00" << endl;
    	    		cout << "4. 15:00 - 17:00" << endl;
    	    		cout << "5. 17:00 - 19:00" << endl;
    	    		cout << "6. 19:00 - 21:00" << endl;
    	    		cout << "Enter your choice: ";
    	    		int choiceTime;
    	    		cin >> choiceTime;
	
    	  			switch (choiceTime) {
    	    			case 1: {
							freeTimeTemp = "8:00 - 10:00";
    	      				flag = false;
    	      				break;
						}
    	    			case 2: {
							freeTimeTemp = "10:00 - 12:00";
    	      				flag = false;
    	      				break;
						}
	
    	    			case 3: {
							freeTimeTemp = "13:00 - 15:00";
    	      				flag = false;
    	      				break;
						}
	
    	    			case 4: {
							freeTimeTemp = "15:00 - 17:00";
    	      				flag = false;
    	      				break;
						}

    	    			case 5: {
							freeTimeTemp = "17:00 - 19:00";
    	      				flag = false;
    	      				break;
						}

    	    			case 6: {
							freeTimeTemp = "19:00 - 21:00";
    	      				flag = false;
    	      				break;
						}	
    	    			default: {
							cout << "Invalid choice." << endl;
    	      				break;
						}

    	    		}
    	  		}
	int position ;
    for (int i = 0; i < memList.size(); i++) {
		if (memList[i].getFreeTime() == freeTimeTemp && memList[i].getStatus() == "Available") {
			position = i;
			break;
		}
	}
	flag = false;
    double creditPointsTemp, hostRatingScoreTemp;
	int positionBlockMem = findBlockedMem(username, memList[position].getUsername());
    if (position < memList.size()) {
		cout << "\033[2J\033[1;1H";
        cout << "Supporters in " << freeTimeTemp << " found: " << endl;
		for (Member &mem : memList) {
			if (mem.getUsername() == username) {
                creditPointsTemp = mem.getCreditPoints();
				hostRatingScoreTemp = mem.getHostRatingScore();
                continue;
            }
		}
		for (int i = 0; i < memList.size(); i++) {
			if (blockMemList.size() > 0) {
				for (BlockMem &blockMem : blockMemList) {
					if (blockMem.blockedMem == username && blockMem.MemBlock == memList[i].getUsername()) {
						i++;
					}
				}
			}
			if(memList[i].getFreeTime() == freeTimeTemp && memList[i].getPosition() == "Supporter" && memList[i].getConsumePoint() <= creditPointsTemp && memList[i].getStatus() == "Available" && memList[i].getMiniumHostRatingScore() <= hostRatingScoreTemp ) {
			
				cout << "Username: " << memList[i].getUsername() << endl;
        		cout << "Fullname: " << memList[i].getFullname() << endl;
        		cout << "Address: " << memList[i].getAddress() << endl;
        		cout << "Email: " << memList[i].getEmail() << endl;
        		cout << "PhoneNum: " << memList[i].getPhoneNum() << endl;
        		cout << "Best Skill: " << memList[i].getBestSkill() << endl;
        		cout << "Skill Rating Score: " << memList[i].getHostRatingScore() << endl;
        		cout << "Supporter Rating Score: " << memList[i].getSupporterRatingScore() << endl;
				cout << "Time he/she can work: " << memList[i].getFreeTime() << endl;
				cout << "Consuming point per hour: " << memList[i].getConsumePoint() << endl;
        		cout << endl;
				flag = 1;
			}
		}
		
		if (flag == true) {
        	cout << "Do you want to book any supporter in " << freeTimeTemp << "? (Y/N): ";
        	char choice;
        	cin >> choice;
        	if (choice == 'Y' || choice == 'y') {
        	    bookSup(username);
        	} else {
        	    return;
			}
		} else {
			cout << "Cannot find any supporter in " << freeTimeTemp << endl;
			cout << "\n\nPress any key to continue! \n" ;
			getch();
		}
    } else if (position >= memList.size()) {
		cout << "\033[2J\033[1;1H";
        cout << "Supporters in " << freeTimeTemp << " not found: " << endl;
		cout << "\n\nPress any key to continue! \n";
		getch();
        return;
    }
};
//Check whether input information of account is correct or not
bool System::isMemberLoginValid(const string &username1, const string &pwd1){
    for(int i = 0; i < memList.size(); i++){
        if(memList[i].getUsername() == username1 && memList[i].getPwd() == pwd1){
            return true;
        } 
    }   
    return false;
}

//Finish the request
bool System::finishRequest(const string &supName) {
    startfinishRequest: ;
	cout << "\033[2J\033[1;1H"; //Clear screen
	int id;
	if (viewBookedRequests(supName)) {
		while (1) {
			cout << "Enter the request id which you want to finish: ";
    		cin >> id;
			if (id > 0 && id <= reqList.requestListInfo.size()) {
				break;
			} else {
				cout << "Invalid choice!" << endl;
			}
		}
		cout << "Do you want to finish this request? (Y/N): ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			int positionSup = findMem(supName);
		reqList.requestListInfo[id - 1].setStatus("Finished");
		std::tm timeInfo = {};
		std::stringstream sts(reqList.requestListInfo[id - 1].getTimeReq());
		sts >> std::get_time(&timeInfo, "%a %b %d %H:%M:%S %Y");
		time_t rawtime;

    	time (&rawtime);
		string timeTemp = generateTime();

		double seconds = difftime(rawtime, mktime(&timeInfo));

		int positionHost = findMem(reqList.requestListInfo[id - 1].getHostUserName());

		memList[positionHost].setCreditPoints(memList[positionHost].getCreditPoints() - reqList.requestListInfo[id - 1].getConsumePoint() * (seconds / 3600));
		memList[positionSup].setCreditPoints(memList[positionSup].getCreditPoints() + reqList.requestListInfo[id - 1].getConsumePoint() * (seconds / 3600));

		reqList.requestListInfo[id - 1].setTimeReq(timeTemp);

    	return true;
		} else {
			return false;
		}
	} else {
		cout << "You haven't booked any host yet." << endl;
		cout << "\n\nPress any key to continue! \n" ;
		getch();
	}
    return false;
}

//Register member account
Member System::registerMem() {
	cout << "\033[2J\033[1;1H"; //Clear screen
    cout  << "To register an account you need to pay for $20\n"
        << "Please choose payment method you want to use to register account:\n"
        << "1. Internet Banking\n" 
        << "2. Credit Card" << endl;
    int paymentChoice;
	cout << "Enter your choice (1-2): ";
    cin >> paymentChoice;
    cout << "Payment successfully!\n";
    cout << "You have been deducted $20\n\n"
        << "Please enter any key to continue!";
    getch();
    cout << "\033[2J\033[1;1H"; //Clear screen
  
    string username, pwd, fullname;
    string email, address, status;
    string bestSkill;
    string phoneNum, position;
    int creditPoints;
    double host_ratingScore, skill_ratingScore, supporter_ratingScore;

    bool flag = false;
    
    while (1) {
        cout << "Enter your username: ";
        getline(cin >> std::ws, username);
		//Find the space character in username
		if (username.find(" ") != string::npos) {
			cout << "Your username should not contain space character. Please enter again." << endl;
			continue;
		} else if (!checkUsername(username)) {
        	break;
    	} else {
        	cout << "Your username is unavailable. Please enter again." << endl;
    	}
    }
    
    //Ask the user to input the password
    cout << "Enter your password: ";
    getline(cin >> std::ws, pwd);

    //Ask the user to input the fullname
    cout << "Enter your fullname: ";
    getline(cin >> std::ws, fullname);

    //Ask the user to input the email
    while (1) {
        cout << "Enter your email (example: abcdef@gmail.com): ";
        getline(cin >> std::ws, email);
    if (email.find("@gmail.com") != string::npos) {
        break;
    } else {
        cout << "Invalid email. Please enter again." << endl;
    }
    }
    
    //Ask the user to input the address
    while (1) {
        cout << "Enter your address (Ha Noi / Ho Chi Minh): ";
        getline(cin >> std::ws, address);
    if (address == "Ha Noi" || address == "Ho Chi Minh") {
        break;
    } else {
        cout << "Invalid address. Please enter again." << endl;
    }
    }

    //Ask the user to input their skill
    cout << "Enter your best skill (Maximun of 1): ";
    getline(cin >> std::ws, bestSkill);

    //Ask the user to input their phone number
    while (1)
    {
        restart: ;

        cout << "Enter your phone number (Your phone number must be contain 10 numbers): ";
        getline(cin >> std::ws, phoneNum);

        if (phoneNum.length() != 10) {
            cout << "The phone number may contain 10 digits only. \n";
            goto restart;
        } else {
            for (int i = 0; i < phoneNum.length(); i++)
            {
                if (!isdigit(phoneNum[i]))
                {
                    cout << "The phone number should be only number!";
                    goto restart;
                }
            }
        }
        break;
    }

    position = "Supporter";
    status = "Unavailable";
    creditPoints = 20;
    host_ratingScore = 0;
    skill_ratingScore = 0;
    supporter_ratingScore = 0;

    return Member(username, pwd, fullname, email, address, status, bestSkill, phoneNum, position, creditPoints);
  
}

//Check wether the username is exist in data file
bool System::checkUsername(const string &username) {
    for (Member &mem : memList) {
        if (mem.getUsername() == username) {
            return true;
        }
    }
    return false;
}

//Load all data from file
bool System::loadSupComment() {
    std::ifstream inputFile("data/supComment.txt");
    if (!inputFile) {
        cout << "Fail to open data file!" << endl;
        return false;
    }
	while (!inputFile.eof()) {
	    string s;
	    getline(inputFile, s);
	    if (!inputFile) break;
	    std::stringstream sts(s);
	    string time, nameTemp, comment, supScore, skillScore;
	    getline(sts, time, '\t');
		getline(sts, nameTemp, '\t');
	    getline(sts, supScore, '\t');
		getline(sts, skillScore, '\t');
	    getline(sts, comment);
	    supCommentList.push_back(Comment(time, "",nameTemp, comment, std::stod(skillScore) , 0 , std::stod(supScore)));
	}
	inputFile.close();
	return true;
}

//Load all data from file
bool System::loadHostComment() {
    std::ifstream inputFile("data/hostComment.txt");
    if (!inputFile) {
        cout << "Fail to open data file!" << endl;
        return false;
    }
while (!inputFile.eof()) {
    string s;
    getline(inputFile, s);
    if (!inputFile) break;
    std::stringstream sts(s);
    string time, nameTemp, comment, score;
    getline(sts, time, '\t');
    getline(sts, nameTemp, '\t');
	getline(sts, score, '\t');
    getline(sts, comment);
	string supName = "";
    hostCommentList.push_back(Comment(time, nameTemp, supName,comment, 0,std::stod(score), 0));
}
inputFile.close();
return true;
}
//Find the comment with the given host name
bool System::findHostComment(const string &hostName) {
    bool found = false;
	cout << "\033[2J\033[1;1H"; //Clear screen
    for (Comment &cmt : hostCommentList) {
        if (cmt.getHostName() == hostName) {
            cmt.showHostComment();
            found = true;
        }
    }
	cout << "Press any key to go back previous menu!" << endl;
	getch();
    if (!found) {
        cout << "No comment found!" << endl;
        return false;
    }
    return true;
}
 //Find the comment with the given host name
bool System::findSupComment(const string &supName) {
    bool found = false;
	cout << "\033[2J\033[1;1H"; //Clear screen
    for (Comment &cmt : supCommentList) {
        if (cmt.getSupName() == supName) {
            cmt.showSupComment();
            found = true;
        }
    }
	cout << "Press any key to go back previous menu!" << endl;
	getch();
    if (!found) {
        cout << "No comment found!" << endl;
        return false;
    }
    return true;
}
//Save all data to file
bool System::saveHostComment() {
    std::ofstream outputFile("data/hostComment.txt", std::ios::out);
	if (!outputFile.is_open()) {
	    cout << "Error: Failed to open/create file.\n";
	    return false;
	}

	for (Comment &cmt : hostCommentList) {
	    outputFile << cmt.getTime() << "\t" << cmt.getHostName() << "\t" << cmt.getHostScore() << "\t" << cmt.getComment() << endl;
	}

	outputFile.close();
	return true;
}
//Save all data to file
bool System::saveSupComment() {
    std::ofstream outputFile("data/supComment.txt", std::ios::out);
	if (!outputFile.is_open()) {
	    cout << "Error: Failed to open/create file.\n";
	    return false;
	}

	for (Comment &cmt : supCommentList) {
	    outputFile << cmt.getTime() << "\t" << cmt.getSupName()  << "\t" << cmt.getSupScore() << "\t" << cmt.getSkillScore() << "\t" << cmt.getComment() << endl;
	}
	outputFile.close();
	return true;
}

//Save all data to file
bool System::saveAllData() {
  	if (!saveHostComment()) {
  	  	return false;
  	};
  	if (!saveSupComment()) {
  	  	return false;
  	};
  	if (!saveMemData()) {
  	  	return false;
  	};
  	if (!reqList.SaveRequestData()) {
  	  	return false;
  	}
	if (!saveBlockMem()) {
		return false;
	}
  	return true;
}

//Read all data from file
bool System::loadAllData() {
  	if (!loadHostComment()) {
  	  	return false;
  	};
  	if (!loadSupComment()) {
  	  	return false;
  	};
  	if (!loadMemData()) {
  	  	return false;
  	};
  	if (!reqList.LoadAllData()) {
  	  	return false;
  	}
	if (!loadBlockMem()) {
		return false;
	}
  	return true;
}

//Chang day from string to num
void changeDay(string &dayS, int &day) {
	if (dayS == "Mon") {
		day = 2;
	} else if (dayS == "Tue") {
		day = 3;
	} else if (dayS == "Wed") {
		day = 4;
	} else if (dayS == "Thu") {
		day = 5;
	} else if (dayS == "Fri") {
		day = 6;
	} else if (dayS == "Sat") {
		day = 7;
	} else if (dayS == "Sun") {
		day = 8;
	}
}

//Erase non-accepted request with overllaped time
void System::eraseNonAcceptedRequest() {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   	for (int i = 0; i < reqList.requestListInfo.size(); i++) {
		if (reqList.requestListInfo[i].getStatus() == "Waiting") {
			std::tm timeInfo = {};
			std::stringstream sts(reqList.requestListInfo[i].getTimeReq());
			sts >> std::get_time(&timeInfo, "%a %b %d %H:%M:%S %Y");
			time_t rawtime;

    		time (&rawtime);

			double seconds = difftime(rawtime, mktime(&timeInfo));
			if (seconds > 7200) {
				reqList.requestListInfo.erase(reqList.requestListInfo.begin() + i);
			}
		}
	}
};