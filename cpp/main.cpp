#include<iostream>
#include<string>
#include<vector> 
#include<fstream> // for file input and output
#include<sstream> // istringstream
#include <cstdlib> /* about random */
#include <ctime> /* about time */
// #include <conio.h>/* kbhit */
#include "../hpp/Question.hpp"
#include "../hpp/User_State.hpp"

using namespace std;

// const int MAX_ACC_PASS_LEN = 11; // the maximum account and password length a person can set
// int curr_active_user = 0; // record the number of active user 
// const int MAX_USER_NUM = 100;
// const int NUM_OPTION = 4;
// const int LEVEL = 7;
// const int RESPONSE_TIME = 10;
// const int USER_BANNED_TIME = 300;

// class User{
// 	friend void fileInput(string dir, User** allUser);
// 	friend int findUser(string user, User** allUser);
// 	friend void createUser(User** allUser);
// 	friend void Login(User** allUser);
// 	private:
// 		float time_used; // probably will convert to second
// 		int total_ques_answered; // the total questions answered
// 		int life; // five life at the start of the game. If it is deducted to zero, he/ she will wait for 10 mins(?
// 		int current_lv; 
// 		string username;
// 		string password;
// 		bool complete_status; // state whether the user completed the game 
// 		bool account_status; // check if the account is set up properly
// 		string wish; // the wish that user makes after clearing the game
// 		bool wish_status; // whether the wish is private
// 		bool banned_status; 
// 		int banned_time;
// 	public:
// 		User(string name, string pass);
// 		User(string username, string password, bool complete_status, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, string wish, bool wish_status, bool banned_status, int banned_time);
// 		void add_time_used(int time_in_question);
// 		void add_total_ques_answered(); // increment by 1 by default
// 		void increment_lv(); // one question correct, then the user can increment one level 
// 		void decrement_lv(); // one question wrong, then the user will decrement one level
// 		void deduct_life(); // one question wrong, then then user will decrement one life
// 		void set_banned_time(int time_in_sec){this -> banned_time = time_in_sec; } // setter // record the time that the user start to be banned!
// 		void set_banned_status(bool status){this -> banned_status = status; } // setter // when recording the banned time, set the banned_status to be true;
// 		void set_complete_status(bool comp_status){this -> complete_status = comp_status;} // setter
// 		void set_wish(string add_wish){this -> wish = add_wish;} // set the wishes of the user if he/she complete the game
// 		void set_wish_status(bool wishStatus){this -> wish_status = wishStatus;}
// 		void refill_life(); // life refill to 5 after a game 
		
// 		int get_time_used(){return this -> time_used;} // getter
// 		int get_total_ques_answered(){return this -> total_ques_answered;} // getter 
// 		string get_username(){return this -> username;} // getter
// 		string get_password(){return this ->password;} // getter
// 		bool get_complete_status(){return this -> complete_status;} // getter
// 		int get_life(){return this -> life;} // getter
// 		int get_account_status(){return this -> account_status;} // getter
// 		int get_current_lv(){return this->current_lv;} // getter // not 
// 		string get_wish(){return this -> wish;}
// 		bool get_wish_status(){return this -> wish_status;}
// 		bool get_banned_status(){return this-> banned_status;}
// 		int get_banned_time(){return this -> banned_time;}
// 		void print(); // to check if the member information is constructed correctly
// };

// User::User(string username, string password){
// 	curr_active_user++;
// 	this -> time_used = 0;
// 	this -> total_ques_answered = 0;
// 	this -> life = 5;
// 	this -> username = username;
// 	this -> password = password; 
// 	this -> complete_status = 0;
// 	this -> account_status = 1; // status normal 
// 	this -> current_lv = 1;
// 	this -> wish = "NA";
// 	this -> wish_status = 0;
// 	this -> banned_status = 0;
// 	this -> banned_time = 0;
// 	//this -> login_status = 1; // the person can log into the account;
// }
// User::User(string username, string password, bool complete_status, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, string wish, bool wish_status, bool banned_status, int banned_time){
// 	curr_active_user++;
// 	this -> username = username;
// 	this -> password = password; 
// 	this -> complete_status = complete_status; 
// 	this -> total_ques_answered = total_ques_answered;
// 	this -> time_used = time_used;
// 	this -> life = life;
// 	this -> current_lv = current_lv;
// 	this -> account_status = account_status;
// 	this -> wish = wish;
// 	this -> wish_status = wish_status; 
// 	this -> banned_status = banned_status;
// 	this -> banned_time = banned_time; 
	
// }

// void User::deduct_life(){
// 	this -> life -= 1;
// 	// check if the life is greater than 0
// 	// if(this -> life >= 0)
// 	// 	return true;
// 	// else
// 	// 	return false;
		
// }
// void User::refill_life(){
// 	this -> life = 5;
// }

// void User::add_time_used(int time_in_question){
// 	this -> time_used += time_in_question;
// }

// void User::increment_lv(){
// 	this -> current_lv += 1;
// 	// if(this -> current_lv == 8){
// 	// 	return true;
// 	// }
// 	// else
// 	// 	return false;
	
// }

// void User::decrement_lv(){
// 	if(this -> current_lv - 1 == 0)
// 		this -> current_lv = 1;
// 	else
// 		this -> current_lv -= 1;
// }

// void User::add_total_ques_answered(){
// 	this -> total_ques_answered += 1;
// }

// void User::print(){
// 	cout << "帳號名稱 : " << this -> username << endl; 
// 	cout << "帳號密碼 : " << this -> password << endl;
// 	cout << "是否已完全破關 : ";
// 	if(this -> complete_status)
// 		cout << "是" << endl;
// 	else
// 		cout << "否" << endl;
// 	cout << "花費時間 : " << this -> time_used << endl;
// 	cout << "答題次數 : " << this -> total_ques_answered << endl;
// 	cout << "生命值 : " << this -> life << endl; 
// 	cout << "現在關卡 : " << this -> current_lv << endl; 
// 	cout << "帳號狀態 : " << this -> account_status << endl;
// 	//cout << "login status: " << this -> login_status << endl;
// 	cout << "願望 : " << this -> wish << endl;
// 	cout << "願望狀態 : " << this -> wish_status << endl; 
// 	cout << "是否可以遊玩 : ";
// 	if(this -> banned_status)
// 		cout << "不行" << endl;
// 	else
// 		cout << "可以" << endl; 
// 	cout << "剩餘禁止時間(秒) : ";
// 	if(this -> banned_time == 0)
// 		cout << 0 << endl;
// 	else{

// 		if((time(NULL) - this -> banned_time) <= USER_BANNED_TIME)
// 			cout << (time(NULL) - this -> banned_time) << endl;
// 		else{
// 			//this -> banned_time = 0; // reset to zero
// 			cout << 0 << endl;
// 		}
			
// 	}
		
// 	cout << "................................" << endl;
// 	return;
// }


// void fileInput(string dir, User** allUser);
// void fileOutput(string dir, User** allUser);
// int findUser(string user, User** allUser);
// void createUser(User** allUser); // put all User to global variable? 
// void Login(User** allUser);
// void welcome(User** allUser);
// void internal_welcome(User** allUser, int user_ind);
// void player_info(User** allUser, int user_ind);
// void intro(User** allUser);
// void story(User** allUser);
// void ranking(User** allUser);
// void sortSuccessUser(User** success_user, int success_num);
// void gameState(User** allUser, int user_ind);
// void setUserWish(User** allUser, int user_ind);


int main(){	
	string dir = "../game_file/user_info.txt";
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
	
//	if(index != -1)
//		allUser[index] -> print();
	
	// output to a file
	fileOutput(dir, allUser);

	return 0;
}

// void fileInput(string dir, User** allUser){
// 	// string username, string password, int trial_used, int time_used, int life, bool account_status
// 	curr_active_user = 0; // reset
// 	ifstream userFile;
// 	userFile.open(dir);
// 	if(!userFile)
// 		cout << "沒有任何紀錄";
// 	else{
// 		string tmp_username;
// 		string tmp_password;
// 		bool tmp_complete_status;
// 		int tmp_total_ques_answered;
// 		int tmp_time_used;
// 		int tmp_life;
// 		int tmp_current_lv;
// 		bool tmp_account_status;
// 		string tmp_wish;
// 		bool tmp_wish_status;
// 		bool tmp_banned_status;
// 		int tmp_banned_time;
		
// 		while(userFile >> tmp_username >>  tmp_password >> tmp_complete_status >> tmp_total_ques_answered >> tmp_time_used >> 
// 		tmp_life >> tmp_current_lv >> tmp_account_status >> tmp_wish >> tmp_wish_status >> tmp_banned_status >> tmp_banned_time){
// 			//curr_active_user += 1;
// 			allUser[curr_active_user - 1] = new User(tmp_username, tmp_password, tmp_complete_status,
// 											 tmp_total_ques_answered, tmp_time_used, tmp_life, tmp_current_lv,  
// 											 tmp_account_status, tmp_wish, tmp_wish_status, tmp_banned_status,
// 											  tmp_banned_time);
// 		}
			
// 	}
// 	userFile.close();
// }

// void fileOutput(string dir, User** allUser){
	
// 	ofstream userFile;
// 	userFile.open(dir);
	
// 	if(!userFile)
// 		cout << "沒有任何紀錄";
// 	else{
// 		for(int i = 0; i < curr_active_user; i++)
// 			userFile << allUser[i] -> get_username() << " " << allUser[i] -> get_password() << " " 
// 			<< allUser[i] -> get_complete_status() << " "<< allUser[i] -> get_total_ques_answered() << " " 
// 			<< allUser[i] -> get_time_used() << " " <<allUser[i] -> get_life() <<" "
// 			<< allUser[i]  -> get_current_lv() << " "  << allUser[i] -> get_account_status() << " " << allUser[i] -> get_wish() << " " << 
// 			allUser[i] -> get_wish_status() <<  " " << allUser[i] -> get_banned_status() << " " << 
// 			allUser[i] -> get_banned_time() << "\n"; 
			
// 			//userFile << "\n"; 
// 	}
	
// 	userFile.close();
		
// }

// int findUser(string user, User** allUser){
// 	// string comparison
// 	for(int i = 0; i < curr_active_user; i++){
// 		if(allUser[i] -> username == user)
// 			return i;
// 	}
// 	// cout << "User not found!";
// 	return -1; // not found any user having the user and password 
		
// }

// void createUser(User** allUser){ // put all User to global variable? 
// 	string username_store;
// 	string password_store;
// 	cout << "請輸入帳號名稱來創建帳號(英文、數字及符號以十個字為上限，中文字五個為上限) : ";
// 	cin >> username_store;
// 	cout << "請輸入帳號密碼來創建帳號(英文、數字及符號以十個字為上限，中文字五個為上限) : ";
// 	cin >> password_store;
// 	cout << endl;
	
// 	//cout << username_store.size();
// 	//cout << password_store.size();
	
// 	int check_user = findUser(username_store, allUser);
// 	char continue_status = 0;
// 	if(check_user == -1){
// 		if(username_store.size() > MAX_ACC_PASS_LEN || password_store.size() > MAX_ACC_PASS_LEN){
// 			cout << "帳號名稱或密碼不符合規定(英文、數字及符號以十個字為上限，中文字五個為上限)" << endl;
// 			cout << "您要再試一次嗎？ (Y/N)";
// 			cin >> continue_status;
// 			if(continue_status == 'Y')
// 				createUser(allUser); // will this line cause problem?
// 			else
// 				welcome(allUser);
// 		}
// 		else{
// 			cout << "歡迎加入我們，新夥伴！" << "\n";	
// 			allUser[curr_active_user - 1] = new User(username_store, password_store);
// //			for(int i = 0; i < curr_active_user; i++)
// //		 		allUser[i] -> print();
// 			internal_welcome(allUser, (curr_active_user - 1));
// 			//gameState(allUser, (curr_active_user - 1));
			
// 		}
// 	}
// 	else{
// 		//while(true){
// 		cout << "這個名字已經被註冊過了" << "\n" << "請按 1 創建別的帳號" <<"\n" <<"請按 2 登入遊戲" << "\n";
// 		int answer = 0;
// 		cin >> answer;
// 		if(answer == 1)
// 			createUser(allUser);
// 		else
// 		 	Login(allUser);
// 	}
// 	//}
// }

// void Login(User** allUser){
// 	string account_store;
// 	string password_store;
// 	cout << "請輸入您的帳號名稱 : ";
// 	cin >> account_store;
// 	//cout << "\n";
	
// 	cout << "請輸入您的帳號密碼 : ";
// 	cin >> password_store;
	
// 	int user_ind = -1;
// 	for(int i = 0; i < curr_active_user; i++){
// 		if(allUser[i] -> username == account_store && allUser[i] -> password == password_store) 
// 			user_ind = i;
// 	} 
	
// 	if(user_ind != -1){

// 			cout << "歡迎！" << endl;
// 			//allUser[user_ind] -> banned_status = false;
// 			internal_welcome(allUser, user_ind);
// 		// }	
// 	}
// 	else{
// 		// if the function doesn;t return, it means that the user might not registered or typed the wrong account/password
// 		char continue_status = 0;
// 		cout << "帳號名稱或密碼不正確(英文、數字及符號以十個字為上限，中文字五個為上限)。您要再試一次嗎？ (Y/N)";
// 		cin >> continue_status;
		
// 		if(continue_status == 'Y')
// 			Login(allUser);
// 		else
// 			welcome(allUser);	
// 	}

// }

// void internal_welcome(User** allUser, int user_ind){
// 	cout << "歡迎進入遊戲！我們的冒險者 : " << allUser[user_ind] -> get_username() << "！" << endl;
// 	cout << "請選擇 : " << endl;
// 	cout << "[1] 開始挑戰   [2] 登出  [3] 查看帳號資訊" << endl;
// 	int flag;
// 	cin >> flag;
// 	if(flag == 1){ //char flag != int 1 !!
// 		// write all the situation where a person can't play the game here
// 		if(allUser[user_ind] -> get_banned_status() == true && (time(nullptr) - allUser[user_ind] -> get_banned_time() <= USER_BANNED_TIME) ){
// 			cout << "您現在不能進入遊戲，因為目前帳號已被暫時凍結..." << endl;
// 			cout << "回到登入介面" << endl;
// 			internal_welcome(allUser, user_ind);
// 		}
// 		else if(allUser[user_ind] -> get_complete_status() == true){
// 			cout << "一個人只有一次許願的機會，不可以貪心..." << endl;
// 			cout << "回到登入介面";
// 			internal_welcome(allUser, user_ind);
// 		}
// 		else{
// 			allUser[user_ind] -> set_banned_status(false); 
// 			gameState(allUser, user_ind);
// 		}
// 	} 
// 	else if(flag == 2) 
// 		welcome(allUser);
// 	else if(flag == 3)
// 		player_info(allUser, user_ind);
// 	else
// 		internal_welcome(allUser, user_ind);
	
// }

// void player_info(User** allUser, int user_ind){
// 	allUser[user_ind] -> print();
// 	char flag;
// 	cout << "回到登入介面？ (Y/N)";
// 	cin >> flag;
// 	if(flag == 'Y')
// 		internal_welcome(allUser, user_ind);
// 	else
// 		player_info(allUser, user_ind);
// }

// void welcome(User** allUser)
// {
// 	cout << "準備好開始挑戰了嗎？" << "\n" << "按 1 創建帳號" << "\n" << "按 2 登入帳號"<< "\n" << "按 3 回到主選單" << "\n";
// 	int status = 0;
// 	cin >> status;
// 	if(status == 1)
// 	{
// 		createUser(allUser);
// 	}
// 	else if(status == 2)
// 	{
// 		Login(allUser);
// 	}
// 	else if(status == 3)
// 	{
// 		//welcome(allUser);
// 		intro(allUser);
// 	}
// 	else
// 		welcome(allUser);
		
// }

// void intro(User** allUser) // intro -> welcome
// {
// 	cout << "台大知識王"  << endl; 
// 	cout << "按 1 看故事" << "\n" << "按 2 看願望清單" << "\n" << "按 3 開始遊戲" << "\n"<< "按 4 離開" << "\n";
// 	int status = 0;
// 	cin >> status;
// 	if(status == 1) // story
// 	{
// 		story(allUser);
// 	}
// 	else if(status == 2) // ranking
// 	{
// 		ranking(allUser);
// 	}
// 	else if(status == 3) //start
// 	{
// 		welcome(allUser);
// 	} 
// 	else // exit
// 		return;
// }


// void story(User** allUser)
// {
// 	cout << "某天，你突然發現你深陷在夢中，醒不過來，但你只是一個混到畢業的資管系學生，現在是個什麼程式都不會打的無業遊民。" << "\n" <<
// 	"你以為在夢裡就能有錢有房有車有女友，結果卻發現在夢中也不能為所欲為，每天只能去超商買即期食品...今天一如往常騎著腳踏車，" << "\n" <<
// 	"到超商買微波食品的路上，不只沒有幸運的事情發生，你還為了閃躲走在自行車道的移動式路障，整個人摔進了花叢中，雖然沒有受傷，" << "\n" <<
// 	"但腳踏車的車籃直接撞成一個茶壺的形狀當你心疼的摸著車籃的時候，你發現，原來是地上那個破茶壺，把你的車籃弄成這樣，一氣之下，" << "\n" <<
// 	"用力地踹了一腳，你「噢嗚！」了一聲，卻也聽到破茶壺「噢嗚！」了一聲，轉頭想拔腿就跑的你，發現忘了騎腳踏車心理雖然很害怕，" << "\n" << 
// 	"但是但是更害怕自己什麼都沒有了，所以不能連腳踏車都沒有。正當你一回頭，就被吸進了茶壺的世界，這裡黑漆漆的，只有一台遊戲機，" << "\n" <<
// 	"上面寫著：想想你的大學生活到底經歷了什麼吧！如果能夠破完全部的關卡，我就考慮實現你一個願望~~"<< "\n" <<\
// 	"規則:" << "\n" << "1.每一次的遊戲當中，你將要答7題由簡單到難的題目。每答對一題就會往上一個等級，但相對的。每答錯一題就會往後退一個等級。"<< "\n" <<
// 	"2.每一次的遊戲不能錯超過五題，超過的話會被停權10分鐘。"<< "\n" <<"3.勝利條件: 順利答對等級7的題目。達成之後即可向神燈精靈提出一個願望。" <<"\n" ;
// 	cout << "回到主選單？ (Y/N)";
// 	char answer = 0;
// 	cin >> answer;
// 	if(answer == 'Y')
// 		intro(allUser);
// 	else
// 		story(allUser);
// }

// void ranking(User** allUser)
// {
// 	//cout << "排名待補" << "\n";
// 	cout << "恭喜你們！神燈精靈小傑會按清單順序，考慮實現你們的願望的！" << endl << endl;
// 	int success_num = 0;
// 	User** success_user = new User*[MAX_USER_NUM];
// 	// currently, I define the wish status to be the complete criteria
// 	for(int i = 0 ; i < curr_active_user; i++){
// 		if(allUser[i] -> get_complete_status() == true){
// 			success_user[success_num] = allUser[i]; // storing the pointer
// 			success_num++;
// 		}
// 	}

// 	// starting to sort the pointer
// 	if(success_num >= 2)
// 		sortSuccessUser(success_user, success_num); 

// 	cout << "\許\願者" << "     " << "願望" << "      " << "花費時間"<< "     " << "答題次數" << endl;
// 	if(success_num == 0){
// 		cout << "都還沒有人能夠完成...應該會有人成\功\的吧？" << endl;
// 	}
// 	else{
// 		for(int i = 0; i < success_num; i++)
// 			cout << success_user[i] -> get_username() << "     " << success_user[i] -> get_wish() << "     " << 
// 					success_user[i] -> get_time_used() << "     " << success_user[i] -> get_total_ques_answered() << endl;
		
// 		cout << "恭喜你們！神燈精靈小傑會按清單順序，考慮實現你們的願望的！";
// 	}
// 	cout << "回到主選單？ (Y/N)";
// 	char answer = 0;
// 	cin >> answer;
// 	if(answer == 'Y')
// 		intro(allUser);
// 	else
// 		ranking(allUser);
// }

// void sortSuccessUser(User** success_user, int success_num){
	
// 	User* tmp;
// 	// implement bubble sort
// 	for(int i = success_num - 1; i > 0; i--){
//     	for(int j = 0; j <= i-1; j++){
//         	if( success_user[j]  -> get_total_ques_answered() > success_user[j+1] -> get_total_ques_answered()){
// 			// swap pointer
//            		tmp = success_user[j];
//             	success_user[j] = success_user[j+1];
//             	success_user[j+1] = tmp;
//         }
//     }
// }

// }


// void gameState(User** allUser, int user_ind)
// {
// 	Question ques_obj;
// 	for(int i = 0 ; i < LEVEL ; i++)
// 	{	
		
// 		string player_answer = "E";
// 		srand( time(NULL) );
		
// 		int pick_question = rand() % 24;
// 		if(allUser[user_ind] -> get_current_lv() == 1)
// 		{	
// 			pick_question += 0; 
// 		}
// 		if(allUser[user_ind] -> get_current_lv() == 2)
// 		{
// 			pick_question += 24;
// 		}
// 		if(allUser[user_ind] -> get_current_lv() == 3)
// 		{
// 			pick_question += 48;
// 		}
// 		if(allUser[user_ind] -> get_current_lv() == 4)
// 		{
// 			pick_question += 72;
// 		}
// 		if(allUser[user_ind] -> get_current_lv() == 5)
// 		{
// 			pick_question += 96;
// 		}
// 		if(allUser[user_ind] -> get_current_lv() == 6)
// 		{
// 			pick_question += 120;
// 		} 
// 		if(allUser[user_ind] -> get_current_lv() == 7)
// 		{
// 			pick_question += 144;
// 		}
		
// 		cout << ques_obj.get_ques(pick_question) << endl;
// 		cout << "A. " << ques_obj.get_option(pick_question, 0) << endl; 
// 		cout << "B. " << ques_obj.get_option(pick_question, 1) << endl; 
// 		cout << "C. " << ques_obj.get_option(pick_question, 2) << endl; 
// 		cout << "D. " << ques_obj.get_option(pick_question, 3) << endl;
// 		cout << "玩家答案 : ";
		
// 		time_t question_start_time;
// 		time(&question_start_time);

// 		while(difftime(time(NULL), question_start_time) != RESPONSE_TIME) // the response time is ten seconds
// 		{	 
// 			//cout << difftime(time(NULL), question_start_time) << endl;
		
// 			if(kbhit())
// 			{	
// 				allUser[user_ind] -> add_time_used(difftime(time(NULL), question_start_time));
// 				int temp_answer = getch();
// 				if(temp_answer > 96)
// 				{
// 					temp_answer -= 32; 
// 				}
// 				player_answer = temp_answer;
				
// 				break;
// 			}	
// 		}
		
// 		cout << "您的答案：" << player_answer << endl;

// 		// add time used
// 		if(player_answer == "E")
// 		{
// 			allUser[user_ind] -> add_time_used(10);
// 		} 
		
// 		// check answer
// 		if(ques_obj.check_answer(pick_question, player_answer))
// 		{
// 			cout << "恭喜答對了!" << endl;
// 			allUser[user_ind] -> increment_lv();
// 		}
// 		else
// 		{
// 			cout << "喔不!答錯了..." << endl; 
// 			allUser[user_ind] -> deduct_life();
// 			cout << "生命值 : " << allUser[user_ind] -> get_life() << endl;
// 			allUser[user_ind] -> decrement_lv();
			
// 		}
		
// 		allUser[user_ind] -> add_total_ques_answered();
// 		cout << endl;
// 		cout << endl;
		
// 		if((allUser[user_ind] -> get_current_lv() == 8) || (allUser[user_ind] -> get_life() == 0))
// 		{
// 			break;
// 		}
// 	}
	
// 	if(allUser[user_ind] -> get_current_lv() == 8)
// 	{
// 		allUser[user_ind] -> refill_life();	
// 		setUserWish(allUser, user_ind);
// 		internal_welcome(allUser, user_ind);

// 	}
// 	else if(allUser[user_ind] -> get_life() == 0)
// 	{
// 		int banned_time = time(nullptr);
// 		cout << "生命值已經用完，請等候10分鐘，再重新登入，即可繼續遊玩..." << endl;	
// 		// operations to ban the users
// 		allUser[user_ind] ->set_banned_status(true);
// 		allUser[user_ind] -> set_banned_time(banned_time);
// 		allUser[user_ind] -> refill_life();	
// 		internal_welcome(allUser, user_ind);	
// 	}
// 	else{
// 		allUser[user_ind] -> refill_life();	
// 		internal_welcome(allUser, user_ind);
// 	}
	
// }

// void setUserWish(User** allUser, int user_ind){
// 	string wish;
// 	bool public_secret;
		
// 		cout << "\恭\喜你完成了所有的關卡，獲得了一次向神燈精靈小傑許願的機會" << endl;
// 		cout << "願望可以選擇公開，或是僅讓精靈小傑得知，請在選擇公開情況並輸入願望後"<< endl;
// 		cout << "按送出，願望將在最後依答題情況，呈現排名，即精靈小傑的願望實現順序"<< endl;
		 
// 		cout << "公開 0 / 秘密 1 : ";
// 		cin >> public_secret;
// 		if(public_secret == 1)
// 		{
// 			cout << "願望保密" << endl;
// 		}
// 		else
// 		{
// 			cout << "公開願望" << endl;
// 		} 


// 		allUser[user_ind] -> set_wish_status(public_secret);
// 		cout << "你的願望 : "; 
// 		cin >> wish;
// 		cout << endl;
// 		allUser[user_ind] -> set_wish(wish);
// 		allUser[user_ind] -> set_complete_status(true);
// }


