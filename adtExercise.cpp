#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class USER {
public:
	USER();
	USER(std::string name, std::string password, int score);
	~USER();
	std::string getUsername(){ return name; };
	std::string getPassword(){ return password; };
	int getScore(){ return score; };

private:
	std::string name;
	std::string password;
	int score;
};
//ADT

USER::USER() { name=""; password=""; score=0; }
USER::USER(std::string n, std::string p, int s) {name= n;password = p;score= s;}
USER::~USER() { }
//C0nstructor and destructor
USER login() {
	std::string username, password;
	std::cout << "Pls enter username: ";
	std::cin >> username;
	std::cout << "Pls enter password: ";
	std::cin >> password;

	std::ifstream inputFile("usersfile.txt");
	std::string user, pswd;
	int fileScore;

	bool found = false;
	while (inputFile >> user >> pswd >> fileScore) {
	if (username == user) {
		found = true;
		int trial=0;
		while (password != pswd&&trial<3) {
			std::cout << "Password error. Please enter again: ";
			std::cin >> password;
			trial++;
		}
		if(trial==3){
			std::cout<<"Too many tries, rerun the program";
			std::exit(0);
		}
		std::cout << "Log in successful\n";
		USER loggedIn(user, pswd, fileScore);
		std::cout << "Username : " << loggedIn.getUsername() << "\n";
		std::cout << "Score    : " << loggedIn.getScore()    << "\n";
		return loggedIn;
		}//Check a line if the user is found
	}
	//Read the file
	inputFile.close();
	if (!found) {
        	std::cout << "Creating new user\n";
		std::ofstream outputFile("usersfile.txt", std::ios::app);
		outputFile << username << " " << password << " " << 0 << "\n";
		outputFile.close();
		USER newUser(username, password, 0);
		return newUser;
		}//If user is not found, create new USER instance 
	return USER();
}

int main() {
	USER currentUser = login();
	std::cout << "Session score: " << currentUser.getScore() << "\n";
	return 0;
}
