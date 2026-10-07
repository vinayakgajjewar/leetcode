#include <queue>
#include <vector>

using namespace std;

class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        // Iterate through each cell. When we reach a 1, perform BFS and mark
        // the other cells in that island as 0 to make sure we don't visit it
        // again.
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int num_islands = 0;
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                if (grid[i][j] != '1')
                    continue;
                ++num_islands;
                queue<pair<int, int>> to_visit;
                to_visit.push(make_pair(i, j));
                while (!to_visit.empty())
                {

                    pair<int, int> curr_cell = to_visit.front();
                    to_visit.pop();
                    for (pair<int, int> direction : directions)
                    {
                        int new_row = curr_cell.first + direction.first;
                        int new_col = curr_cell.second + direction.second;
                        if (new_row < 0 || new_row >= num_rows)
                            continue;
                        if (new_col < 0 || new_col >= num_cols)
                            continue;
                        if (grid[new_row][new_col] == '1')
                        {
                            to_visit.push(make_pair(new_row, new_col));
                            grid[new_row][new_col] = '0';
                        }
                    }
                }
            }
        }
        return num_islands;
    }

    // This is my attempt from 2026/10/07. Note that you can use recursion to
    // solve this! The time complexity is O(M*N) because in the case where the
    // entire grid is all 1s, you visit each cell once. The space complexity is
    // also O(M*N) but for two reasons: first we have a visited array which is
    // M*N, and we also have that the recursive call stack could be M*N in the
    // case that the grid is all 1s.
    int numIslandsV2(vector<vector<char>> &grid)
    {
        // would check if grid truly is a rectangular grid
        int m = grid.size();
        int n = grid[0].size();
        int num_islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // how to initialize to false with size?
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    num_islands++;
                    visit_island(i, j, visited, grid); // pass by ref grid
                }
            }
        }
        return num_islands;
    }
    void visit_island(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        int m = visited.size();
        int n = visited[0].size();
        if (i < 0 || i >= m)
            return;
        if (j < 0 || j >= n)
            return;
        // check if i and j are inside visited's bounds
        if (visited[i][j])
            return;
        if (grid[i][j] == '0')
            return;
        visited[i][j] = true; // lol forgot this
        // up

        visit_island(i - 1, j, visited, grid);
        // down
        visit_island(i + 1, j, visited, grid);
        // left
        visit_island(i, j - 1, visited, grid);
        // right
        visit_island(i, j + 1, visited, grid);
    }
};