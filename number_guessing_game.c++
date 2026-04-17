#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "=== NUMBER GUESSING GAME ===\n";
    cout << "I have selected a number between 1 and 100. Can you guess it?\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "The number is too high. Try again.\n\n";
        }
        else if (guess < secretNumber) {
            cout << "The number is too low. Try again.\n\n";
        }
        else {
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts!\n";
        }
        
    } while (guess != secretNumber);
    return 0;
}