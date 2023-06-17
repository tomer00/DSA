#include <iostream>
using namespace std;

bool isSafe(int col, int row, int** mat, int n) {
    int x = row;
    int y = col;


    /// checking row negatively   <------
    for(int x=0;x<row;x++) if(mat[x][col]==1) return false;

    x = row;
    y = col;

    while (y >= 0 && x >= 0) {
        if (mat[x--][y--] == 1) return false;
    }

    x = row;
    y = col;

    while (y < n && x >= 0) {
        if (mat[x--][y++] == 1) return false;
    }

    return true;

}

bool solveQueen(int** mat, int n, int x) {
    if (x >= n) {
        return true;
    }

    for (int i = 0;i < n;i++) {
        if (isSafe(i, x, mat, n)) {
            mat[x][i] = 1;
            if (solveQueen(mat, n, x + 1)) return true;
            else {
                mat[x][i] = 0;
            }

        }
    }

    return false;
}

int main() {

    cout << "Board Size: ";

    int n;
    int** board, ** ans;
    cin >> n;

    board = new int* [n];
    ans = new int* [n];

    for (int i = 0;i < n;i++) {
        board[i] = new int[n];
        ans[i] = new int[n];
        for (int j = 0;j < n;j++) {
            board[i][j] = 0;
            ans[i][j] = 0;
        }
    }

    solveQueen(board, n, 0);


    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << (board[i][j] == 1 ? "A" : "-") << " ";
        }
        cout << endl;
    }

    return 0;
}