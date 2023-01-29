#include "../hpp/User_State.hpp"
#include <conio.h>

// https://www.microchip.com/forums/m802642.aspx
const int MAX_ACC_PASS_LEN = 11; // the maximum account and password length a person can set
int curr_active_user = 0; // record the number of active user 
const int MAX_USER_NUM = 100;
const int NUM_OPTION = 4;
const int LEVEL = 7;
const int RESPONSE_TIME = 10;
const int USER_BANNED_TIME = 300;

User::User(std::string username, std::string password){
	curr_active_user++;
	this -> time_used = 0;
	this -> total_ques_answered = 0;
	this -> life = 5;
	this -> username = username;
	this -> password = password; 
	this -> complete_status = 0;
	this -> account_status = 1; // status normal 
	this -> current_lv = 1;
	this -> wish = "NA";
	this -> wish_status = 0;
	this -> banned_status = 0;
	this -> banned_time = 0;
	//this -> login_status = 1; // the person can log into the account;
}
User::User(std::string username, std::string password, bool complete_status, int total_ques_answered, int time_used, int life, int current_lv, bool account_status, std::string wish, bool wish_status, bool banned_status, int banned_time){
	curr_active_user++;
	this -> username = username;
	this -> password = password; 
	this -> complete_status = complete_status; 
	this -> total_ques_answered = total_ques_answered;
	this -> time_used = time_used;
	this -> life = life;
	this -> current_lv = current_lv;
	this -> account_status = account_status;
	this -> wish = wish;
	this -> wish_status = wish_status; 
	this -> banned_status = banned_status;
	this -> banned_time = banned_time; 
	
}

void User::deduct_life(){
	this -> life -= 1;
	// check if the life is greater than 0
	// if(this -> life >= 0)
	// 	return true;
	// else
	// 	return false;
		
}
void User::refill_life(){
	this -> life = 5;
}

void User::add_time_used(int time_in_question){
	this -> time_used += time_in_question;
}

void User::increment_lv(){
	this -> current_lv += 1;
	// if(this -> current_lv == 8){
	// 	return true;
	// }
	// else
	// 	return false;
	
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
	std::cout << "帳號名稱 : " << this -> username << std::endl; 
	std::cout << "帳號密碼 : " << this -> password << std::endl;
	std::cout << "是否已完全破關 : ";
	if(this -> complete_status)
		std::cout << "是" << std::endl;
	else
		std::cout << "否" << std::endl;
	std::cout << "花費時間 : " << this -> time_used << std::endl;
	std::cout << "答題次數 : " << this -> total_ques_answered << std::endl;
	std::cout << "生命值 : " << this -> life << std::endl; 
	std::cout << "現在關卡 : " << this -> current_lv << std::endl; 
	std::cout << "帳號狀態 : " << this -> account_status << std::endl;
	//cout << "login status: " << this -> login_status << endl;
	std::cout << "願望 : " << this -> wish << std::endl;
	std::cout << "願望狀態 : " << this -> wish_status << std::endl; 
	std::cout << "是否可以遊玩 : ";
	if(this -> banned_status)
		std::cout << "不行" << std::endl;
	else
		std::cout << "可以" << std::endl; 
	std::cout << "剩餘禁止時間(秒) : ";
	if(this -> banned_time == 0)
		std::cout << 0 << std::endl;
	else{

		if((time(NULL) - this -> banned_time) <= USER_BANNED_TIME)
			std::cout << (time(NULL) - this -> banned_time) << std::endl;
		else{
			//this -> banned_time = 0; // reset to zero
			std::cout << 0 << std::endl;
		}
			
	}
		
	std::cout << "................................" << std::endl;
	return;
}



void fileInput(std::string dir, User** allUser){
	// string username, string password, int trial_used, int time_used, int life, bool account_status
	curr_active_user = 0; // reset
	std::ifstream userFile;
	userFile.open(dir);
	if(!userFile)
		std::cout << "沒有任何紀錄";
	else{
		std::string tmp_username;
		std::string tmp_password;
		bool tmp_complete_status;
		int tmp_total_ques_answered;
		int tmp_time_used;
		int tmp_life;
		int tmp_current_lv;
		bool tmp_account_status;
		std::string tmp_wish;
		bool tmp_wish_status;
		bool tmp_banned_status;
		int tmp_banned_time;
		
		while(userFile >> tmp_username >>  tmp_password >> tmp_complete_status >> tmp_total_ques_answered >> tmp_time_used >> 
		tmp_life >> tmp_current_lv >> tmp_account_status >> tmp_wish >> tmp_wish_status >> tmp_banned_status >> tmp_banned_time){
			//curr_active_user += 1;
			allUser[curr_active_user - 1] = new User(tmp_username, tmp_password, tmp_complete_status,
											 tmp_total_ques_answered, tmp_time_used, tmp_life, tmp_current_lv,  
											 tmp_account_status, tmp_wish, tmp_wish_status, tmp_banned_status,
											  tmp_banned_time);
		}
			
	}
	userFile.close();
}

void fileOutput(std::string dir, User** allUser){
	
	std::ofstream userFile;
	userFile.open(dir);
	
	if(!userFile)
		std::cout << "沒有任何紀錄";
	else{
		for(int i = 0; i < curr_active_user; i++)
			userFile << allUser[i] -> get_username() << " " << allUser[i] -> get_password() << " " 
			<< allUser[i] -> get_complete_status() << " "<< allUser[i] -> get_total_ques_answered() << " " 
			<< allUser[i] -> get_time_used() << " " <<allUser[i] -> get_life() <<" "
			<< allUser[i]  -> get_current_lv() << " "  << allUser[i] -> get_account_status() << " " << allUser[i] -> get_wish() << " " << 
			allUser[i] -> get_wish_status() <<  " " << allUser[i] -> get_banned_status() << " " << 
			allUser[i] -> get_banned_time() << "\n"; 
			
			//userFile << "\n"; 
	}
	
	userFile.close();
		
}

int findUser(std::string user, User** allUser){
	// string comparison
	for(int i = 0; i < curr_active_user; i++){
		if(allUser[i] -> username == user)
			return i;
	}
	// cout << "User not found!";
	return -1; // not found any user having the user and password 
		
}

void createUser(User** allUser){ // put all User to global variable? 
	std::string username_store;
	std::string password_store;
	std::cout << "請輸入帳號名稱來創建帳號(英文、數字及符號以十個字為上限，中文字五個為上限) : ";
	std::cin >> username_store;
	std::cout << "請輸入帳號密碼來創建帳號(英文、數字及符號以十個字為上限，中文字五個為上限) : ";
	std::cin >> password_store;
	std::cout << std::endl;
	
	//cout << username_store.size();
	//cout << password_store.size();
	
	int check_user = findUser(username_store, allUser);
	char continue_status = 0;
	if(check_user == -1){
		if(username_store.size() > MAX_ACC_PASS_LEN || password_store.size() > MAX_ACC_PASS_LEN){
			std::cout << "帳號名稱或密碼不符合規定(英文、數字及符號以十個字為上限，中文字五個為上限)" << std::endl;
			std::cout << "您要再試一次嗎？ (Y/N)";
			std::cin >> continue_status;
			if(continue_status == 'Y')
				createUser(allUser); // will this line cause problem?
			else
				welcome(allUser);
		}
		else{
			std::cout << "歡迎加入我們，新夥伴！" << "\n";	
			allUser[curr_active_user - 1] = new User(username_store, password_store);
//			for(int i = 0; i < curr_active_user; i++)
//		 		allUser[i] -> print();
			internal_welcome(allUser, (curr_active_user - 1));
			//gameState(allUser, (curr_active_user - 1));
			
		}
	}
	else{
		//while(true){
		std::cout << "這個名字已經被註冊過了" << "\n" << "請按 1 創建別的帳號" <<"\n" <<"請按 2 登入遊戲" << "\n";
		int answer = 0;
		std::cin >> answer;
		if(answer == 1)
			createUser(allUser);
		else
		 	Login(allUser);
	}
	//}
}

void Login(User** allUser){
	std::string account_store;
	std::string password_store;
	std::cout << "請輸入您的帳號名稱 : ";
	std::cin >> account_store;
	//cout << "\n";
	
	std::cout << "請輸入您的帳號密碼 : ";
	std::cin >> password_store;
	
	int user_ind = -1;
	for(int i = 0; i < curr_active_user; i++){
		if(allUser[i] -> username == account_store && allUser[i] -> password == password_store) 
			user_ind = i;
	} 
	
	if(user_ind != -1){

			std::cout << "歡迎！" << std::endl;
			//allUser[user_ind] -> banned_status = false;
			internal_welcome(allUser, user_ind);
		// }	
	}
	else{
		// if the function doesn;t return, it means that the user might not registered or typed the wrong account/password
		char continue_status = 0;
		std::cout << "帳號名稱或密碼不正確(英文、數字及符號以十個字為上限，中文字五個為上限)。您要再試一次嗎？ (Y/N)";
		std::cin >> continue_status;
		
		if(continue_status == 'Y')
			Login(allUser);
		else
			welcome(allUser);	
	}

}

void internal_welcome(User** allUser, int user_ind){
	std::cout << "歡迎進入遊戲！我們的冒險者 : " << allUser[user_ind] -> get_username() << "！" << std::endl;
	std::cout << "請選擇 : " << std::endl;
	std::cout << "[1] 開始挑戰   [2] 登出  [3] 查看帳號資訊" << std::endl;
	int flag;
	std::cin >> flag;
	if(flag == 1){ //char flag != int 1 !!
		// write all the situation where a person can't play the game here
		if(allUser[user_ind] -> get_banned_status() == true && (time(nullptr) - allUser[user_ind] -> get_banned_time() <= USER_BANNED_TIME) ){
			std::cout << "您現在不能進入遊戲，因為目前帳號已被暫時凍結..." << std::endl;
			std::cout << "回到登入介面" << std::endl;
			internal_welcome(allUser, user_ind);
		}
		else if(allUser[user_ind] -> get_complete_status() == true){
			std::cout << "一個人只有一次許願的機會，不可以貪心..." << std::endl;
			std::cout << "回到登入介面";
			internal_welcome(allUser, user_ind);
		}
		else{
			allUser[user_ind] -> set_banned_status(false); 
			gameState(allUser, user_ind);
		}
	} 
	else if(flag == 2) 
		welcome(allUser);
	else if(flag == 3)
		player_info(allUser, user_ind);
	else
		internal_welcome(allUser, user_ind);
	
}

void player_info(User** allUser, int user_ind){
	allUser[user_ind] -> print();
	char flag;
	std::cout << "回到登入介面？ (Y/N)";
	std::cin >> flag;
	if(flag == 'Y')
		internal_welcome(allUser, user_ind);
	else
		player_info(allUser, user_ind);
}

void welcome(User** allUser)
{
	std::cout << "準備好開始挑戰了嗎？" << "\n" << "按 1 創建帳號" << "\n" << "按 2 登入帳號"<< "\n" << "按 3 回到主選單" << "\n";
	int status = 0;
	std::cin >> status;
	if(status == 1)
	{
		createUser(allUser);
	}
	else if(status == 2)
	{
		Login(allUser);
	}
	else if(status == 3)
	{
		//welcome(allUser);
		intro(allUser);
	}
	else
		welcome(allUser);
		
}

void intro(User** allUser) // intro -> welcome
{
	std::cout << "台大知識王"  << std::endl; 
	std::cout << "按 1 看故事" << "\n" << "按 2 看願望清單" << "\n" << "按 3 開始遊戲" << "\n"<< "按 4 離開" << "\n";
	int status = 0;
	std::cin >> status;
	if(status == 1) // story
	{
		story(allUser);
	}
	else if(status == 2) // ranking
	{
		ranking(allUser);
	}
	else if(status == 3) //start
	{
		welcome(allUser);
	} 
	else // exit
		return;
}


void story(User** allUser)
{
	std::cout << "某天，你突然發現你深陷在夢中，醒不過來，但你只是一個混到畢業的資管系學生，現在是個什麼程式都不會打的無業遊民。" << "\n" <<
	"你以為在夢裡就能有錢有房有車有女友，結果卻發現在夢中也不能為所欲為，每天只能去超商買即期食品...今天一如往常騎著腳踏車，" << "\n" <<
	"到超商買微波食品的路上，不只沒有幸運的事情發生，你還為了閃躲走在自行車道的移動式路障，整個人摔進了花叢中，雖然沒有受傷，" << "\n" <<
	"但腳踏車的車籃直接撞成一個茶壺的形狀當你心疼的摸著車籃的時候，你發現，原來是地上那個破茶壺，把你的車籃弄成這樣，一氣之下，" << "\n" <<
	"用力地踹了一腳，你「噢嗚！」了一聲，卻也聽到破茶壺「噢嗚！」了一聲，轉頭想拔腿就跑的你，發現忘了騎腳踏車心理雖然很害怕，" << "\n" << 
	"但是但是更害怕自己什麼都沒有了，所以不能連腳踏車都沒有。正當你一回頭，就被吸進了茶壺的世界，這裡黑漆漆的，只有一台遊戲機，" << "\n" <<
	"上面寫著：想想你的大學生活到底經歷了什麼吧！如果能夠破完全部的關卡，我就考慮實現你一個願望~~"<< "\n" <<\
	"規則:" << "\n" << "1.每一次的遊戲當中，你將要答7題由簡單到難的題目。每答對一題就會往上一個等級，但相對的。每答錯一題就會往後退一個等級。"<< "\n" <<
	"2.每一次的遊戲不能錯超過五題，超過的話會被停權10分鐘。"<< "\n" <<"3.勝利條件: 順利答對等級7的題目。達成之後即可向神燈精靈提出一個願望。" <<"\n" ;
	std::cout << "回到主選單？ (Y/N)";
	char answer = 0;
	std::cin >> answer;
	if(answer == 'Y')
		intro(allUser);
	else
		story(allUser);
}

void ranking(User** allUser)
{
	//cout << "排名待補" << "\n";
	std::cout << "恭喜你們！神燈精靈小傑會按清單順序，考慮實現你們的願望的！" << std::endl << std::endl;
	int success_num = 0;
	User** success_user = new User*[MAX_USER_NUM];
	// currently, I define the wish status to be the complete criteria
	for(int i = 0 ; i < curr_active_user; i++){
		if(allUser[i] -> get_complete_status() == true){
			success_user[success_num] = allUser[i]; // storing the pointer
			success_num++;
		}
	}

	// starting to sort the pointer
	if(success_num >= 2)
		sortSuccessUser(success_user, success_num); 

	std::cout << "許願者" << "     " << "願望" << "      " << "花費時間"<< "     " << "答題次數" << std::endl;
	if(success_num == 0){
		std::cout << "都還沒有人能夠完成...應該會有人成功的吧？" << std::endl;
	}
	else{
		for(int i = 0; i < success_num; i++)
			std::cout << success_user[i] -> get_username() << "     " << success_user[i] -> get_wish() << "     " << 
					success_user[i] -> get_time_used() << "     " << success_user[i] -> get_total_ques_answered() << std::endl;
		
		std::cout << "恭喜你們！神燈精靈小傑會按清單順序，考慮實現你們的願望的！";
	}
	std::cout << "回到主選單？ (Y/N)";
	char answer = 0;
	std::cin >> answer;
	if(answer == 'Y')
		intro(allUser);
	else
		ranking(allUser);
}

void sortSuccessUser(User** success_user, int success_num){
	
	User* tmp;
	// implement bubble sort
	for(int i = success_num - 1; i > 0; i--){
    	for(int j = 0; j <= i-1; j++){
        	if( success_user[j]  -> get_total_ques_answered() > success_user[j+1] -> get_total_ques_answered()){
			// swap pointer
           		tmp = success_user[j];
            	success_user[j] = success_user[j+1];
            	success_user[j+1] = tmp;
        }
    }
}

}


void gameState(User** allUser, int user_ind)
{
	Question ques_obj;
	for(int i = 0 ; i < LEVEL ; i++)
	{	
		
		std::string player_answer = "E";
		srand( time(NULL) );
		
		int pick_question = rand() % 24;
		if(allUser[user_ind] -> get_current_lv() == 1)
		{	
			pick_question += 0; 
		}
		if(allUser[user_ind] -> get_current_lv() == 2)
		{
			pick_question += 24;
		}
		if(allUser[user_ind] -> get_current_lv() == 3)
		{
			pick_question += 48;
		}
		if(allUser[user_ind] -> get_current_lv() == 4)
		{
			pick_question += 72;
		}
		if(allUser[user_ind] -> get_current_lv() == 5)
		{
			pick_question += 96;
		}
		if(allUser[user_ind] -> get_current_lv() == 6)
		{
			pick_question += 120;
		} 
		if(allUser[user_ind] -> get_current_lv() == 7)
		{
			pick_question += 144;
		}
		
		std::cout << ques_obj.get_ques(pick_question) << std::endl;
		std::cout << "A. " << ques_obj.get_option(pick_question, 0) << std::endl; 
		std::cout << "B. " << ques_obj.get_option(pick_question, 1) << std::endl; 
		std::cout << "C. " << ques_obj.get_option(pick_question, 2) << std::endl; 
		std::cout << "D. " << ques_obj.get_option(pick_question, 3) << std::endl;
		std::cout << "玩家答案 : ";
		
		time_t question_start_time;
		time(&question_start_time);

		while(difftime(time(NULL), question_start_time) != RESPONSE_TIME) // the response time is ten seconds
		{	 
			//cout << difftime(time(NULL), question_start_time) << endl;
		
			if(kbhit())
			{	
				allUser[user_ind] -> add_time_used(difftime(time(NULL), question_start_time));
				int temp_answer = getch();
				if(temp_answer > 96)
				{
					temp_answer -= 32; 
				}
				player_answer = temp_answer;
				
				break;
			}	
		}
		
		std::cout << "您的答案：" << player_answer << std::endl;

		// add time used
		if(player_answer == "E")
		{
			allUser[user_ind] -> add_time_used(10);
		} 
		
		// check answer
		if(ques_obj.check_answer(pick_question, player_answer))
		{
			std::cout << "恭喜答對了!" << std::endl;
			allUser[user_ind] -> increment_lv();
		}
		else
		{
			std::cout << "喔不!答錯了..." << std::endl; 
			allUser[user_ind] -> deduct_life();
			std::cout << "生命值 : " << allUser[user_ind] -> get_life() << std::endl;
			allUser[user_ind] -> decrement_lv();
			
		}
		
		allUser[user_ind] -> add_total_ques_answered();
		std::cout << std::endl;
		std::cout << std::endl;
		
		if((allUser[user_ind] -> get_current_lv() == 8) || (allUser[user_ind] -> get_life() == 0))
		{
			break;
		}
	}
	
	if(allUser[user_ind] -> get_current_lv() == 8)
	{
		allUser[user_ind] -> refill_life();	
		setUserWish(allUser, user_ind);
		internal_welcome(allUser, user_ind);

	}
	else if(allUser[user_ind] -> get_life() == 0)
	{
		int banned_time = time(nullptr);
		std::cout << "生命值已經用完，請等候10分鐘，再重新登入，即可繼續遊玩..." << std::endl;	
		// operations to ban the users
		allUser[user_ind] ->set_banned_status(true);
		allUser[user_ind] -> set_banned_time(banned_time);
		allUser[user_ind] -> refill_life();	
		internal_welcome(allUser, user_ind);	
	}
	else{
		allUser[user_ind] -> refill_life();	
		internal_welcome(allUser, user_ind);
	}
	
}

void setUserWish(User** allUser, int user_ind){
	std::string wish;
	bool public_secret;
		
		std::cout << "恭喜你完成了所有的關卡，獲得了一次向神燈精靈小傑許願的機會" << std::endl;
		std::cout << "願望可以選擇公開，或是僅讓精靈小傑得知，請在選擇公開情況並輸入願望後"<< std::endl;
		std::cout << "按送出，願望將在最後依答題情況，呈現排名，即精靈小傑的願望實現順序"<< std::endl;
		 
		std::cout << "公開 0 / 秘密 1 : ";
		std::cin >> public_secret;
		if(public_secret == 1)
		{
			std::cout << "願望保密" << std::endl;
		}
		else
		{
			std::cout << "公開願望" << std::endl;
		} 


		allUser[user_ind] -> set_wish_status(public_secret);
		std::cout << "你的願望 : "; 
		std::cin >> wish;
		std::cout << std::endl;
		allUser[user_ind] -> set_wish(wish);
		allUser[user_ind] -> set_complete_status(true);
}


