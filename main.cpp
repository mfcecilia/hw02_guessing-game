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

using namespace std;

//guessing range
int low = 1;
int high = 10;

//ready?
string userReady;

//play?
bool play;

//computer random number
int randNum = (rand()%high)+low;

//user number guess
int userNum;

/*
 * main method
 */
int main() {

    //welcome to the guessing game
    std::cout << "Welcome to the guessing game! \n" << endl;

    //ready player one
    cout << "Are you ready to play? (Y/N): \n" << endl;
    //user ready response
    std::cin >> userReady;
    //to lowercase
    userReady = tolower(userReady);

    while (userReady == "y") {

    }






    //process user ready response
    switch(userReady) {
        case 'y' :
            cout << "Hooray! \n" << endl;
            play = true;
            break;
        case 'n' :
            cout << "Goodbye. \n" << endl;
            play = false;
            break;
        default :
            cout << "Invalid response." << endl;
    }


   //game
    while (play) {

        //ask user to guess a number
        printf("Enter number from %d to %d \n", low, high);

        //store user input
        cin >> userNum;

        //check if guess is an integer
        if (isdigit(userNum)) {

          //check if guess is within range
          if (userNum < low || userNum > high) {

              //error -- not within range
              cout << "Not in range. Try again." << endl;

              //reset failed state
              cin.clear();

              //ask user to guess a number
              printf("Enter number from %d to %d \n", low, high);

              //store user input
              cin >> userNum;
            }

          //error -- not an integer
        } else {

              cout << "Not an number. Try again." << endl;

              //reset failed state
              cin.clear();

              //ask user to guess a number
              printf("Enter number from %d to %d \n", low, high);

              //store user input
              cin >> userNum;
        }

        //compare to computer random number
        if (userNum == randNum) {

          //win if numbers match
          cout << "You're a winner!" << endl;

        } else if (userNum > randNum) {

          //lose if guess is too high
          cout << "You guessed too high. Try again." << endl;

        } else if (userNum < randNum) {

          //lose if guess is too low
          cout << "You guessed too low. Try again." << endl;
        }

    }

    return 0;

}
