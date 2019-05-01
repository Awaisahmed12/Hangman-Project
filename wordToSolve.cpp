#include "wordToSolve.h"
using namespace std;

wordToSolve::wordToSolve(string sWord) {
    word = sWord;

    while (underscore.size() != sWord.size()) {
        underscore.push_back('_');
    }
}

wordToSolve::wordToSolve(string sWord, int sAttempts, vector<char> sUnderscore, vector<char> sGuesses) {
    word = sWord;
    attempts = sAttempts;

    for (int i = 0; i < sUnderscore.size(); i++) {
        underscore.push_back(sUnderscore[i]);
    }

    for (int i = 0; i < sGuesses.size(); i++) {
        guesses.push_back(sGuesses[i]);
    }



}
bool wordToSolve::solve(char letter) {
    bool isFound = false;
    bool underscoreFound = false;
    bool guessFound = false;


    for (int i = 0; i < word.size(); ++i) {
        if (tolower(letter) == tolower(word[i])) {
            isFound = true;
            underscore[i] = tolower(word[i]);
        }
    }

    if (!isFound) {
        for (int i = 0; i < guesses.size(); ++i) {
            if (tolower(letter) == tolower(guesses[i])) {
                cout << "You've already guessed this letter" << endl;
                guessFound = true;
                break;
            }
        }

        if (!guessFound) {
            attempts++;
            guesses.push_back(toupper(letter));
        }
    }

    for (int i = 0; i < underscore.size(); i++) {
        if (underscore[i] == '_') {
            underscoreFound = true;
            break;
        }
    }

    if (!underscoreFound) {return true;}
    else {return false;}
}

wordToSolve &wordToSolve::operator=(wordToSolve& otherWord) {
    word = otherWord.getWord();
    underscore = otherWord.getUnderscore();
    guesses = otherWord.getGuesses();
    attempts = otherWord.getAttempts();
}




void wordToSolve::printUnderscores() {
    for (int i = 0; i < underscore.size(); i++) {
        cout << underscore[i] << " ";
    }

    cout << endl;
}

void wordToSolve::printGuesses() {
    for (int i = 0; i < guesses.size(); i++) {
        cout << guesses[i] << " ";
    }

    cout << endl;
}

bool wordToSolve::Solved() {
    for (int i = 0; i < underscore.size(); i++) {
        if (underscore[i] == '_') {
            return false;
        }
    }

    return true;

}

void wordToSolve::printHangman(int o) {
    switch (o) {
        case 0:
            cout << "      ___________  " << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "      ___________  " << endl << endl;
            break;
        case 1:
            cout << "      ___________  " << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "      O         |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "      ___________  " << endl << endl;
            break;
        case 2:
            cout << "      ___________  " << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "      O         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "      ___________  " << endl << endl;
            break;
        case 3:
            cout << "      ___________  " << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "      O         |  "  << endl;
            cout << "     \\|         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "      ___________  " << endl << endl;
            break;
        case 4:
            cout << "      ___________  " << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "      O         |  "  << endl;
            cout << "     \\|/        |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "      ___________  " << endl << endl;
            break;
        case 5:
            cout << "      ___________  " << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "      O         |  "  << endl;
            cout << "     \\|/        |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "     /          |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "      ___________  " << endl << endl;
            break;
        case 6:
            cout << "      ___________  " << endl;
            cout << "      |         |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "      O         |  "  << endl;
            cout << "     \\|/        |  "  << endl;
            cout << "      |         |  "  << endl;
            cout << "     / \\        |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "                |  "  << endl;
            cout << "      ___________  " << endl << endl;
            break;
    }

}
