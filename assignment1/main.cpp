// Nicholas Nikas
// 260870980
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
-- INSERT --
