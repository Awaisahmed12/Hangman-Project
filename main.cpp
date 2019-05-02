#include <iostream>
#include <fstream>
#include <string>
#include "wordToSolve.h"
#include "gameMan.h"

using namespace std;

class invalidOption {};

int main(){
    // Declarations
    gameMan game;
    string letter;
    int diff, option;
    bool isSolved = false;
    // -----------




   while (true) {
        isSolved = false;


        game.printMenu(0);

        try {
            cin >> option;

            while (cin.fail()) {
                cin.clear();
                cin.ignore();
            }
            if (option != 1 and option != 2 and option != 3){
                throw invalidOption();
            }

            if (option == 1){
                game.printMenu(1);

                cin >> diff;

                if (diff != 1 && diff != 2 && diff != 3) {
                    throw invalidOption();
                }

                game.getWords(diff);
                wordToSolve word(game.pickWord());

                game.gWord = word;

                game.gWord.clearWordGuesses();
            }
            else if (option == 2){
                cout << game.activeGame() << endl;
                if (!game.loadFile()) {
                   // continue;
                }
            }
            else if (option == 3){
                return 0;
            }

            game.gWord.printHangman(game.gWord.getAttempts());

            while ((game.gWord.getAttempts() < 6) && (!isSolved)) {

                game.printMenu(2);

                cin >> letter;


                if (letter == "$") {
                    game.saveFile(isSolved);
                    return 0;
                }

                isSolved = game.gWord.solve(letter);
                game.gWord.printHangman(game.gWord.getAttempts());
                game.saveFile(isSolved);
            }

            if (isSolved) {game.printMenu(3);} else {game.printMenu(4);}
            cout << "The word was: " << game.gWord.getWord() << endl;
            }
            catch(const invalidOption& e){
                cout<< "Invalid option!" <<endl;
                continue;
            }
        }


    return 0;
}

