#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    int moves;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X'), moves(0) {}

    void displayBoard() {

        cout << "\n  0   1   2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << " ";

            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            
            cout << "\n";
            if (i < 2) cout << " ---+---+---\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            return false;
        }

        board[row][col] = currentPlayer;
        moves++;
        return true;
    }

    bool checkWinner() {

        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
        }

        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;
        return false;
    }

    bool isDraw() {
        return moves == 9;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }

    void reset() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        moves = 0;
    }
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    TicTacToe game;
    int row, col;
    char playAgain;

    cout << "=== TIC TAC TOE ===\n";
    cout << "Player X vs Player O\n\n";

    do {
        game.reset();
        
        while (true) {
            game.displayBoard();
            cout << "Player " << game.getCurrentPlayer() << "'s turn\n";
            cout << "Enter row (0-2) and column (0-2): ";
            
            if (!(cin >> row >> col)) {
                clearInput();
                cout << "Invalid input. Try again.\n";
                continue;
            }

            if (!game.makeMove(row, col)) {
                cout << "Invalid move. Cell occupied or out of range.\n";
                continue;
            }

            if (game.checkWinner()) {
                game.displayBoard();
                cout << "Player " << game.getCurrentPlayer() << " WINS!\n";
                break;
            }

            if (game.isDraw()) {
                game.displayBoard();
                cout << "It's a DRAW!\n";
                break;
            }

            game.switchPlayer();
        }

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
        clearInput();

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}