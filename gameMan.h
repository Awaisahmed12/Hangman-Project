#ifndef GAMEMAN_H
#define GAMEMAN_H
#include <iostream>
#include <string>
#include <fstream>
#include "wordToSolve.h"
#include <vector>

using namespace std;



class gameMan{
	public:
		gameMan() {difficulty = 1;}
		gameMan(int h){difficulty = h;}
		void getWords(int diff);
		void saveFile(bool isSolved);
		bool loadFile();
		void clearArr();
		bool activeGame();
		string pickWord();
		vector<string> wordArr;
		wordToSolve gWord;
		void printMenu(int o);

	private:
		int difficulty;




};


#endif
