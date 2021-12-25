#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	string username[2] = {"Petty", "Daisy"};
	int time_used[2] = {1, 2};
	string wishes[2] = {"經援100", "橘子好吃"};
	
	std::ifstream inFile("../output_2.txt");
	
	
	if(inFile){
		std::ofstream f("../output_3.txt");
		string tmp_user;
		int tmp_time;
		string tmp_wishes;
		while(inFile >>tmp_user >> tmp_time >> tmp_wishes)
			f << tmp_user << " " << tmp_time << " " << tmp_wishes << endl;
		
		f.close();
	}
	inFile.close();
	
	return 0;
}
