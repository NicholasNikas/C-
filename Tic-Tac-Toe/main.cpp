#include <iostream>
#include "functions.cpp"
using namespace std;

int main()
{
    greetAndInstruct();
    bool isWinner = false;
    char board[27];
    displayBoard(board);
    int input;

    while (isWinner == false)
    {
        // Player turn
        cout << "Player turn: ";
        cin >> input;
        bool legal = checkIfLegal(input, board);
        while (!legal)
        {
            cout << "Invalid input, please input a different cell: ";
            cin >> input;
            legal = checkIfLegal(input, board);
        }
        board[input] = 'X';
        displayBoard(board);
        isWinner = checkWinner(board);
        if (isWinner == true)
        {
            cout << "Player has won!!!" << endl;
            break;
        }
        cout << endl;

        // Computer turn
        cout << "Computer turn: ";
        cout << endl;
        computerMove(board);
        displayBoard(board);
        isWinner = checkWinner(board);
        if (isWinner)
        {
            cout << "Computer has won!!!" << endl;
        }
        cout << endl;
    }

    return 0;
}
