#ifndef USER_STATE_HPP
#define USER_STATE_HPP

#include <string>
#include<iostream>
#include<fstream>
#include "../hpp/Question.hpp"

// when moving <conio.h> to the .cpp file, the multiple definition error disappear. WHy?
extern const int MAX_ACC_PASS_LEN; // the maximum account and password length a person can set
extern int curr_active_user; // record the number of active user 
extern const int MAX_USER_NUM;
extern const int NUM_OPTION;
extern const int LEVEL;
extern const int RESPONSE_TIME;
extern const int USER_BANNED_TIME;

class User{
	friend void fileInput(std::string dir, User** allUser);
	friend int findUser(std::string user, User** allUser);
	friend void createUser(User** allUser);
	friend void Login(User** allUser);
	private:
		float time_used; // probably will convert to second
		int total_ques_answered; // the total questions answered
		int life; // five life at the start of the game. If it is deducted to zero, he/ she will wait for 10 mins(?
		int current_lv; 
		std::string username;
		std::string password;
		bool complete_status; // state whether the user completed the game 
		bool account_status; // check if the account is set up properly
		std::string wish; // the wish that user makes after clearing the game
		bool wish_status; // whether the wish is private
		bool banned_status; 
		int banned_time;
	public:
		User(std::string name, std::string pass);
		User(std::string username, std::string password, bool complete_status, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, std::string wish, bool wish_status, bool banned_status, int banned_time);
		void add_time_used(int time_in_question);
		void add_total_ques_answered(); // increment by 1 by default
		void increment_lv(); // one question correct, then the user can increment one level 
		void decrement_lv(); // one question wrong, then the user will decrement one level
		void deduct_life(); // one question wrong, then then user will decrement one life
		void set_banned_time(int time_in_sec){this -> banned_time = time_in_sec; } // setter // record the time that the user start to be banned!
		void set_banned_status(bool status){this -> banned_status = status; } // setter // when recording the banned time, set the banned_status to be true;
		void set_complete_status(bool comp_status){this -> complete_status = comp_status;} // setter
		void set_wish(std::string add_wish){this -> wish = add_wish;} // set the wishes of the user if he/she complete the game
		void set_wish_status(bool wishStatus){this -> wish_status = wishStatus;}
		void refill_life(); // life refill to 5 after a game 
		
		int get_time_used(){return this -> time_used;} // getter
		int get_total_ques_answered(){return this -> total_ques_answered;} // getter 
		std::string get_username(){return this -> username;} // getter
		std::string get_password(){return this ->password;} // getter
		bool get_complete_status(){return this -> complete_status;} // getter
		int get_life(){return this -> life;} // getter
		int get_account_status(){return this -> account_status;} // getter
		int get_current_lv(){return this->current_lv;} // getter // not 
		std::string get_wish(){return this -> wish;}
		bool get_wish_status(){return this -> wish_status;}
		bool get_banned_status(){return this-> banned_status;}
		int get_banned_time(){return this -> banned_time;}
		void print(); // to check if the member information is constructed correctly
};

void fileInput(std::string dir, User** allUser);
void fileOutput(std::string dir, User** allUser);
int findUser(std::string user, User** allUser);
void createUser(User** allUser); // put all User to global variable? 
void Login(User** allUser);
void welcome(User** allUser);
void internal_welcome(User** allUser, int user_ind);
void player_info(User** allUser, int user_ind);
void intro(User** allUser);
void story(User** allUser);
void ranking(User** allUser);
void sortSuccessUser(User** success_user, int success_num);
void gameState(User** allUser, int user_ind);
void setUserWish(User** allUser, int user_ind);

#endif