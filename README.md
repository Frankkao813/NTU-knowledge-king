## NTU knowledge king

### Introduction
This is the final project of 110-1 programming design course offered by the department of imformation management. Students are asked to form groups of five to six to use C++ to make something. 

The goal of our group project is to create a multi-page, multiple choice question answering game. The work is divided into two parts, the game logic and pages and graphic user interface. I belonged to the game logic and page design subteam, and what I had done was to design classes to store the game information, and decide the transitions between page to page. 

### file structure
This repository can be classifed into three sections. Each section is wrapped a folder:
1. game file: This folder contain files to be inputted/outputed: `answer.txt`, `options.txt`, `question.txt`, `user_info.txt`. The file encoding is all in utf-8.
2. supplementary material: 
    a. class說明書: explains how the class was designed
    b. 問題集: the full question, option, and answer of the game.
3. cpp/hpp file: `main.cpp` is the entry point, and cpp and hpp files are separated into two folders.

Note that this repository only contains the CLI version of the game, the full GUI game is in another repository.

### compilation
In the cpp folder:
`g++ User_State.cpp Question.cpp main.cpp -o NTU_game`
