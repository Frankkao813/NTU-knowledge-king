#include "../hpp/Question.hpp"
#include<fstream>
#include<sstream>
Question::Question(){

	// file input - question file(in utf-8 format)
	// note that in visual studio code, the default encoding is utf-8
	std::ifstream quesFile("../game_file/question.txt");
	std::string quesStr;
	if(quesFile){
		while(std::getline(quesFile, quesStr)){
			//cout << quesStr << endl;
			ques_vec.push_back(quesStr);
		}	
	}
	quesFile.close();
	
	// option
	
	std::fstream optFile("../game_file/options.txt");
	std::string line;
	int index_vector = 0;
	if(optFile){
			// changing the line (type: string) to input stream	
		std::string option_line;
		while (std::getline(optFile, option_line,'\n')) {
		 	std::istringstream templine(option_line);
			option_vec.push_back(std::vector<std::string>()); // pushback an empty string vector
			index_vector += 1;
			std::string option;
			while(std::getline(templine, option, ',')){
				option_vec[index_vector - 1].push_back(option);
				//cout << index_vector << endl; 
				//cout << option << endl;
			}
		}	
	}	
	optFile.close();

	
	
	// answer

	std::fstream answerFile("../game_file/answer.txt");
	std::string answer_char;
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
bool Question::check_answer(int i, std::string userInput){
	if(answer_vec[i] == userInput)
		return true;
	else
		return false;
}
// 