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

bool gameMan::loadFile() {
    string lWord;
    vector<char> sUnderscore;
    vector<char> sGuesses;
    int lAttempts;
    char elem;


    if (activeGame()) {
        ifstream inputFile;
        inputFile.open("save.txt");

        inputFile >> lWord;
        inputFile >> lAttempts;

        while (inputFile >> elem) {

            if (elem == '|') {break;}
            sGuesses.push_back(elem);
        }

        while (inputFile >> elem) {
            sUnderscore.push_back(elem);
        }

        wordToSolve loadedSave(lWord, lAttempts, sUnderscore, sGuesses);
        gWord = loadedSave;

        return true;

        inputFile.close();
    } else {
        cout << "No save data found!" << endl;
        cout << "Defaulting to new game..." << endl;
        return false;
    }



}

bool gameMan::activeGame() {
	ifstream inputFile;
	bool result;

	inputFile.open("save.txt");

    result = inputFile.eof();
	inputFile.close();

	return result;
}

void gameMan::saveFile(bool isSolved){
	ofstream outputFile;



	if (isSolved) {
            outputFile.open("save.txt", ofstream::out | ofstream::trunc);
            outputFile.close();
            return;
	}

	outputFile.open("save.txt");

	outputFile << gWord.getWord() << endl << gWord.getAttempts() << endl;

	for (int i = 0; i < gWord.getGuesses().size(); i++) {
        outputFile << gWord.getGuesses()[i] << " ";
	}

	outputFile << "|" << endl;

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
            cout << endl << endl;
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
            cout << endl;
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
            cout << endl << "" << endl;
            cout << "Enter '$' at any time to save and exit." << endl;
            cout << "Guesses: ";
            gWord.printGuesses();
            cout << endl << endl;
            gWord.printUnderscores();
            cout << "Your guess: ";
            break;
        case 3:
            cout.width(28);
            cout.fill('*');
            cout << "" << endl;
            cout.fill('*');
            cout.width(28);
            cout << "********  You won!  ********" << endl;
            cout.width(28);
            cout.fill('*');
            cout << "" << endl;
            break;
        case 4:
            cout.width(28);
            cout.fill('*');
            cout << "" << endl;
            cout.fill('*');
            cout.width(28);
            cout << "********  You lost!  *******" << endl;
            cout.width(28);
            cout.fill('*');
            cout << "" << endl;
            break;

    }

}
