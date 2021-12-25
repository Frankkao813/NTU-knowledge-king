#include<iostream>
#include<vector>
#include<string> 
#include<fstream>
#include<sstream> // istringstream
using namespace std;

const int NUM_OPTION = 4;
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
		string get_ans(int ind_ans) {return answer_vec[ind_ans];} // to obtain the answer to the question
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


	cout << option_vec.size() << endl;
	cout << ques_vec.size() << endl;
	cout << answer_vec.size() << endl;

}


// to check if the user inputs the correct answer
bool Question::check_answer(int i, string userInput){
	if(answer_vec[i] == userInput)
		return true;
	else
		return false;
}

int main(){
	Question ques_obj;
	// The reason why this place don't use char is becuase some vicious users might type two characters at once
	// to break the program
	string userInput; 
	bool correctness = false;
	
	for(int i = 0; i < 168; i++){
		//to do:  the program to pick the question randomly...probably a function can help
		
		string question_title = ques_obj.get_ques(i);
		cout << question_title;
		cout << endl;
		for(int j = 0;  j < NUM_OPTION; j++)
			cout << "["<<  static_cast<char>(65 + j) <<  "] "  << ques_obj.get_option(i, j) << " ";
	cout << endl;
		cout << ques_obj.get_ans(i);
	cout << endl;
	cout << endl;
	
//		cout << "Please input your answer: ";
//		cin >> userInput;
//		correctness = ques_obj.check_answer(i, userInput);
//		if(correctness == true)
//			cout << "Congratulations!";
//		else
//			cout << "Oops! You get the wrong answer.";
//		
//		cout << endl;
//		cout << endl;
	} 
	
	//cout << "hello!" << endl;
	return 0;
}
