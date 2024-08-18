#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int SIZE = 3;
const char PLAYER_A = 'X';
const char PLAYER_B = 'O';
const int WIN_SCORE = 1;
const int DRAW_SCORE = 0;
const int LOSE_SCORE = -1;

struct Move {
    int row, col;
};

class TicTacToe {
public:
    TicTacToe() {
        board.resize(SIZE, vector<char>(SIZE, ' '));
    }

    void play() {
        while (true) {
            printBoard();
            if (isGameOver()) {
                cout << "Game Over!" << endl;
                break;
            }
            if (currentPlayer == PLAYER_A) {
                Move bestMove = minimax(PLAYER_A);
                board[bestMove.row][bestMove.col] = PLAYER_A;
                currentPlayer = PLAYER_B;
            } else {
                Move bestMove = minimax(PLAYER_B);
                board[bestMove.row][bestMove.col] = PLAYER_B;
                currentPlayer = PLAYER_A;
            }
        }
    }

private:
    vector<vector<char>> board;
    char currentPlayer = PLAYER_A;

    void printBoard() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    bool isGameOver() {
        return checkWin(PLAYER_A) || checkWin(PLAYER_B) || isDraw();
    }

    bool checkWin(char player) {
        for (int i = 0; i < SIZE; ++i) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                return true;
            }
        }
        return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
               (board[0][2] == player && board[1][1] == player && board[2][0] == player);
    }

    bool isDraw() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    Move minimax(char player) {
        int bestScore = (player == PLAYER_A) ? numeric_limits<int>::min() : numeric_limits<int>::max();
        Move bestMove = {-1, -1};

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;
                    int score = evaluate();
                    board[i][j] = ' ';

                    if ((player == PLAYER_A && score > bestScore) || (player == PLAYER_B && score < bestScore)) {
                        bestScore = score;
                        bestMove = {i, j};
                    }
                }
            }
        }
        return bestMove;
    }

    int evaluate() {
        if (checkWin(PLAYER_A)) return WIN_SCORE;
        if (checkWin(PLAYER_B)) return LOSE_SCORE;
        return DRAW_SCORE;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
