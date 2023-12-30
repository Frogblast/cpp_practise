#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main()
{
    // Declare variables
    bool running = true;
    int input;

    // Generate a random number
    time_t randomSeed = time(0);
    srand(static_cast<unsigned int>(randomSeed));
    int secretNumber = randomSeed % 100 + 1;

    // Start game
    cout << "There is a secret number between 1 and 100. Can you guess what it is?" << endl;
    while (running)
    {
        cin >> input;

        // Evaluates the guess
        if (secretNumber == input)
        {
            cout << "You found the secret number!" << endl;
            // End and quit the game
            running = false;
        }
        else if (input > secretNumber)
        {
            cout << "The secret number is bigger than the one you guessed\n\t Guess again!" << endl;
        }
        else
        {
            cout << "The secret number is smaller than the one you guessed\n\t Guess again!" << endl;
        }
    }

    return 0;
}