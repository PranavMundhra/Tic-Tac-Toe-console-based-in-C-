#include <iostream>
using namespace std;
void display_board(char board[3][3]);
void player1_play(char board[3][3],bool& win);
void player2_play(char board[3][3],bool& win);
void update_board(char board[3][3],int,int,bool& win);
void check_win(char board[3][3],bool& win);
int main(){
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    display_board(board);
    bool win = false;
    bool draw =  false;
    while (!win && !draw) {
    player1_play(board, win);
    check_win(board, win);
    if (win) {
        cout << "Player 1 ('X') wins the game!!!!";
        break; 
    }

    
    draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = false;
                break;
            }
        }
        if (!draw) {
            break;
        }
    }
    if (draw) {
        cout << "No player wins. It's a draw!" << endl;
        break;
    }

    player2_play(board, win);
    check_win(board, win);
    if (win) {
        cout << "Player 2 ('Y') wins the game!!!!";
        break; 
    }

    
    draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = false;
                break;
            }
        }
        if (!draw) {
            break;
        }
    }
    if (draw) {
        cout << "No player wins. It's a draw!" << endl;
        break;
    }
}


    return 0;
} 

void display_board(char board[3][3]){
    for(int i = 0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<" | "<<board[i][j]; 
        }
        cout<<endl;
        cout<<endl;
    }
    cout<<"-------------------------"<<endl;
}

void player1_play(char board[3][3], bool& win){
    cout<<"Please enter the coordinates where you wanna place 'X' ";
    int x,y;
    cout<<"\nRow: ";
    cin>>x;
    cout<<"\nColoumn: ";
    cin>>y;
    while (x > 2 || y > 2 || board[x][y] != ' ')
{
    cout<<"Invalid input please make sure that coordinates are correct or not already taken ";
    cout<<"\nRow: ";
    cin>>x;
    cout<<"\nColoumn: ";
    cin>>y;
}
    board[x][y] = 'X';


    update_board(board,x,y,win);
}
void player2_play(char board[3][3], bool& win){
    cout<<"Please enter the coordinates where you wanna place 'Y' ";
    int x,y;
    cout<<"\nRow: ";
    cin>>x;
    cout<<"\nColoumn: ";
    cin>>y;
while (x > 2 || y > 2 || board[x][y] != ' ')
{
    cout<<"Invalid input please make sure that coordinates are correct or not already taken ";
    cout<<"\nRow: ";
    cin>>x;
    cout<<"\nColoumn: ";
    cin>>y;
}

    board[x][y] = 'Y';
    update_board(board,x,y,win);
}
void update_board(char board[3][3],int a, int b,bool& win){
     for(int i = 0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<" | "<<board[i][j]; 
        }
        cout<<endl;
        cout<<endl;
    }
    cout<<"-------------------------"<<endl;
    check_win(board,win);
}
void check_win(char board[3][3], bool& win) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            win = true;
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            win = true;
            return;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        win = true;
        return;
    }

    win = false; 
}
