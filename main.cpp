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

//rounds
int round = 0;

//scoreboard -- 2*10 matrix
int score[2][10];

//points
int points = 5;


/*
score method -- keeps and prints results
*/
void keepScore(char result){

    //correct response
    if (result == 'win'){
        //record responses
        score[0][round] = userNum;
        score[1][round] = randNum;
        //move print responses here to avoid cheating when you lose

    //incorrect response
    } else {
        //record responses
        score[0][round] = userNum;
        score[1][round] = randNum;
        //don't show responses so they can't see the answer
    }
    //print responses
    //loop rows
    for(int i = 0; i < 2; i++) {
        //loop columns
        for (int j = 0; j < 10; j++) {
            cout << score[i][j] << "    ";
        }
        cout << endl;
    }
    cout << "\n" << endl;
}




/*
replay method -- starts a fresh new game
*/
void replay() {

    //ready player one
    cout << "Play again? (Y/N): \n" << endl;
    cout << "\n" << endl;

    //user ready response
    cin >> userReady;
    cout << "\n" << endl;

    //reset game
    if (userReady == "y") {
        round = 0;
        randNum = (rand()%high)+low;
        points = 5;
        //clear score board
        for (int a = 0; a < 2; a++){
            for (int b = 0; b < 10; b++) {
                score[a][b] = 0;
            }
        }
    } else if (userReady == "n") {
        //exit game
        cout << "Thanks for playing! Goodbye!" << endl;
        cout << "\n" << endl;
        return;
    } else {
        cout << "That doesn't appear to be a valid input. Goodbye." << endl;
        cout << "\n" << endl;
        return;
    }
}

/*
next round method -- starts the next round
*/
void nextRound() {

    //subtract point
    points--;
    //show points
    printf("Your Score:  %d \n", points);
    cout << "\n" << endl;

    //no points -- game over
    if (points == 0){
        cout << "GAME OVER \n" << endl;
        cout << "\n" << endl;
        replay();

     //points left -- start next round
    } else {
        //ready player one
        cout << "Try again? (Y/N): \n" << endl;
        cout << "\n" << endl;
        //user ready response
        cin >> userReady;
        cout << "\n" << endl;

        //next round
        if (userReady == "y") {
            round++;

        } else if (userReady == "n") {
            //show points
            printf("Your Score:  %d \n", points);
            cout << "\n" << endl;
            //exit game
            cout << "Thanks for playing! Goodbye!" << endl;
            cout << "\n" << endl;
            return;
        } else {
            cout << "That doesn't appear to be a valid input. Goodbye." << endl;
            cout << "\n" << endl;
            return;
        }
    }
}

/*
game play
*/
void gamePlay(){

    while (userReady == "y") {
        //ask user to guess a number
        printf("Enter number from %d to %d \n", low, high);
        cout << "\n" << endl;

        //get user input
        cin >> userNum;
        cout << "\n" << endl;

        if (userNum == randNum) {
            cout << "You Win! \n" << endl;
            cout << "\n" << endl;

            //show points
            printf("Your Score:  %d \n", points);
            cout << "\n" << endl;

            keepScore('win');
            replay();
        }
        else if ((userNum < randNum) && (userNum > 0)) {
            cout << "You guessed too low. \n" << endl;
            cout << "\n" << endl;

            keepScore('lose');
            nextRound();

        }
        else if ((userNum > randNum) && (userNum < high + 1)) {
            cout << "You guessed too high. \n" << endl;
            cout << "\n" << endl;

            keepScore('lose');
            nextRound();
        }
        else {
            cout << "That doesn't appear to be a valid input. Goodbye. \n" << endl;
            cout << "\n" << endl;
            break;
        }
    }
}




/*
 * main method
 */
int main() {

    //welcome to the guessing game
    cout << "Welcome to the guessing game! \n" << endl;
    cout << "\n" << endl;

    //ready player one
    cout << "Are you ready to play? (Y/N): \n" << endl;
    cout << "\n" << endl;

    //user ready response
    cin >> userReady;
    cout << "\n" << endl;

    //game
    gamePlay();

    return 0;
}
