#include <iostream>
#include <fstream>
#include <string>
#include "wordToSolve.h"
#include "gameMan.h"

using namespace std;

int main(){
    // Declarations
    gameMan game;
    char letter;
    int diff, option;
    bool isSolved = false;
    // -----------

    game.printMenu(0);

    cin >> option;

    if (option == 1){
        game.printMenu(1);

        cin >> diff;

        game.getWords(diff);
        wordToSolve word(game.pickWord());

        game.gWord = word;


    }
    else if (option == 2){
        game.loadFile();

    }
    else if (option == 3){
        return 0;
    }

    game.gWord.printHangman(game.gWord.getAttempts());

    while ((game.gWord.getAttempts() < 6) && (!isSolved)) {

        game.printMenu(2);

        cin >> letter;


        if (letter == '$') {
            game.saveFile(isSolved);
            return 0;
        }

        isSolved = game.gWord.solve(letter);
        game.gWord.printHangman(game.gWord.getAttempts());
        game.saveFile(isSolved);
    }

    if (isSolved) {game.printMenu(3);} else {game.printMenu(4);}
    cout << "The word was: " << game.gWord.getWord() << endl;

    return 0;
}

