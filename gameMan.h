#ifndef GAMEMAN_H
#define GAMEMAN_H

#include <iostream>
#include <string>
#include <fstream>

#include <vector>

using namespace std;

class gameMan{
	public:
		gameMan() {
			difficulty = 1;
		}
		gameMan(int h){
			difficulty = h;
		}
		
		void openFile(int diff);
		void saveFile();
		void loadFile();
		bool activeGame(); 
		vector<string> wordArr;
		
	private:
		int difficulty;
		
		
	
};


#endif
