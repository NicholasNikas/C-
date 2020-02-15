#include <iostream>
#include <cstdlib>
using namespace std;

// function signatures
void greetAndInstruct();
void displayBoard(char board[]);
void index(char board[], int i);
bool checkIfLegal(int cellNbre, char board[]);
bool checkWinner(char board[]);
void computerMove(char board[]);

void greetAndInstruct()
{
    cout << " " << endl;
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
    cout << " " << endl;
    cout << "The board is numbered from 1 to 27 as per the following:" << endl;
    cout << " " << endl;
    cout << "1 | 2 | 3    10 | 11 | 12    19 | 20 | 21" << endl;
    cout << "----------   -------------   ------------ " << endl;
    cout << "4 | 5 | 6    13 | 14 | 15    22 | 23 | 24" << endl;
    cout << "----------   -------------   ------------ " << endl;
    cout << "7 | 8 | 9    16 | 17 | 18    25 | 26 | 27" << endl;
    cout << " " << endl;
    cout << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move" << endl;
    cout << "is marked with X. Computer’s move is marked with O." << endl;
    cout << " " << endl;
    cout << "Start? (y/n): ";
    string dec; // decision from user
    cin >> dec;

    if (dec == "y")
    {
        return;
    }
    else
    {
        exit(0); // exit program
    }
}

void displayBoard(char board[])
{
    cout << endl;
    index(board, 1), cout << " | ", index(board, 2), cout << " | ", index(board, 3), cout << "    ";
    index(board, 10), cout << " | ", index(board, 11), cout << " | ", index(board, 12), cout << "    ";
    index(board, 19), cout << " | ", index(board, 20), cout << " | ", index(board, 21), cout << "    " << endl;
    cout << "----------   ------------    ------------" << endl;
    index(board, 4), cout << " | ", index(board, 5), cout << " | ", index(board, 6), cout << "    ";
    index(board, 13), cout << " | ", index(board, 14), cout << " | ", index(board, 15), cout << "    ";
    index(board, 22), cout << " | ", index(board, 23), cout << " | ", index(board, 24), cout << "    " << endl;
    cout << "----------   ------------    ------------" << endl;
    index(board, 7), cout << " | ", index(board, 8), cout << " | ", index(board, 9), cout << "    ";
    index(board, 16), cout << " | ", index(board, 17), cout << " | ", index(board, 18), cout << "    ";
    index(board, 25), cout << " | ", index(board, 26), cout << " | ", index(board, 27), cout << "    " << endl;
    cout << endl;
    return;
}

// helper method that prints what the index of the board holds
void index(char board[], int i)
{
    if (board[i] != 'X' && board[i] != 'O')
    {
        cout << i;
    }
    else if (board[i] == 'X')
    {
        cout << 'X';
    }
    else if (board[i] == 'O')
    {
        cout << 'O';
    }
}

// check if an index is unoccupied
bool checkIfLegal(int cellNbre, char board[])
{

    if (cellNbre < 1 || cellNbre > 27)
    {
        return false;
    }

    if (board[cellNbre] != 'X' && (board[cellNbre] != 'O'))
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

bool checkWinner(char board[])
{
    // check winner for player
    for (int i = 1; i < 28; i++)
    {
        // check horizontal one board
        if ((i - 1) % 3 == 0 && board[i] == 'X' && board[i + 1] == 'X' && board[i + 2] == 'X')
        {
            return true;
        }
        // check vertical one board
        if ((i == 1 || i == 2 || i == 3 || i == 10 || i == 11 || i == 12 || i == 19 || i == 20 || i == 21) && board[i] == 'X' && board[i + 3] == 'X' && board[i + 6] == 'X')
        {
            return true;
        }
        // check diagonal to the right one board
        if ((i == 1 || i == 10 || i == 19) && board[i] == 'X' && board[i + 4] == 'X' && board[i + 8] == 'X')
        {
            return true;
        }

        // check diagonal to the left one board
        if ((i == 3 || i == 12 || i == 21) && board[i] == 'X' && board[i + 2] == 'X' && board[i + 4] == 'X')
        {
            return true;
        }

        // check same cell across 3 boards
        if (board[i] == 'X' && board[i + 9] == 'X' && board[i + 18] == 'X')
        {
            return true;
        }
        // check horizontal across 3 boards
        if ((i == 2 || i == 5 || i == 8) && board[i] == 'X' && board[i + 10] == 'X' && board[i + 20] == 'X')
        {
            return true;
        }
        // check vertical across 3 boards
        if ((i == 1 || i == 2 || i == 3) && board[i] == 'X' && board[i + 12] == 'X' && board[i + 24] == 'X')
        {
            return true;
        }
        // check diagonal to the right across 3 boards
        if ((i == 1) && board[i] == 'X' && board[i + 13] == 'X' && board[i + 26] == 'X')
        {
            return true;
        }

        // check diagonal to the left across 3 boards
        if ((i == 7) && board[7] == 'X' && board[14] == 'X' && board[21] == 'X')
        {
            return true;
        }
        // check diagonal special case for 3 boards
        if (board[9] == 'X' && board[15] == 'X' && board[21] == 'X')
        {
            return true;
        }

        // check diagonal special case for 3 boards
        if (board[1] == 'X' && board[13] == 'X' && board[25] == 'X')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[9] == 'X' && board[14] == 'X' && board[19] == 'X')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[25] == 'X' && board[14] == 'X' && board[3] == 'X')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[27] == 'X' && board[15] == 'X' && board[3] == 'X')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[27] == 'X' && board[14] == 'X' && board[1] == 'X')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[7] == 'X' && board[14] == 'X' && board[21] == 'X')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[8] == 'X' && board[14] == 'X' && board[20] == 'X')
        {
            return true;
        }
    }
    // check winner for computer
    for (int i = 1; i < 28; i++)
    {
        // check horizontal one board
        if ((i - 1) % 3 == 0 && board[i] == 'O' && board[i + 1] == 'O' && board[i + 2] == 'O')
        {
            return true;
        }
        // check vertical one board
        if ((i == 1 || i == 2 || i == 3 || i == 10 || i == 11 || i == 12 || i == 19 || i == 20 || i == 21) && board[i] == 'O' && board[i + 3] == 'O' && board[i + 6] == 'O')
        {
            return true;
        }
        // check diagonal to the right one board
        if ((i == 1 || i == 10 || i == 19) && board[i] == 'O' && board[i + 4] == 'O' && board[i + 8] == 'O')
        {
            return true;
        }

        // check diagonal to the left one board
        if ((i == 3 || i == 12 || i == 21) && board[i] == 'O' && board[i + 2] == 'O' && board[i + 4] == 'O')
        {
            return true;
        }

        // check same cell across 3 boards
        if (board[i] == 'O' && board[i + 9] == 'O' && board[i + 18] == 'O')
        {
            return true;
        }
        // check horizontal across 3 boards
        if ((i == 2 || i == 5 || i == 8) && board[i] == 'O' && board[i + 10] == 'O' && board[i + 20] == 'O')
        {
            return true;
        }
        // check vertical across 3 boards
        if ((i == 1 || i == 2 || i == 3) && board[i] == 'O' && board[i + 12] == 'O' && board[i + 24] == 'O')
        {
            return true;
        }
        // check diagonal to the right across 3 boards
        if ((i == 1) && board[i] == 'O' && board[i + 13] == 'O' && board[i + 26] == 'O')
        {
            return true;
        }

        // check diagonal to the left across 3 boards
        if ((i == 7) && board[7] == 'O' && board[14] == 'O' && board[21] == 'O')
        {
            return true;
        }
        // check diagonal special case for 3 boards
        if (board[9] == 'O' && board[15] == 'O' && board[21] == 'O')
        {
            return true;
        }

        // check diagonal special case for 3 boards
        if (board[1] == 'O' && board[13] == 'O' && board[25] == 'O')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[9] == 'O' && board[14] == 'O' && board[19] == 'O')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[25] == 'O' && board[14] == 'O' && board[3] == 'O')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[27] == 'O' && board[15] == 'O' && board[3] == 'O')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[27] == 'O' && board[14] == 'O' && board[1] == 'O')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[7] == 'O' && board[14] == 'O' && board[21] == 'O')
        {
            return true;
        }

        // check diagonal other special case for 3 boards
        if (board[8] == 'O' && board[14] == 'O' && board[20] == 'O')
        {
            return true;
        }
    }

    bool isTie = true;
    // check if entire board is occupied for tie
    for (int i = 1; i < 28; i++)
    {
        if (board[i] != 'X' || board[i] != 'O')
        {
            isTie = false;
            break;
        }
    }

    if (isTie)
    {
        cout << "Tie Game!!!" << endl;
        exit(0);
    }

    return false;
}
void computerMove(char board[])
{
    // Check if winning move exists for computer
    for (int i = 1; i < 28; i++)
    {
        if (checkIfLegal(i, board) == true)
        {
            board[i] = 'O';
            if (!checkWinner(board))
            {
                board[i] = i;
            }
            else
            {
                // won the game
                return;
            }
        }
    }
    // Check if winning move exists for player
    for (int i = 1; i < 28; i++)
    {
        if (checkIfLegal(i, board))
        {
            board[i] = 'X';
            if (!checkWinner(board))
            {
                board[i] = i;
            }
            else
            {
                // block winning move
                board[i] = 'O';
                return;
            }
        }
    }

    // make random move
    // generate random number from 1 to 27
    int random = (rand() % 27) + 1;
    bool legal = checkIfLegal(random, board);

    while (!legal)
    {
        random = (rand() % 27) + 1;
        legal = checkIfLegal(random, board);
    }
    board[random] = 'O';
    return;
}
