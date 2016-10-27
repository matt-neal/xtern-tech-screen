#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

struct userID {
    void setCoins(int coin) {
        coins = coin;
    }

    int getCoins(){
        return coins;
    }

    void setUserId(string user) {
        userId = user;
    }

public:
    int coins = 0;
    string userId;
};

//number generator with a range
int NewNumber(int range) {
    int random = rand() %range;
    return random;
}

//guess validation (returns true/false)
bool HandleGuess(struct userID * newUser, int range) {
    bool keepGoing = true;
    int guesses = 1;
    int numberToFind = NewNumber(range);
    int numberToGuess = NewNumber(range);
    int currentCoins = newUser->getCoins();
    while(keepGoing) {
        if (numberToFind == numberToGuess) {
            currentCoins++;
            newUser->setCoins(currentCoins);
            cout << "This attempt took " << guesses << " trys to complete." << endl;
            keepGoing = false;
        }
        else {
            guesses++;
            numberToGuess = NewNumber(range);
        }
    }
    return true;
}

//returns the users current amount of coins
int GetCoins(struct userID * newUser){
    int coinInfo = newUser->getCoins();
    cout << coinInfo << endl;
    return coinInfo;
}

//begins the guessing program
bool StartGuessing(int range, struct userID * newUser) {
    HandleGuess(newUser, range);
    return true;
}

int main(){
    srand(time(NULL));
    bool keepgoing = true;
    bool keepGOING = true;
    int choose = 0;
    int range = 0;
    string userId = "";
    while (keepgoing) {
        cout << "Welcome to XternCoin!" << endl;
        cout << "Please enter a user id" << endl;
        cin >> userId;

        userID *newUser = new userID;
        newUser->setUserId(userId);
        while (keepGOING) {
            cout << "Please select from the following options:" << endl;
            cout << "1 to start a new random guess." << endl;
            cout << "2 to clear your user information." << endl;
            cout << "3 to end your session. This will terminate the program." << endl;
            cin >> choose;
            if (choose == 1) {
                    cout << "Please select a range for the random number and search." << endl;
                    cout << "(I advise less than 100000.)" << endl;
                    cin >> range;
                    StartGuessing(range, newUser);
                    GetCoins(newUser);
                }
            else if (choose == 2) {
                delete newUser;
            } else if (choose == 3) {
                keepgoing = false;
                keepGOING = false;
            } else {
                cout << "I'm sorry, that is an invalid selection." << endl;
            }
        }
    }
}