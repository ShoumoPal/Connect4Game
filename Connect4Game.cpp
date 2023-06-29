#include <iostream>

using namespace std;

const int ROW = 6;
const int COL = 7;

enum Player { NONE, RED, BLUE };

class Connect4Game {
public:
    void Play() {

        bool gameFinished = false;
        while (!gameFinished) {
            DrawBoard(); // Draws the board
            cout << "===================================" << endl;
            int columnChosen = ChooseColumn();
            if (isColumnValid(columnChosen)) {
                int row =  dropPiece(columnChosen);
                if (checkWin(row, columnChosen)) {
                    DrawBoard();
                    cout << "Congratulations! Player " << currentPlayer << " wins!!" << endl;
                    gameFinished = true;
                }
                SwitchPlayer();
            }
            else {
                cout << "Invalid placement, please enter the column number again..." << endl;
            }
        }
    }

private:
    Player board[ROW][COL] = { Player::NONE };
    Player currentPlayer = Player::RED;

    void DrawBoard() {

        for (int i = 0; i < COL; i++) {
            cout << " " << i;
        }
        cout << endl;
        cout << "---------------" << endl;
        for (int i = 0; i < ROW; i++) {
            cout << "|";
            for (int j = 0; j < COL; j++) {
                switch (board[i][j]) {
                case Player::NONE:
                    cout << " ";
                    break;
                case Player::RED:
                    cout << "R";
                    break;
                case Player::BLUE:
                    cout << "B";
                    break;
                }
                cout << "|";
            }
            cout << endl;
            cout << "---------------" << endl;
        }
    }

    void SwitchPlayer() {
        currentPlayer = (currentPlayer == Player::RED) ? Player::BLUE : Player::RED;
    }

    int ChooseColumn() {
        int column;
        cout << ((currentPlayer == Player::RED) ? "Player 1: " : "Player 2: ") << endl;
        cout << "Enter the column number (0-6): ";
        cin >> column;
        return column;
    }

    bool isColumnValid(int column) {
        return (column >= 0 && column < COL && board[0][column] == Player::NONE);
    }

    int dropPiece(int col) {
        
        int row = ROW - 1;

        while (board[row][col] != Player::NONE) {
            row--;
        }

        board[row][col] = currentPlayer;
        return row;
    }

    bool checkWin(int _row, int _col) {
        return false;
    }
};
int main() {
    Connect4Game game;
    game.Play();
}