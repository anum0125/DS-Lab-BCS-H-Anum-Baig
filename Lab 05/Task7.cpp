#include <iostream>
using namespace std;

bool canPlace(int **board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;
    return true;
}

void printBoard(int **board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void solve(int **board, int row, int n) {
    if (row == n) {
        printBoard(board, n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (canPlace(board, row, col, n)) {
            board[row][col] = 1;
            solve(board, row + 1, n);
            board[row][col] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int **board = new int *[n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }
    solve(board, 0, n);
    return 0;
}
