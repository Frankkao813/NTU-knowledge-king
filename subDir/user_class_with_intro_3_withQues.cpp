#include<iostream>
#include<string>
#include<vector> 
#include<fstream> // for file input and output
#include<sstream> // istringstream

using namespace std;

const int MAX_ACC_PASS_LEN = 11; // the maximum account and password length a person can set
int curr_active_user = 0; // record the number of active user 
const int MAX_USER_NUM = 100;
const int NUM_OPTION = 4;

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
		string wish; // the wish that user makes after clearing the game
		bool wish_status; // whether the wish is private
		
	public:
		User(string name, string pass);
		User(string username, string password, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, string wish, bool wish_status);
		void add_time_used(int time_in_question);
		void add_total_ques_answered(); // increment by 1 by default
		bool increment_lv(); // one question correct, then the user can increment one level 
		void decrement_lv(); // one question wrong, then the user will decrement one level
		bool deduct_life();
		int get_time_used(){return this -> time_used;} // getter
		int get_total_ques_answered(){return this -> total_ques_answered;} // getter 
		string get_username(){return this -> username;} // getter
		string get_password(){return this ->password;} // getter
		int get_life(){return this -> life;} // getter
		int get_account_status(){return this -> account_status;} // getter
		int get_current_lv(){return this->current_lv;} // getter // not implemented
		string get_wish(){return this -> wish;}
		bool get_wish_status(){return this -> wish_status;}
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
	this -> wish = "0";
	this -> wish_status = 0;
	//this -> login_status = 1; // the person can log into the account;
}
User::User(string username, string password, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, string wish, bool wish_status){
	curr_active_user++;
	this -> username = username;
	this -> password = password; 
	this -> total_ques_answered = total_ques_answered;
	this -> time_used = time_used;
	this -> life = life;
	this -> current_lv = current_lv;
	this -> account_status = account_status;
	this -> wish = wish;
	this -> wish_status = wish_status; 
	
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

void User::print(){
	cout << "Account name: " << this -> username << endl; 
	cout << "Account Password: " << this -> password << endl;
	cout << "time used: " << this -> time_used << endl;
	cout << "trial used: " << this -> total_ques_answered << endl;
	cout << "life: " << this -> life << endl; 
	cout << "current level " << this -> current_lv << endl; 
	cout << "Account status: " << this -> account_status << endl;
	//cout << "login status: " << this -> login_status << endl;
	cout << "wish: " << this -> wish << endl;
	cout << "wish status: " << this -> wish_status << endl; 
	cout << "................................" << endl;
	return;
}

class Question{
	friend class check_answer;
	private:
		int num_question;
		vector<string> ques_vec; // a single dimensional vector storing the questions
		vector<vector<string>> option_vec; // a two dimensional vector storing options (4 options)
		vector<string> answer_vec; // a single dimensional vector storing the answer of the answer to the question;
	public:
		Question(); // constructor, questions, options, and answers will also be written into it
		string get_ques(int ind_ques){return ques_vec[ind_ques];} // get the desired question
		string get_option(int row, int col){return option_vec[row][col];} // get the desired option
		// int get_ans(int ind_ans); // to obtain the answer to the question
		bool check_answer(int ind_ques, string userInput); // to check if the answer is correct
};

Question::Question(){

	// file input - question file(in ansi format)
	// note that in visual studio code, the default encoding is utf-8
	std::ifstream quesFile("../question_ansi.txt");
	std::string quesStr;
	if(quesFile){
		while(std::getline(quesFile, quesStr)){
			//cout << quesStr << endl;
			ques_vec.push_back(quesStr);
		}	
	}
	quesFile.close();
	
	// option
	
	fstream optFile("../options_ansi.txt");
	string line;
	int index_vector = 0;
	if(optFile){
			// changing the line (type: string) to input stream	
		string option_line;
		while (getline(optFile, option_line,'\n')) {
		 	istringstream templine(option_line);
			option_vec.push_back(vector<string>()); // pushback an empty string vector
			index_vector += 1;
			string option;
			while(getline(templine, option, ',')){
				option_vec[index_vector - 1].push_back(option);
				//cout << index_vector << endl; 
				//cout << option << endl;
			}
		}	
	}	
	optFile.close();

	
	
	// answer

	fstream answerFile("../answer_ansi.txt");
	string answer_char;
	if(answerFile){
		while(answerFile >> answer_char)
			answer_vec.push_back(answer_char);
	}
	answerFile.close();


	//cout << option_vec.size() << endl;
	//cout << ques_vec.size() << endl;
	//cout << answer_vec.size() << endl;

}


// to check if the user inputs the correct answer
bool Question::check_answer(int i, string userInput){
	if(answer_vec[i] == userInput)
		return true;
	else
		return false;
}


void fileInput(string dir, User** allUser);
void fileOutput(string dir, User** allUser);
int findUser(string user, User** allUser);
void createUser(User** allUser); // put all User to global variable? 
int Login(User** allUser);
void welcome(User** allUser);
void intro(User** allUser, int user_ind);
void story(User** allUser, int user_ind);
void ranking(User** allUser, int user_ind);
void gameState(User** allUser, int user_ind);


int main(){	
	string dir = "../user_info.txt";
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
	welcome(allUser); //return; 
	
//	if(index != -1)
//		allUser[index] -> print();
	
	// output to a file
	fileOutput(dir, allUser);

	return 0;
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
		string tmp_wish;
		bool tmp_wish_status;
		
		while(userFile >> tmp_username >> tmp_password >> tmp_total_ques_answered >> tmp_time_used >> 
		tmp_life >> tmp_current_lv >> tmp_account_status >> tmp_wish >> tmp_wish_status){
			//curr_active_user += 1;
			allUser[curr_active_user - 1] = new User(tmp_username, tmp_password, tmp_total_ques_answered, 
											tmp_time_used, tmp_life, tmp_current_lv,  tmp_account_status, tmp_wish, tmp_wish_status);
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
			<< allUser[i]  -> get_current_lv() << " "  << allUser[i] -> get_account_status() <<  allUser[i] -> get_wish() << " " << allUser[i] -> get_wish_status() << "\n"; // ???
			
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
				welcome(allUser);
		}
		else{
			cout << "Welcome out new member!";	
			allUser[curr_active_user - 1] = new User(username_store, password_store);
			for(int i = 0; i < curr_active_user; i++)
		 		allUser[i] -> print();
			welcome(allUser);
			
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

void welcome(User** allUser)
{
	cout << "Welcome to 台大知識王." << "\n" << "Press 1 to sign up" << "\n" << "Press 2 to log in"<< "\n";
	int status = 0;
	cin >> status;
	if(status == 1)
	{
		createUser(allUser);
		welcome(allUser);
	}
	else if(status == 2)
	{
		int index = Login(allUser);
		intro(allUser, index);
	}
	else
	{
		welcome(allUser);
	}
}

void intro(User** allUser, int user_ind)
{
	cout << "welcome!" << allUser[user_ind] -> get_username() << endl; 
	cout << "Press 1 to read the story" << "\n" << "Press 2 to see the ranking" << "\n" << "Press 3 to start the game" << "\n";
	int status = 0;
	cin >> status;
	if(status == 1) // story
	{
		story(allUser, user_ind);
	}
	else if(status == 2) // ranking
	{
		ranking(allUser, user_ind);
	}
	else if(status == 3) //start
	{
		gameState(allUser, user_ind);
	}
}


void story(User** allUser, int user_ind)
{
	cout << "小明是一位資管系大一的學生，最近在學習程式設計class與operator overloading等進階概念時遇到了很大的困難，且嘗試了很多方法仍效果不彰。最近他突然想到魔法這個手段他還沒有用過，可能可以幫助他順利領悟。" 
	<< "\n" << "碰巧在一次的跳蚤市場中，小明看到了號稱是阿拉丁神燈的藏寶圖。抱著想要找到精靈的決心，他就把它買了下來，並且在一天的午後實際前往了藏寶地點。出乎他意料的是那邊真的有一個茶壺!" <<  "\n" <<
	"不幸的是，茶壺的上面寫著只有通過7個有關於台大或生活的問答題才能順利召喚神燈裡的精靈。期被程式語言折磨的小明已經沒有多餘的力氣想題目了。聰明的你，能夠幫助他透過精靈度過必修課的挑戰嗎?"<<  "\n" <<
	"規則:" << "\n" << "1.每一次的遊戲當中，你將要答7題由簡單到難的題目。每答對一題就會往上一個等級，但相對的。每答錯一題就會往後退一個等級。"<< "\n" <<
	"2.每一次的遊戲不能錯超過五題，超過的話會被停權10分鐘。"<< "\n" <<"3.勝利條件: 順利答對等級7的題目。達成之後即可向神燈精靈提出一個願望。" <<"\n" ;
	cout << "Back to menu?(Y/N)";
	char answer = 0;
	cin >> answer;
	if(answer == 'Y')
		intro(allUser, user_ind);
	else
		story(allUser, user_ind);
}

void ranking(User** allUser, int user_ind)
{
	cout << "排名待補" << "\n";
	cout << "Back to menu?(Y/N)";
	char answer = 0;
	cin >> answer;
	if(answer == 'Y')
		intro(allUser, user_ind);
	else
		ranking(allUser, user_ind);
}

void gameState(User** allUser, int user_ind){
	
	Question ques_obj;
	string userInput; 
	bool correctness = false;
	
	for(int i = 0; i < 4; i++){
		//to do:  the program to pick the question randomly...probably a function can help
		
		string question_title = ques_obj.get_ques(i);
		cout << question_title;
		cout << endl;
		for(int j = 0;  j < NUM_OPTION; j++)
			cout << "["<<  static_cast<char>(65 + j) <<  "] "  << ques_obj.get_option(i, j) << " ";
		cout << endl;
		cout << "Please input your answer: ";
		cin >> userInput;
		correctness = ques_obj.check_answer(i, userInput);
		if(correctness == true)
			cout << "Congratulations!";
		else{
			cout << "Oops! You get the wrong answer.";
			allUser[user_ind] -> deduct_life();
			cout << "the current life is..." << allUser[user_ind] -> get_life() << endl;
		}
			
		
		cout << endl;
		cout << endl;
	} 
	
	//cout << "hello!" << endl;
}
