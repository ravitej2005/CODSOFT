#include <iostream>
#include <ctime>
using namespace std;

class GuessingGame
{
    int user_guess;
    int target;

public:
    GuessingGame();
    void user_input();
    int checkwin(int, int);
    ~GuessingGame() {}
};

GuessingGame :: GuessingGame()
{
    srand(time(NULL));
    target = rand()%50 + 1;
}

void GuessingGame :: user_input()
{
    int guess;
    int x;
    cout << "Make a Guess(1-50) : " ;
    cin >> guess;
    for (int i = 1; i <= 5; i++)
    {
        if (guess > 50 || guess < 1)
        {
            cout << "Your guess is out of bound - Kindly guess number between 0-50" << endl
                 << "You have " << 5 - i << " chances left..." << endl;

            cout << "\nMake another Guess : " << endl;
            cin >> guess;
            continue;
        }
        x = this->checkwin(guess, i);
        if (i == 5 && x == 0)
        {
            cout << "Alas..!! You Lost..!!" << endl;
            break;
        }
        if (x == 1)
        {
            break;
        }
        cout << "\nMake another Guess : " ;
        cin >> guess;
    }
}

int GuessingGame ::checkwin(int guess, int i)
{
    user_guess = guess;
    if (user_guess == target)
    {
        cout << "Amazing !! You guessed number correctly !! We appreciate your intuitions !!!" << endl;
        return 1;
    }
    else if (user_guess > target && user_guess <= (target + 5))
    {
        cout << "You are too close...!!! try a little lower number...!!" << endl
             << "You have " << 5 - i << " chances left..." << endl;
        return 0;
    }
    else if (user_guess > (target + 5) && user_guess <= (target + 15))
    {
        cout << "Your guess is little high but you are close...!!! try more...!!" << endl
             << "You have " << 5 - i << " chances left..." << endl;
        return 0;
    }
    else if (user_guess > (target + 15) && user_guess <= (target + 50))
    {
        cout << "Your guess is too high...!!! try harder kid...!!" << endl
             << "You have " << 5 - i << " chances left..." << endl;
        return 0;
    }
    else if (user_guess < target && user_guess >= (target - 5))
    {
        cout << "You are too close...!!! try a little greater number...!!" << endl
             << "You have " << 5 - i << " chances left..." << endl;
        return 0;
    }
    else if (user_guess < (target - 5) && user_guess >= (target - 15))
    {
        cout << "Your guess is little low but you are close...!!! try more...!!" << endl
             << "You have " << 5 - i << " chances left..." << endl;
        return 0;
    }
    else if (user_guess < (target - 15) && user_guess >= (target - 50))
    {
        cout << "Your guess is too low...!!! try harder kid...!!" << endl
             << "You have " << 5 - i << " chances left..." << endl;
        return 0;
    }
    return 0;
}

void play()
{
    GuessingGame game;
    game.user_input();
}

int main()
{
   
    cout << "\nWelcome to the Guessing Game!\n";
    int choice;
    do
    {
         cout<< "Let's Start, I have selected a number between 1 and 50.\n"
         << "You have 5 chances to guess it correctly.\n"
         << "It gives you feedback depending on how far you are from the target.\n"
         << "Here is how feedback works:\n"
         << " - 0-5: You're too close!\n"
         << " - 5-15: Little high/low, You're close!\n"
         << " - 15-50: You're too high/low!\n"
         << "Let's get started!\n"
         << endl;
        play();
        cout << "\nWanna restart game ?" << endl
             << "1. Restart (Press 1 to restart)" << endl
             << "2. Exit (Press 0 to exit)" << endl;
        cin >> choice;
        cout<<endl;
    } while (choice == 1);

    cout << "Exiting the game...." << endl;
    return 0;
}
