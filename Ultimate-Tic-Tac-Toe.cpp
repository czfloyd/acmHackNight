#include <iostream>

using namespace std;

const int sizes = 3;

void printBoard(int board[sizes][sizes][sizes][sizes]);
int takeTurn(int board[sizes][sizes][sizes][sizes], int turn, int prevBoard);
void initArray(int board[sizes][sizes][sizes][sizes]);
bool checkWin(int board[sizes][sizes], int player);
bool checkOverallWin(int board[sizes][sizes][sizes][sizes], int player);
void  printTest(int board[sizes][sizes][sizes][sizes]);
void  printTest();

int main(){
    int board[sizes][sizes][sizes][sizes];
    int turn = 1;
    int prevBoard = -1;
    initArray(board);
    bool gameOver = false;
    
    while (!gameOver){
        prevBoard = takeTurn(board, turn, prevBoard);
        gameOver = checkOverallWin(board, turn);
        turn = 3 - turn;
    }
    
    turn = 3 - turn;
    printBoard(board);
    
    cout << "Player " << turn << " has won. This player is clearly the superior programmer.\n" << endl;
    return(0);
}
bool checkWin(int board[sizes][sizes], int player)
{
    bool win = false;
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        win = true;
    }
    else if (board[0][0] == player && board[0][1] ==player && board[0][2] == player)
    {
        win = true;
    }
    else if (board[1][0] == player && board[1][1] ==player && board[1][2] ==player)
    {
        win = true;
    }
    else if (board[2][0] == player && board[2][1] == player && board[2][2] ==player)   
    {
        win = true;
    }
    else if(board[0][0] == player && board[1][0] == player && board[2][0] ==player)
    {
       win =true;
    }
    else if(board[0][1] == player && board[1][1] == player && board[2][1] ==player)
    {
       win =true;
    }
    else if(board[0][2] == player && board[1][2] == player && board[2][2] ==player)
    {
       win =true;
    }
    else if(board[0][2] == player && board[1][1] == player && board[2][0] ==player)
    {
        win = true;
    }
    return(win);
}
bool checkOverallWin(int board[sizes][sizes][sizes][sizes], int player)
{
     bool win = false;
    if(checkWin(board[0][0],player) == true && checkWin(board[1][1],player) == true && checkWin(board[2][2],player) == true)
    {
        win = true;
    }
    else if (checkWin(board[0][0],player) == true && checkWin(board[0][1],player) == true && checkWin(board[0][2],player) == true)
    {
        win = true;
    }
    else if (checkWin(board[1][0],player) == true && checkWin(board[1][1],player) == true && checkWin(board[1][2],player) == true)
    {
        win = true;
    }
    else if (checkWin(board[2][0],player) == true && checkWin(board[2][1],player) == true && checkWin(board[2][2],player) == true)   
    {
        win = true;
    }
    else if(checkWin(board[0][0],player) == true && checkWin(board[1][0],player) == true && checkWin(board[2][0],player) == true)
    {
       win =true;
    }
    else if(checkWin(board[0][1],player) == true && checkWin(board[1][1],player)== true && checkWin(board[2][1],player) ==true)
    {
       win =true;
    }
    else if(checkWin(board[0][2],player) == true && checkWin(board[1][2],player)== true && checkWin(board[2][2], player)==true)
    {
       win =true;
    }
    else if(checkWin(board[0][2],player) == true && checkWin(board[1][1],player) == true && checkWin(board[2][0],player) == true)
    {
        win = true;
    }
    return(win);
}
void initArray(int board[sizes][sizes][sizes][sizes]){
    for (int i = 0; i < sizes; i++){
        for (int j = 0; j < sizes; j++){
            for (int k = 0; k < sizes; k++){
                for (int l = 0; l < sizes; l++){
                    board[i][j][k][l] = 0;
                }
            }
        }
    }
}

void printBoard(int board[sizes][sizes][sizes][sizes])
{
  for (int i = 0; i < sizes; i++)
    {
        for (int j = 0; j < sizes; j++)
        {
            for (int k = 0; k < sizes; k++)
            {
                cout << "| ";
                for (int l = 0; l < sizes; l++)
                {
                    switch (board[i][k][j][l]) {
                    case 0:
                        cout << "_ | ";
                        break;
                    case 1:
                        cout << "O | ";
                        break;
                    case 2:
                        cout << "X | ";
                        break;
                    }
                }
                cout << "    ";
            }
            cout << endl << endl;
        }
        cout << endl << endl;
    }

}
void printTest()
{
    for(int i = 0; i < 3; i++)
    {
        cout << "| ";
        for(int x = 1; x <= 3; x++)
        {
            cout <<i*3+x<<" | ";
        }
        cout << endl << endl;
    }
}
void printTest(int board[sizes][sizes])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "| ";
        for(int x = 1; x <= 3; x++)
        {
            if(board[i][x-1] == 0)
                cout <<i*3+x<<" | ";
            else 
                cout << "_ | ";
        }
        cout << endl << endl;
    }
}
int takeTurn(int board[sizes][sizes][sizes][sizes], int turn, int prevBoard){
    cout << "Here is the current board:\n";
    printBoard(board);
    int temp = 0;
    int pc = (prevBoard - 1) % 3;
    int pr = (prevBoard - 1) / 3;
    int cr = 0;
    int cc = 0;
    int input = 0;
    bool validMove = false;
    
    if (checkWin(board[pr][pc], 1) || checkWin(board[pr][pc], 2) || prevBoard == -1){
        while(!validMove){
            cout << "Player " << turn << ", you have free reign. Here are your choices for boards:\n";
            printTest();
            cout << "Please choose a board to play in:\n";
            cin >> prevBoard;
            pc = (prevBoard - 1) % 3;
            pr = (prevBoard - 1) / 3;
            if((checkWin(board[pr][pc], 1) || checkWin(board[pr][pc], 2))){
                cout << "Invalid move. Please try again.\n";
            }
            else validMove = true;
        }
    }
    validMove = false;
    while(!validMove){
        cout << "Player " << turn << ", you are in board " << prevBoard << ". Here is the board of moves you can make:\n";
        printTest(board[pr][pc]);
        cout << "Please choose a space to play in:\n";
        cin >> input;
        cr = (input - 1) / 3;
        cc = (input - 1) % 3;
        if (board[pr][pc][cr][cc] != 0){
            cout << "Invalid move. Please try again.\n";
        }
        else {
            validMove = true;
        }
    }
    board[pr][pc][cr][cc] = turn;
    //cout << board[pr][pc][cr][cc] << " should be printed in " << pr << " " << pc << " " << cr << " " << cc << ".\n";
    
    return(input);
}
