#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define N 4

// Function to check if a move is valid
bool isSafe(int maze[N][N], int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

// Utility function to solve the maze and track the path
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], vector<string>& path) {
    // If (x, y) is the destination, mark it and return true
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if the current move is valid
    if (isSafe(maze, x, y, sol)) {
        sol[x][y] = 1; // Mark (x, y) as part of the solution path

        // Move Down
        path.push_back("down");
        if (solveMazeUtil(maze, x + 1, y, sol, path))
            return true;
        path.pop_back();

        // Move Right
        path.push_back("right");
        if (solveMazeUtil(maze, x, y + 1, sol, path))
            return true;
        path.pop_back();

        // Move Up
        path.push_back("up");
        if (solveMazeUtil(maze, x - 1, y, sol, path))
            return true;
        path.pop_back();

        // Move Left
        path.push_back("left");
        if (solveMazeUtil(maze, x, y - 1, sol, path))
            return true;
        path.pop_back();

        // Backtrack: Unmark (x, y) and return false
        sol[x][y] = 0;
        return false;
    }
    return false;
}

// Function to solve the maze and print the path
bool solveMaze(int maze[N][N]) {
    int sol[N][N] = {0}; // Solution matrix initialized to 0
    vector<string> path;

    if (solveMazeUtil(maze, 0, 0, sol, path) == false) {
        cout << "No solution exists" << endl;
        return false;
    }

    // Print the sequence of moves
    for (const string& step : path)
        cout << step << " ";
    cout << endl;

    return true;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
