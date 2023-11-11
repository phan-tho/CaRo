#include <iostream>
using namespace std;

int t = 0;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void display();
void update(int k);
int check();


int main(){
    display();
    int player1, player2;
    while (t < 9){
        cout << "Player 1 [X] : ";  cin >> player1;
        update(player1);
        t++;
        if (check() == 1){
            cout << "Player 1 win !!!";
            break;
        }

        cout << "Player 2 [O] : ";  cin >> player2;
        update(player2);
        t++;
        if (check() == 2){
            cout << "Player 2 win !!!";
            break;
        }
    }
    
    if (check() == -1)      cout << "HOÀ";
}

int check(){
    for (int i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            if (board[0][i] == 'X')       return 1;
            else                          return 2;
        }
        else if (board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            if (board[0][i] == 'X')       return 1;
            else                          return 2;
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        if (board[0][0] == 'X')       return 1;
        else                          return 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if (board[0][2] == 'X')       return 1;
        else                          return 2;
    }
    return -1;
}

void display(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "  " << board[i][j] << "  ";
        }
        cout << "\n\n";
    }
}
void update(int k){
    int row = k/3,colum = k - row*3 - 1;
    if (t%2 == 0)         board[row][colum] = 'X';
    else                  board[row][colum] = 'O';
    display();
}