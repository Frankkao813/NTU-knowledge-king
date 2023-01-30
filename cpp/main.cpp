// #include<iostream>
// #include<string>
// #include<vector> 
// #include<fstream> // for file input and output
// #include<sstream> // istringstream
// #include <cstdlib> /* about random */
// #include <ctime> /* about time */
// #include <conio.h>/* kbhit */
#include "../hpp/Question.hpp"
#include "../hpp/User_State.hpp"

using namespace std;

int main(){	
	std::string dir = "../game_file/user_info.txt";
	User** allUser = new User*[MAX_USER_NUM]; // the pointer array to store all users
	fileInput(dir, allUser);
	
	/*
	// test - if the class function can be correctly used
	for(int i = 0; i < curr_active_user; i++)
		//allUser[i] -> add_time_used(20);
	*/
		 

	/*
	// test - find if a user is in our system
	int index = findUser("testCoco", "NTUIM2021", allUser);
	cout << index;
	
	*/
	
	
	// test - print all current existing users
	for(int i = 0; i < curr_active_user; i++)
		 allUser[i] -> print();
	
	
	// login
	//int index = Login(allUser);
	intro(allUser); //return; 
	

	
	// output to a file
	fileOutput(dir, allUser);

	return 0;
}
