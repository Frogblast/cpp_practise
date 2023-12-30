#include <iostream>
#include <ctime> // For time(int) function

using namespace std;

int main()
{
    // Declare variables
    bool running = true;
    int input;
    unsigned int guessLimit;
    unsigned int guessCounter = 0;

    // Generate a random number between 1 and 100
    time_t randomSeed = time(0);
    srand(static_cast<unsigned int>(randomSeed));
    int secretNumber = randomSeed % 100 + 1;

    // Start game
    cout << "Enter how many guesses you want (1-10)" << endl;
    cin >> guessLimit;

    // Limit guessLimits to 10
    guessLimit > 10 ? guessLimit = 10 : guessLimit = guessLimit;

    system("CLS"); // Clear screen. Part of iostream library
    cout << "There is a secret number between 1 and 100. Can you guess what it is?" << endl;
    while (running)
    {
        // Check for game over
        if (guessCounter >= guessLimit)
        {
            system("CLS");
            cout << "No more guesses available. Game over!" << endl;
            running = false;
            continue;
        }

        cout << "\nGuesses remaining: " << guessLimit - guessCounter << endl;
        cin >> input;

        // Evaluates the guess
        if (input < secretNumber)
        {
            cout << "The secret number is bigger than the one you guessed. ";
        }
        else if (input > secretNumber)
        {
            cout << "The secret number is smaller than the one you guessed. ";
        }
        else
        {
            cout << "You found the secret number!" << endl;
            // End and quit the game
            running = false;
            continue;
        }

        guessCounter++;
        cout << "Guess again!" << endl;
    }
    cout << "The secret number was: " << secretNumber << endl;

    return 0;
}