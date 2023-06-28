#include <iostream>

using namespace std;

const int ROW = 6;
const int COL = 7;

enum Player { NONE, RED, BLUE };

class Connect4Game {
public:
    void Play() {

        DrawBoard(); // Draws the board
        //Hello World
        // B!xh
    }

private:
    Player board[ROW][COL] = { Player::NONE };

    void DrawBoard() {

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
};
int main() {
    Connect4Game game;
    game.Play();
}