#include <iostream>
#include <vector>

using namespace std;

class NQueens {
public:
    static int count;

    static bool isSafe(vector<vector<char>>& board, int row, int col) {
        // Check upper column
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    static void nQueen(vector<vector<char>>& board, int row) {
        if (row == board.size()) {
            printBoard(board);
            count++;
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                nQueen(board, row + 1); // Recursive call
                board[row][col] = 'x';  // Backtrack step
            }
        }
    }

    static void printBoard(const vector<vector<char>>& board) {
        cout << "--- Chess Board ---" << endl;
        for (const auto& row : board) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int NQueens::count = 0;

int main() {
    int n;
    cout << "Enter the size of n: ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, 'x')); // Initialize board
    NQueens::nQueen(board, 0);

    cout << "Total solutions: " << NQueens::count << endl;
    return 0;
}