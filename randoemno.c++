#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;
    int userguess = 0;
    cout << "Guess the number (between 1 and 100): ";
    while (userguess != randomNumber)
    {
        cin >> userguess;
        if (userguess > randomNumber)
        {
            cout << "Too high! Try again: ";
        } 
        else if (userguess < randomNumber)
        {
            cout << "Too low! Try again: ";
        } else
        {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
        }
    }

    return 0;
}
