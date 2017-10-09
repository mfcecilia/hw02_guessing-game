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
        }
        else if ((userNum < randNum) && (userNum > 0)) {
            cout << "You guessed too low. \n" << endl;
        }
        else if ((userNum > randNum) && (userNum < high + 1)) {
            cout << "You guessed too high. \n" << endl;
        }
        else {
            cout << "That doesn't appear to be a valid input. \n" << endl;
        }

        //ready player one
        cout << "Play again? (Y/N): \n" << endl;
        //user ready response
        cin >> userReady;
    }

    return 0;
}
