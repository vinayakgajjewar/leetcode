#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        // Iterate through each cell. When we reach a 1, perform BFS and mark
        // the other cells in that island as 0 to make sure we don't visit it
        // again.
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        vector<pair<int, int>> directions = {{0,  1},
                                             {0,  -1},
                                             {1,  0},
                                             {-1, 0}};
        int num_islands = 0;
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (grid[i][j] != '1') continue;
                ++num_islands;
                queue<pair<int, int>> to_visit;
                to_visit.push(make_pair(i, j));
                while (!to_visit.empty()) {

                    pair<int, int> curr_cell = to_visit.front();
                    to_visit.pop();
                    for (pair<int, int> direction: directions) {
                        int new_row = curr_cell.first + direction.first;
                        int new_col = curr_cell.second + direction.second;
                        if (new_row < 0 || new_row >= num_rows) continue;
                        if (new_col < 0 || new_col >= num_cols) continue;
                        if (grid[new_row][new_col] == '1') {
                            to_visit.push(make_pair(new_row, new_col));
                            grid[new_row][new_col] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }
};