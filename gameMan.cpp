#include "gameMan.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class FileNotFound {};

void gameMan::getWords(int diff){
	ifstream inputFile;
	string word;

    try{
        inputFile.open("wordBank.txt");

        if(!inputFile.is_open()) {
            throw FileNotFound();
        }

        while (getline(inputFile, word)) {
            switch (diff) {
                case 1:
                    if (word.length() <= 5) {
                            wordArr.push_back(word);
                        }
                    break;
                case 2:
                    if (word.length() <= 8 && word.length() > 5) {
                            wordArr.push_back(word);
                        }
                    break;
                case 3:
                    if (word.length() > 8) {
                            wordArr.push_back(word);
                    }
                    break;
                default:
                    break;
            }
        }
    inputFile.close();
    }

    catch (const FileNotFound& e){
        cout << "File not found!" << endl;
    }

}

bool gameMan::activeGame() {
	ifstream inputFile;

	inputFile.open("save.txt");

	if (inputFile.eof()) {
		return false;
	} else {
		return true;
	}

	inputFile.close();
}

void gameMan::saveFile(){
	ofstream outputFile;

	outputFile.open("save.txt");

	outputFile << gWord.getWord() << endl << gWord.getAttempts() << endl;

	for (int i = 0; i < gWord.getGuesses().size(); i++) {
        outputFile << gWord.getGuesses()[i] << " ";
	}

	outputFile << endl;

	for (int i = 0; i < gWord.getUnderscore().size(); i++) {
        outputFile << gWord.getUnderscore()[i] << " ";

	}

	outputFile.close();

}

string gameMan::pickWord() {
    srand(time(NULL));

    return wordArr.at(rand() % wordArr.size());
}

void gameMan::clearArr() {
    wordArr.clear();
    return;
}

void gameMan::printMenu(int o){

    switch (o) {
        case 0:
            cout << "       *Hangman Game*       " << endl << endl;
            cout << "          RULES:            " << endl;
            cout << "   You get six attempts to  " << endl;
            cout << "       guess the word.      " << endl << endl;
            cout << "----------------------------"<< endl;
            cout << "-       1. New Game        -" <<endl;
            cout << "-       2. Load Game       -" << endl;
            cout << "-       3. Exit            -" <<endl;
            cout << "----------------------------" << endl;
            cout << "Your option: ";
            break;
        case 1:
            cout.width(28);
            cout.fill('*');
            cout << "" << endl;
            cout << "*  Select your Difficulty  *" << endl;
            cout << "*  1. Easy (<= 5 letters)  *" << endl;
            cout << "*  2. Medium (<= 8 letters)*" << endl;
            cout << "*  3. Hard (> 8 letters)   *" << endl;
            cout.width(28);
            cout.fill('*');
            cout << "" << endl;
            cout << "Your option: ";
            break;
        case 2:
            cout.width(28);
            cout.fill('*');
            cout << endl << "Enter '$' at any time to save and exit." << endl;
            cout << "Guesses: ";
            gWord.printGuesses();
            cout << endl << endl;
            gWord.printUnderscores();
            cout << "Your guess: ";

    }

}
