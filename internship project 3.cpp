#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }

    // No winner
    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
        currentPlayer = 2;
    } else {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    if (currentMarker == 'X') {
        currentMarker = 'X';
    } else {
        currentMarker = 'O';
    }

    int winner = 0;
    int slot;

    for (int i = 0; i < 9; i++) {
        drawBoard();
        cout << "Player " << currentPlayer << ", enter your slot: ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Please try again.\n";
            i--;
            continue;
        }

        winner = checkWinner();

        if (winner == 1) {
            drawBoard();
            cout << "Player 1 wins!\n";
            break;
        } else if (winner == 2) {
            drawBoard();
            cout << "Player 2 wins!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (winner == 0) {
        drawBoard();
        cout << "It's a tie!\n";
    }
}

int main() {
    game();
    return 0;
}
