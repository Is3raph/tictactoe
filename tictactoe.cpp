#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

int choice;
int row, column;
char turn = 'X';
bool draw = false;

// Function to display the current state of the board
void display_board() {
    cout << "Player - 1 [X]  Player - 2 [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n\n";
}

// Function to get player input and update the board
void player_turn() {
    if(turn == 'X') {
        cout << "Player - 1 [X] turn: ";
    } else {
        cout << "Player - 2 [O] turn: ";
    }
    cin >> choice;

    // Map the choice to board coordinates
    switch(choice) {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout << "Invalid Move\n";
            return;
    }

    // Check if the chosen cell is already occupied
    if(board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        // Switch turn
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Please choose another!!\n\n";
        player_turn();
    }
}

// Function to check the game's status
bool gameover() {
    // Check for win
    for(int i=0; i<3; i++) {
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
            return false;
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
            return false;
    }
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
        return false;
    if(board[0][2]==board[1][1] && board[0][2]==board[2][0])
        return false;

    // Check for draw
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

int main() {
    cout << "Tic Tac Toe Game!\n";
    cout << "For 2 players.\n";

    while(gameover()) {
        display_board();
        player_turn();
    }

    display_board();

    if(draw) {
        cout << "Game Draw!\n";
    } else {
        if(turn == 'X')
            cout << "Player 2 [O] Wins! Congratulations!\n";
        else
            cout << "Player 1 [X] Wins! Congratulations!\n";
    }

    return 0;
}
