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
    // -----------

    game.printMenu(0);

    cin >> option;

    if (option == 1){
        game.printMenu(1);
    }
    else if (option == 2){

    }
    else if (option == 3){
        return 0;
    }

    cin >> diff;

    game.getWords(diff);
    wordToSolve word(game.pickWord());
    game.gWord = word;


    while (game.gWord.getAttempts() < 6) {
        game.printMenu(2);

        cin >> letter;
        if (letter == '$') {
            game.saveFile();
            return 0;
        }

        game.gWord.solve(letter);
    }

    cout << "The word was: " << game.gWord.getWord() << endl;

    return 0;
}

