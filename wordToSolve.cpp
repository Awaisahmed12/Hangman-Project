#include "wordToSolve.h"
using namespace std;

wordToSolve::wordToSolve(string sWord) {
    word = sWord;

    while (underscore.size() != sWord.size()) {
        underscore.push_back('_');
    }

    guesses.clear();
    wordGuesses.clear();
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
bool wordToSolve::solve(string letter) {
    bool isFound = false;
    bool underscoreFound = false;
    bool guessFound = false;
    char letterChar;
    bool isWord = false;

    cout.width(28);
    cout.fill('*');
    cout << "" << endl << endl << endl;

    if (letter.length() != 1) {
        isWord = true;
    } else if (letter.length() == 1) {
        letterChar = letter[0];
    }

    if (isWord) {
        if (letter == word){
            for (int i = 0; i < word.length(); ++i) {
                underscore[i] = word[i];
            }
            return true;
        }
        else {
            attempts++;
            wordGuesses.push_back(letter);
            }
        return false;
    }


    for (int i = 0; i < word.size(); ++i) {
        if (tolower(letterChar) == tolower(word[i])) {
            isFound = true;
            underscore[i] = tolower(word[i]);
        }
    }

    if (!isFound) {
        for (int i = 0; i < guesses.size(); ++i) {
            if (tolower(letterChar) == tolower(guesses[i])) {
                cout << "You've already guessed this letter" << endl;
                guessFound = true;
                break;
            }
        }

        if (!guessFound) {
            attempts++;
            guesses.push_back(toupper(letterChar));
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

void wordToSolve::clearWordGuesses() {
    wordGuesses.clear();

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

    for(int g = 0; g < wordGuesses.size(); g++){
        cout << wordGuesses[g] << " ";
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
