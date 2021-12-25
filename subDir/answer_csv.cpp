#include<iostream>
#include<fstream>
#include<vector>
#include<sstream> // istringstream
#include<string>
// read csv file ?? 
// http://cckuo0925.blogspot.com/2016/08/c-csv.html 
using namespace std;

int main(){
	vector<vector<string>> option_vec;
	//int option_cnt = 0;
	int index_vector = 0;
	fstream ansFile("../csv_ansi_new.txt");
	
	string line;
	if(ansFile){
			// changing the line (type: string) to input stream	
		string option_line;
		while (getline(ansFile, option_line,'\n')) {
		 	istringstream templine(option_line);
			option_vec.push_back(vector<string>()); // pushback an empty string
			index_vector += 1;
			string option;
			while(getline(templine, option, ',')){
				option_vec[index_vector - 1].push_back(option);
				cout << index_vector << endl; 
				cout << option << endl;
			}
		}	
	}	
	ansFile.close();
	//cout << option_cnt; 
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 4; j++)
			cout << option_vec[i][j] << " ";
		cout << endl;	
	}
	
	cout <<option_vec.size();
	
	return 0;
} 
