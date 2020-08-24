#include <iostream>
#include <vector>

using namespace std;

int countAliveNeighbors(int i, int j, int m, int n, vector<vector<int>>& board) {
    int counter = 0;

    if (i != 0) {
        if (j != 0) {
            counter += board[i -1][j - 1];
        }
        counter += board[i -1][j];
        if (j != n - 1) {
            counter += board[i - 1][j + 1];
        }
    }
    if (j != 0) {
        counter += board[i][j - 1];
    }
    if (j != n - 1) {
        counter += board[i][j + 1];
    }
    if (i != m - 1) {
        if ( j != 0) {
            counter += board[i + 1][j - 1];
        }
        counter += board[i + 1][j];
        if ( j != n - 1) {
            counter += board[i + 1][j + 1];
        }
    }

    return counter;
}

void gameOfLifeV1(vector<vector<int>>& board) {
    vector<vector<int>> new_state;
    for (int i = 0; i < board.size(); ++i) {
        vector<int> line(board[i].size());

        for (int j = 0; j < board[i].size(); ++j) {
            int an = countAliveNeighbors(i, j, board.size(), board[i].size(), board);
            if (board[i][j] == 1 && an < 2) {
                line[j] = 0;
            }
            if (board[i][j] == 1 && (an == 2 || an == 3)) {
                line[j] = 1;
            }
            if (board[i][j] == 1 && an > 3) {
                line[j] = 0;
            }
            if (board[i][j] == 0 && an == 3) {
                line[j] = 1;
            }
        }
        new_state.push_back(line);
    }
    board.swap(new_state);
}

int findAliveNeighbors(vector<vector<int>>& board, int row, int col, int m, int n){
    int top = max(0, row - 1);
    int bottom = min(row + 1, m - 1);

    int left = max(0, col - 1);
    int right = min(col + 1, n - 1);

    int live=0;
    for (int i = top; i <= bottom; ++i) {
        for (int j = left; j <= right; ++j){
            if (i == row && j == col)
                continue;

            int cur = board[i][j] & 1;
            if (cur == 1)
                ++live;
        }
    }

    return live;
}

void gameOfLifeV2(vector<vector<int>>& board) {
    auto maxRow = board.size();
    auto maxCol = board[0].size();

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxCol; ++j) {
            int curValue = board[i][j]&1;

            int an = findAliveNeighbors(board, i, j, maxRow, maxCol);
            if (curValue == 0 && an == 3) {
                board[i][j] = board[i][j] | 2;
            }
            if (curValue == 1) {
                if (an < 2) {
                    board[i][j] = board[i][j] | 0;
                } else if (an < 4) {
                    board[i][j] = board[i][j] | 2;
                } else {
                    board[i][j] = board[i][j] | 0;
                }
            }
        }
    }

    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxCol; ++j) {
            board[i][j] = board[i][j] >> 1;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
