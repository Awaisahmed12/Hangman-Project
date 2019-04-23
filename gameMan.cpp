#include "gameMan.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void gameMan::openFile(int diff){
	ifstream inputFile;
	string word; 
	
	inputFile.open("wordBank.txt");
	if(!inputFile.is_open()){cout << "Not working.";}
	else{
	
	
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
}
	inputFile.close();	
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
	
	
}
