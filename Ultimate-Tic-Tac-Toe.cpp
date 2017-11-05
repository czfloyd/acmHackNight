#include<iostream>

using namespace std;


void printBoard (int board[6][7]);
void takeTurn (int board[6][7], int player);
void initArray(int board[6][7]);
bool checkWin(int board[6][7], int player);
int main() {
    int board[6][7];
    bool gameOver = false;
    initArray(board);
    int turn = 1;
    
    while(!gameOver){
        takeTurn(board, turn);
        gameOver = checkWin(board, turn);
        turn = 3 - turn;
    }
    
    turn = 3 - turn;
    printBoard(board);
    
    cout << "Player " << turn << " has won. This player is clearly the superior programmer.\n" << endl;
    return(0);
}

void printBoard (int board[6][7]) {
    cout<< "  1";
    for(int x = 2; x <= 7; x++) {
        cout << "   " << x;
    }
    cout << endl;
    
    
    for(int r = 0; r < 6; r++) {
        cout << "| ";
        for(int c = 0; c < 7; c++) {
            switch (board[r][c]) {
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
        cout << endl << endl;
    }
    
}

void takeTurn (int board[6][7], int player) {
    int col = 0;
    int row = 6;
    bool placed = false;
    cout << "Here is the current board:\n";
    printBoard(board);
    cout << "Player " << player << ", please select which column you are placing your piece in:\n";
    cin >> col;
    col--;
    while (!placed) {
        if (row < 0 || (col < 0 || col > 7)) {
            row = 6;
            cout << "Invalid move. Please try another column:\n";
            cin >> col;
            col--;
        }
        else if (board[row][col] == 0) {
            board[row][col] = player;
            placed = true;
        }
        else {
            row--;
        }
    }
}
void initArray(int board[6][7]) {
    for(int r = 0; r < 6; r ++) {
        for(int c = 0; c < 7 ; c++) {
            board[r][c] = 0;
        }
    }
}

bool checkWin(int board[6][7], int player){
    bool won = false;
    
    
    //Straight Down and NegDiagonal
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 7; col++)
        {
             if( ((board[row][col] == player) &&
                  (board[row+1][col] == player) &&
                  (board[row+2][col] == player) &&
                  (board[row+3][col] == player)) )
                  return (true);
             if(col <= 3)
             {
                 if( (board[row][col] == player) &&
                      (board[row+1][col+1] == player) &&
                      (board[row+2][col+2] == player) &&
                      (board[row+3][col+3] == player))
                      return (true);
             }
             if(col >= 3)
             {
                 if( (board[row][col] == player) &&
                      (board[row+1][col-1] == player) &&
                      (board[row+2][col-2] == player) &&
                      (board[row+3][col-3] == player))
                      return (true);
             }
        }
    }
    
    
    for (int row = 0; row < 6; row++){
        for (int col = 0; col <= 3; col++){
            if (board[row][col] == player &&
                board[row][col+1] == player &&
                board[row][col+2] == player &&
                board[row][col+3] == player)
                return (true);
        }
    }
    
    return (won);
}
    


