//guessing_game.cpp: This program asks for an upper limit, generates a random number based on that limit, asks the user to guess that number, tells them if they are higher or lower, loops until they guess that number, tracks how many times they guess, loops to the begining of the game if they choose to play again.
//Name: Luke MacLean
//Class Section: COSC-1436.900 Online
// Date: 10/11/2021

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

int main()
{
    // Constants: Constants 
    const int MIN_VALUE = 1;


    // Variables:
    int maxValue, randomNumber, guessAttempts, guessNumber;
    char restart;

    do
    {
    guessAttempts = 0;
    cout << "Welcome to the guessing game! I'll choose a random number between 1 and a limit of your choice, and you guess what it is. \n";

    // let the user choose the upper guessing limit
    cout << "How high would you like the guessing range to be? ";
    cin >> maxValue;

    // Generate a random number between 1 and a limit of the user's choice. Make sure that a different random number is chosen each time the game is played.
    unsigned seed = time(0);
    srand(seed);
    randomNumber = rand() % maxValue + MIN_VALUE;

    // Ask the user for their first guess and store it in a variable. 
    cout << "I'm thinking of a number! What is it?";
    cin >> guessNumber;
    guessAttempts++;

    // If the user’s guess is too high or too low, tell them so and give them the opportunity to guess again.
    while (guessNumber != randomNumber){


        // Keep track of the number of tries that it took for the user to get the right answer
        guessAttempts++;

        if (guessNumber > randomNumber)
        {
            cout << "Too high. Try again: ";
            cin >> guessNumber;
        }
        else{
            cout << "Too low. Try again: ";
            cin >> guessNumber;
        }
        
    }

    //Tell the user when they have successfully guessed the number.
    // display the number of attempts to them once they’ve guessed the correct answer.
    cout << "You guessed it! It took " << guessAttempts << " tries.";

   
    // Add the ability for the user to play again without having to restart the game.
    cout << "Would you like to play again? Y/N \n";
    cin >> restart;

    } while (restart == 'y' || restart == 'Y');
    
    return 0;
}