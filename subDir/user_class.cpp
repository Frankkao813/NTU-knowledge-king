#include<iostream>
#include<string>
#include<vector> 
#include<fstream> // for file input and output

using namespace std;

const int MAX_ACC_PASS_LEN = 11; // the maximum account and password length a person can set
int curr_active_user = 0; // record the number of active user 
const int MAX_USER_NUM = 100;

class User{
	friend void fileInput(string dir, User** allUser);
	friend int findUser(string user, User** allUser);
	friend void createUser(User** allUser);
	friend int Login(User** allUser);
	private:
		float time_used; // probably will convert to second
		int total_ques_answered; // the total questions answered
		int life; // five life at the start of the game. If it is deducted to zero, he/ she will wait for 10 mins(?
		int current_lv; 
		string username;
		string password; 
		bool account_status; // ok
		// bool banned_status; //  wait for 10 minutes - not implemented yet
		
		
	public:
		User(string name, string pass);
		User(string username, string password, int trial_used, int time_used, int life, int current_lv, bool account_status); //constructor overloading
		bool deduct_life();
		void add_time_used(int time_in_question);
		void add_total_ques_answered(); // increment by 1 by default
		bool increment_lv(); // one question correct, then the user can increment one level 
		void decrement_lv(); // one question wrong, then the user will decrement one level
		
		int get_time_used(); // getter
		int get_total_ques_answered(); // getter 
		string get_username(); // getter
		string get_password(); // getter
		int get_life(); // getter
		int get_account_status(); // getter
		int get_current_lv(); // getter // not implemented
		void print(); // to check if the member information is constructed correctly
};

User::User(string username, string password){
	curr_active_user++;
	this ->time_used = 0;
	this -> total_ques_answered = 0;
	this -> life = 5;
	this -> username = username;
	this -> password = password; 
	this -> account_status = 1; // status normal 
	this -> current_lv = 1;
	//this -> login_status = 1; // the person can log into the account;
}
User::User(string username, string password, int total_ques_answered, int time_used, int life, int current_lv, bool account_status){
	curr_active_user++;
	this -> username = username;
	this -> password = password; 
	this -> total_ques_answered = total_ques_answered;
	this -> time_used = time_used;
	this -> life = life;
	this -> current_lv = current_lv;
	this -> account_status = account_status;
	
}

bool User::deduct_life(){
	this -> life -= 1;
	// check if the life is greater than 0
	if(this -> life >= 0)
		return true;
	else
		return false;
		
}

void User::add_time_used(int time_in_question){
	this -> time_used += time_in_question;
}

bool User::increment_lv(){
	this -> current_lv += 1;
	if(this -> current_lv == 8){
		return true;
	}
	else
		return false;
	
}

void User::decrement_lv(){
	if(this -> current_lv - 1 == 0)
		this -> current_lv = 1;
	else
		this -> current_lv -= 1;
}

void User::add_total_ques_answered(){
	this -> total_ques_answered += 1;
}

int User::get_time_used(){
	return this -> time_used; // in second
}

int User::get_total_ques_answered(){
	return this -> total_ques_answered;
}

string User::get_username(){
	return this -> username;
}

string User::get_password(){
	return this -> password;
} 

int User::get_life(){
	return this -> life;
}

int User::get_current_lv(){
	return this->current_lv;
}
int User::get_account_status(){
	return this-> account_status;
}
void User::print(){
	cout << "Account name: " << this -> username << endl; 
	cout << "Account Password: " << this -> password << endl;
	cout << "time used: " << this -> time_used << endl;
	cout << "trial used: " << this -> total_ques_answered << endl;
	cout << "life: " << this -> life << endl; 
	cout << "current level " << this -> current_lv << endl; 
	cout << "Account status: " << this -> account_status << endl;
	//cout << "login status: " << this -> login_status << endl;
	cout << "................................" << endl;
	return;
}
void fileInput(string dir, User** allUser){
	// string username, string password, int trial_used, int time_used, int life, bool account_status
	curr_active_user = 0; // reset
	ifstream userFile;
	userFile.open(dir);
	if(!userFile)
		cout << "no file exists";
	else{
		string tmp_username;
		string tmp_password;
		int tmp_total_ques_answered;
		int tmp_time_used;
		int tmp_life;
		int tmp_current_lv;
		bool tmp_account_status;
		
		while(userFile >> tmp_username >> tmp_password >> tmp_total_ques_answered >> tmp_time_used >> tmp_life >> tmp_current_lv >> tmp_account_status){
			//curr_active_user += 1;
			allUser[curr_active_user - 1] = new User(tmp_username, tmp_password, tmp_total_ques_answered, 
											tmp_time_used, tmp_life, tmp_current_lv,  tmp_account_status);
		}
			
	}
	userFile.close();
}
void fileOutput(string dir, User** allUser){
	ofstream userFile;
	userFile.open(dir);
	if(!userFile)
		cout << "no file exists!";
	else{
		for(int i = 0; i < curr_active_user; i++)
			userFile << allUser[i] -> get_username() << " " << allUser[i] -> get_password() << " " <<
			allUser[i] -> get_total_ques_answered() << " " << allUser[i] -> get_time_used() << " " <<allUser[i] -> get_life() <<" "
			<< allUser[i]  -> get_current_lv() << " "  << allUser[i] -> get_account_status() <<  "\n"; // ???
			
			//userFile << "\n"; 
	}
	
	userFile.close();
		
}

int findUser(string user, User** allUser){
	// string comparison
	for(int i = 0; i < curr_active_user; i++){
		if(allUser[i] -> username == user)
			return i;
	}
	// cout << "User not found!";
	return -1; // not found any user having the user and password 
		
}

void createUser(User** allUser){ // put all User to global variable? 
	string username_store;
	string password_store;
	cout << "Please enter the account name to create the account (maximum length 10): ";
	cin >> username_store;
	cout << "Please enter the password to create the acoount (maximum length 10): ";
	cin >> password_store;
	cout << endl;
	
	cout << username_store.size();
	cout << password_store.size();
	
	int check_user = findUser(username_store, allUser);
	char continue_status = 0;
	if(check_user == -1){
		if(username_store.size() > MAX_ACC_PASS_LEN || password_store.size() > MAX_ACC_PASS_LEN){
			cout << "length of username or password is not correct (maximum 10 characters)" << endl;
			cout << "Do you want to try again? (Y/N)";
			cin >> continue_status;
			if(continue_status == 'Y')
				createUser(allUser); // will this line cause problem?
			else
				return;
		}
		else{
			cout << "Welcome out new member!";	
			allUser[curr_active_user - 1] = new User(username_store, password_store);
			return;
			
		}
			
	}
	//else // check	
		
}

int Login(User** allUser){
	string account_store;
	string password_store;
	cout << "Please enter your account name";
	cin >> account_store;
	//cout << "\n";
	
	cout << "Please enter your password!";
	cin >> password_store;
	 
	for(int i = 0; i < curr_active_user; i++){
		if(allUser[i] -> username == account_store && allUser[i] -> password == password_store){ 
			// enter to the next page - hasn't been implemented
			cout << "Welcome!";
			return i; // index of the user	
		}		
	} 
	// if the function doesn;t return, it means that the user might not registered or typed the wrong account/password
	char continue_status = 0;
	cout << "The account or password isn't correct. Do you want to try again?(Y/N): ";
	cin >> continue_status;
	
	if(continue_status == 'Y')
		Login(allUser);
	else
		return -1;
}


int main(){
	string dir = "../user_info.txt";
	// vector<string> user = {"testCoco", "testBonnie", "testAnn"};
	// vector<string> pass = {"NTUIM2021", "NTUCH2021", "MATH2001"};
	//User testUser(user[], pass);
	//testUser.print();
	
	
	User** allUser = new User*[MAX_USER_NUM]; // the pointer array to store all users
//	int current_user = user.size();
//	//cout << current_user;
//	for(int i = 0; i < current_user; i++){
//		allUser[i] = new User(user[i], pass[i]);
//		curr_active_user += 1; 
//	}
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
	int index = Login(allUser);
	if(index != -1)
		allUser[index] -> print();
	
	// output to a file
	fileOutput(dir, allUser);

	return 0;
}
