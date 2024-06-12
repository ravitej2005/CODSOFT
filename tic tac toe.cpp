#include <iostream>
using namespace std;

class board
{
    char grid[3][3];

public:
    board()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grid[i][j] = ' ';
            }
        }
    }

    void displayboard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << grid[i][j];
                if (j < 2)
                {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i < 2)
            {
                cout << "---------\n";
            }
        }
    }
    bool updateboard(int &row, int &col, char s)
    {
        if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != ' ')
        {
            cout << "Invalid Move...!! Replay yor move...\n";
            return false;
        }
        else
        {
            grid[row][col] = s;
            return true;
        }
    }
    int checkwin(char s)
    {
        for (int i = 0; i < 3; i++)
        {
            if ((grid[i][0] == s && grid[i][1] == s && grid[i][2] == s) || (grid[0][i] == s && grid[1][i] == s && grid[2][i] == s) ||
                (grid[0][0] == s && grid[1][1] == s && grid[2][2] == s) || (grid[0][2] == s && grid[1][1] == s && grid[2][0] == s))
            {
                return 1;
            }
        }
        return 0;
    }

    int checkdraw()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == ' ')
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    ~board() {}
};

class player
{
    char symbol;

public:
    player(char s) : symbol(s) {}

    char getsymbol()
    {
        return symbol;
    }

    void getmove(int &row, int &col, char s)
    {
        cout << "Player" << s << " move : ";
        cin >> row >> col;
        row--;
        col--;
    }
};

class game
{
    player playerX;
    player playerO;
    player *CurrentPlayer;

public:
    game() : playerX('X'), playerO('O')
    {
        CurrentPlayer = &playerX;
    };

    void SwitchPlayers()
    {
        if (CurrentPlayer == &playerX)
        {
            CurrentPlayer = &playerO;
        }
        else
        {
            CurrentPlayer = &playerX;
        }
    }

    void PlayGame()
    {
        board board;
        cout << "\n#Instructions - " << endl
             << "1. Player 1 is playerX and Player 2 is playerO" << endl
             << "2. Enter your move in following format - row_number<space>coloumn_number" << endl
             << "   e.g. 2 3 (This will mean 2nd row-3rd coloumn position)" << endl;
        bool gameover = false;
        while (!gameover)
        {
            int row, col;
            cout << endl;
            board.displayboard();
            cout << endl;
            CurrentPlayer->getmove(row, col, CurrentPlayer->getsymbol());
            if (board.updateboard(row, col, CurrentPlayer->getsymbol()))
            {
                if (board.checkwin(CurrentPlayer->getsymbol()))
                {
                    gameover = true;
                    cout << endl;
                    board.displayboard();
                    cout << "\nCongradulations...!!! player" << CurrentPlayer->getsymbol() << " wins !!!" << endl;
                }
                else if (board.checkdraw())
                {
                    gameover = true;
                    cout << endl;
                    board.displayboard();
                    cout << "\nMatch Draw...!!!" << endl;
                }
                else
                {
                    SwitchPlayers();
                }
            }
            else
            {
                continue;
            }
        }
    }

    bool PlayAgain()
    {
        char response;
        cout << "Do you wanna play game again ?(y/n)\t";
        cin >> response;
        if (response == 'y' || response == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    game game;
    do
    {
        game.PlayGame();
        cout << endl;
    } while (game.PlayAgain());

    return 0;
}