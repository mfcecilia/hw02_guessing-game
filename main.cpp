/*
 * The computer program randomly generates a number in the range of 1 to 10 and
 * the user tries to guess it.  Output both numbers and tell the player if they
 * guessed too low, guessed too high or guessed the random number.
 */


/*
 * File:   main.cpp
 * Author: Evelyn Garcia
 *
 * Created on October 9, 2017, 3:03 PM
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//guessing range
int low = 1;
int high = 10;

//ready?
string userReady;

//computer random number
int randNum = (rand()%high)+low;

//user number guess
int userNum;

//computer answer
int computer;

//player answer
int player;

//rounds
int round = 0;

//scoreboard -- 2*100 matrix
int score[2][10];



/*
 * main method
 */
int main() {

    //welcome to the guessing game
    cout << "Welcome to the guessing game! \n" << endl;

    //ready player one
    cout << "Are you ready to play? (Y/N): \n" << endl;
    //user ready response
    cin >> userReady;


    //game
    while (userReady == "y") {

        //ask user to guess a number
        printf("Enter number from %d to %d \n", low, high);
        //get user input
        cin >> userNum;

        if (userNum == randNum) {
            cout << "You Win! \n" << endl;
            score[0][round] = userNum;
            score[1][round] = randNum;
        }
        else if ((userNum < randNum) && (userNum > 0)) {
            cout << "You guessed too low. \n" << endl;
            score[0][round] = userNum;
        }
        else if ((userNum > randNum) && (userNum < high + 1)) {
            cout << "You guessed too high. \n" << endl;
            score[0][round] = userNum;
        }
        else {
            cout << "That doesn't appear to be a valid input. \n" << endl;
            break;
        }

        //loop rows
        for(int i = 0; i < 2; i++) {
            //loop columns
            for (int j = 0; j < 10; j++) {
                cout << score[i][j] << endl;
            }
        }

        //ready player one
        cout << "Play again? (Y/N): \n" << endl;
        //next round
        round++;
        //user ready response
        cin >> userReady;
    }

    return 0;
}
