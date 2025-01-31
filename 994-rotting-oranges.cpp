#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static int orangesRotting(vector<vector<int>> &grid) {

        /*
         * For each fresh orange, we want its minimum distance to a rotten
         * orange. This minimum distance must pass through other fresh oranges
         * only. We want the maximum across all fresh oranges of this minimum
         * distance. Maintain a grid of minimum distances from a rotten orange.
         * Oranges that are already rotten have a distance of 0. Perform BFS
         * starting from each rotten orange.
         */

        int num_rows = grid.size();
        int num_cols = grid[0].size();

        queue<pair<int, int>> work_queue;
        vector<vector<int>> min_distances(num_rows, vector<int>(num_cols, INT_MAX));

        /*
         * Initialize the distance of each rotten orange to 0 and add it to our
         * work queue.
         */
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (grid[i][j] == 2) {
                    min_distances[i][j] = 0;
                    work_queue.push(make_pair(i, j));
                }
            }
        }

        vector<pair<int, int>> directions = {{0,  1},
                                             {0,  -1},
                                             {1,  0},
                                             {-1, 0}};

        /*
         * It's time to do BFS.
         */
        while (!work_queue.empty()) {
            pair<int, int> curr_cell = work_queue.front();
            int curr_cell_dist = min_distances[curr_cell.first][curr_cell.second];
            work_queue.pop();

            /*
             * Look at each fresh orange that borders this cell and update its
             * distance to (1 +  the current cell's distance) if that value is
             * less than its current distance.
             */
            for (pair<int, int> direction: directions) {
                int new_cell_row = curr_cell.first + direction.first;
                int new_cell_col = curr_cell.second + direction.second;

                /*
                 * Don't forget to check if we're off the grid.
                 */
                if (new_cell_row < 0 || new_cell_row >= num_rows) continue;
                if (new_cell_col < 0 || new_cell_col >= num_cols) continue;

                /*
                 * Skip if this isn't a fresh orange.
                 */
                if (grid[new_cell_row][new_cell_col] != 1) continue;
                if (1 + curr_cell_dist < min_distances[new_cell_row][new_cell_col]) {
                    min_distances[new_cell_row][new_cell_col] = 1 + curr_cell_dist;
                    work_queue.push(make_pair(new_cell_row, new_cell_col));
                }
            }
        }

        /*
         * Once BFS terminates, we must return the largest distance or -1 if a
         * fresh orange's distance is still INT_MAX.
         */
        int max_distance = INT_MIN;
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (grid[i][j] != 1) continue;
                if (min_distances[i][j] == INT_MAX) return -1;
                max_distance = max(max_distance, min_distances[i][j]);
            }
        }

        /*
         * Capture the edge case when there aren't any fresh oranges.
         */
        if (max_distance == INT_MIN) max_distance = 0;
        return max_distance;
    }
};

int main() {
    vector<vector<int>> input1 = {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}
    };
    int output1 = Solution::orangesRotting(input1);
    cout << output1 << endl;
}