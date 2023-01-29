#ifndef Question_HPP
#define Question_HPP

#include <vector>
#include <string>

class Question{
	//friend class check_answer;
	private:
		int num_question;
		std::vector<std::string> ques_vec; // a single dimensional vector storing the questions
		std::vector<std::vector<std::string>> option_vec; // a two dimensional vector storing options (4 options)
		std::vector<std::string> answer_vec; // a single dimensional vector storing the answer of the answer to the question;
	public:
		Question(); // constructor, questions, options, and answers will also be written into it
		std::string get_ques(int ind_ques){return ques_vec[ind_ques];} // get the desired question
		std::string get_option(int row, int col){return option_vec[row][col];} // get the desired option
		// int get_ans(int ind_ans); // to obtain the answer to the question
		bool check_answer(int ind_ques, std::string userInput); // to check if the answer is correct
};

# endif