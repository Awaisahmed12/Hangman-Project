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
        wordToSolve(string sWord, int sAttempts, vector<char> sUnderscore, vector<char> sGuesses);
        bool solve(string letter);
        int getAttempts(){return attempts;}
        void printUnderscores();
        void printGuesses();
        string getWord() {return word;}
        vector<char> getUnderscore() {return underscore;}
        vector<char> getGuesses() {return guesses;}
        void clearWordGuesses();
        bool Solved();
        void printHangman(int o);
        wordToSolve &operator=(wordToSolve &otherWord);


	private:
		string word;
		vector<char> underscore;
		vector<string> wordGuesses;
		vector<char> guesses;
		int attempts = 0;



};

#endif
