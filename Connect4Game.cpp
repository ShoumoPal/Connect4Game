#include <iostream>

using namespace std;

const int ROW = 6;
const int COL = 7;

enum Player { NONE, RED, BLUE };

class Connect4Game {
public:
    void Play() {

        ShowInstructions();

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
                else if (checkDraw()) {
                    DrawBoard();
                    cout << "It's a draw!" << endl;
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

    void ShowInstructions() {
        cout << "--------------------------------------\n" << endl;
        cout << "\t Welcome to Connect 4\n" << endl;
        cout << "--------------------------------------\n" << endl;
        cout << "Rules:\n" << endl;
        cout << "1. Two-player game (Red & Blue)\n2. Board size is 6x7\n3. A player wins if they are able to connect 4 coins vertically, horizontal and diagonally\n4. Draw when the matrix is filled fully." << endl;
        cout << "--------------------------------------\n" << endl;
        cout << "How to Play:\n" << endl;
        cout << "1. Game always starts with Player 1(Red)\n2. In each step, choose the column number to put your coin in.\n3. Rows will be filled from bottom to top.\n" << endl;
        cout << "--------------------------------------\n" << endl;
    }

    bool checkDraw() {
        for (int j = 0; j < COL; j++) {
            if (board[0][j] == Player::NONE) {
                return false;
            }
        }
        return true;
    }

    void DrawBoard() {

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
        for (int i = 0; i < COL; i++) {
            cout << " " << i;
        }
        cout << endl;
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
        //Horizontal win
        int count = 0;
        for (int i = 0; i < COL; i++) {
            if (board[_row][i] == currentPlayer) {
                count++;
                if (count == 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }

        //Vertical win
        count = 0;
        for (int i = 0; i < ROW; i++) {
            if (board[i][_col] == currentPlayer) {
                count++;
                if (count == 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }

        //Top-left to bottom right check
        count = 0;
        int startrow = _row - min(_row, _col);
        int startcol = _col - min(_row, _col);
        for (int i = startrow, j = startcol; i < ROW && j < COL; i++, j++) {
            if (board[i][j] == currentPlayer) {
                count++;
                if (count == 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }

        //Top-right to bottom left check
        count = 0;
        startrow = _row + min(ROW - _row - 1, _col);
        startcol = _col - min(ROW - _row - 1, _col);
        for (int i = startrow, j = startcol; i < ROW && j < COL; i++, j++) {
            if (board[i][j] == currentPlayer) {
                count++;
                if (count == 4) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
        return false;
    }
};
int main() {
    Connect4Game game;
    game.Play();
}