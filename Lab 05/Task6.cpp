#include <iostream>
using namespace std;

bool isSafe(int **maze, int x, int y, int n, int **sol) {
    if (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && sol[x][y] == 0)
        return true;
    return false;
}

bool solveMazeUtil(int **maze, int x, int y, int n, int **sol) {
    if (x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y, n, sol)) {
        sol[x][y] = 1;
        if (solveMazeUtil(maze, x + 1, y, n, sol))
            return true;
        if (solveMazeUtil(maze, x, y + 1, n, sol))
            return true;
        if (solveMazeUtil(maze, x - 1, y, n, sol))
            return true;
        if (solveMazeUtil(maze, x, y - 1, n, sol))
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

bool solveMaze(int **maze, int n) {
    int **sol = new int *[n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
            sol[i][j] = 0;
    }
    if (!solveMazeUtil(maze, 0, 0, n, sol)) {
        cout << "No path found" << endl;
        return false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int **maze = new int *[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    }
    solveMaze(maze, n);
    return 0;
}
