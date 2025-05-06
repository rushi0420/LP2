#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int ROW = 5;
const int COL = 5;

struct Cell {
    int parent_i, parent_j;
    double f, g, h;
};

struct Pair {
    int i, j;
};

// Heuristic function: Manhattan distance
double heuristic(int row, int col, int destRow, int destCol) {
    return abs(row - destRow) + abs(col - destCol);
}

// Check if cell is valid
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Check if cell is blocked
bool isUnblocked(vector<vector<int>>& grid, int row, int col) {
    return grid[row][col] == 1;
}

// Check if destination is reached
bool isDestination(int row, int col, Pair dest) {
    return row == dest.i && col == dest.j;
}

// Trace the path from destination to source
void tracePath(vector<vector<Cell>>& cellDetails, Pair dest) {
    int row = dest.i;
    int col = dest.j;

    vector<Pair> path;
    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
        path.push_back({ row, col });
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    path.push_back({ row, col });
    reverse(path.begin(), path.end());

    cout << "Path:\n";
    for (auto p : path) {
        cout << "(" << p.i << "," << p.j << ") ";
    }
    cout << endl;
}

// A* algorithm implementation
void aStarSearch(vector<vector<int>>& grid, Pair start, Pair dest) {
    if (!isValid(start.i, start.j) || !isValid(dest.i, dest.j)) {
        cout << "Invalid start or destination.\n";
        return;
    }
    if (!isUnblocked(grid, start.i, start.j) || !isUnblocked(grid, dest.i, dest.j)) {
        cout << "Start or destination is blocked.\n";
        return;
    }

    if (isDestination(start.i, start.j, dest)) {
        cout << "Already at destination.\n";
        return;
    }

    vector<vector<bool>> closedList(ROW, vector<bool>(COL, false));
    vector<vector<Cell>> cellDetails(ROW, vector<Cell>(COL));

    int i = start.i, j = start.j;
    cellDetails[i][j] = { i, j, 0.0, 0.0, 0.0 };

    using PFC = pair<double, Pair>;
    priority_queue<PFC, vector<PFC>, greater<PFC>> openList;
    openList.push({ 0.0, { i, j } });

    // 4 directions (up, down, left, right)
    int rowNum[] = { -1, 1, 0, 0 };
    int colNum[] = { 0, 0, -1, 1 };

    while (!openList.empty()) {
        PFC current = openList.top();
        openList.pop();

        i = current.second.i;
        j = current.second.j;
        closedList[i][j] = true;

        for (int dir = 0; dir < 4; dir++) {
            int newRow = i + rowNum[dir];
            int newCol = j + colNum[dir];

            if (isValid(newRow, newCol)) {
                if (isDestination(newRow, newCol, dest)) {
                    cellDetails[newRow][newCol].parent_i = i;
                    cellDetails[newRow][newCol].parent_j = j;
                    tracePath(cellDetails, dest);
                    return;
                }

                if (!closedList[newRow][newCol] && isUnblocked(grid, newRow, newCol)) {
                    double gNew = cellDetails[i][j].g + 1.0;
                    double hNew = heuristic(newRow, newCol, dest.i, dest.j);
                    double fNew = gNew + hNew;

                    if (cellDetails[newRow][newCol].f == 0.0 || cellDetails[newRow][newCol].f > fNew) {
                        openList.push({ fNew, { newRow, newCol } });

                        cellDetails[newRow][newCol].f = fNew;
                        cellDetails[newRow][newCol].g = gNew;
                        cellDetails[newRow][newCol].h = hNew;
                        cellDetails[newRow][newCol].parent_i = i;
                        cellDetails[newRow][newCol].parent_j = j;
                    }
                }
            }
        }
    }

    cout << "Failed to find a path to the destination.\n";
}

int main() {
    vector<vector<int>> grid = {
        { 1, 1, 1, 1, 1 },
        { 1, 0, 1, 0, 1 },
        { 1, 1, 1, 0, 1 },
        { 0, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1 }
    };

    Pair start = { 0, 0 };
    Pair dest = { 4, 4 };

    aStarSearch(grid, start, dest);

    return 0;
}
