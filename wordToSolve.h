#ifndef WORDTOSOLVE_H
#define WORDTOSOLVE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class wordToSolve {

	public:
		wordToSolve(){
			word = "";
		}

        wordToSolve(string sWord);
        void solve(char letter);
        int getAttempts(){return attempts;}
        void printUnderscores();
        void printGuesses();
        string getWord() {return word;}
        vector<char> getUnderscore() {return underscore;}
        vector<char> getGuesses() {return guesses;}
        bool Solved();
        void printHangman(int o);
        wordToSolve &operator=(wordToSolve &otherWord);


	private:
		string word;
		vector<char> underscore;
		vector<char> guesses;
		int attempts = 0;



};

#endif
