#include<iostream>
//#include<locale>
#include<fstream>
#include<string>
#include<vector>
//#pragma execution_character_set( "utf-8" )
// http://www.ziyou.math.ncu.edu.tw/~ziyou/c++/practice/code/pbird.html
// https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/532152/
using namespace std;
int main() {
	//SetConsoleOutputCP( 65001 );
	int	totalQues = 0;
	std::ifstream inFile("../question_ansi.txt");
	vector<string> str_vec;
	
	if (inFile) {
		std::string wstr;
		std::ofstream f("../output.txt");
		while (std::getline(inFile, wstr)) {
			totalQues += 1;
			//std::cout << wstr << std::endl;
			f << wstr << std::endl;
			str_vec.push_back(wstr);
		}
		f.close();
	}

	inFile.close();
	string endMsg = "§A¦n´Î!";
	str_vec.push_back(endMsg);
	for(int i = 0; i < totalQues + 1; i++)
		cout << str_vec[i] << endl;
	
	//cout << "çŽ‹æ›‰æ˜Ž";
	return 0;
}
