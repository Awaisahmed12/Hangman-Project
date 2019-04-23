#ifndef GAMEMAN_H
#define GAMEMAN_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class gameMan{
	public:
		gameMan(){
			difficulty = 1;
		}
		gameMan(int h){
			difficulty = h;
		}
		void saveFile();
		void loadFile();
		bool activeGame(); 

	private:
		int difficulty;
	
};


#endif
