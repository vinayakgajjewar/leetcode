#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        // We need to return all the grid coordinates that can flow to both the
        // Pacific and the Atlantic Ocean. We know we're flowing into the
        // Atlantic Ocean if we're going off the right (col >= num_cols) or if
        // we're going off the bottom (row >= num_rows). Maybe the way to go
        // about this is to start at the edges and simulate water flowing
        // uphill. The water has to strictly flow uphill, though. We maintain a
        // grid that keeps track of whether a particular cell is reachable from
        // which ocean.

        int num_rows = heights.size();
        int num_cols = heights[0].size();
        // The first value denotes if this cell is reachable from the Pacific.
        // The second value denotes if this cell is reachable from the
        // Atlantic.
        vector<vector<pair<bool, bool>>> reachable(num_rows,
                                                   vector<pair<bool, bool>>(num_cols, make_pair(false, false)));
        queue<pair<int, int>> work_queue;

        // Add all the nodes on the edges to the work queue. We'll do it on an
        // ocean-by-ocean basis.
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (i == 0 || j == 0 || i == num_rows - 1 || j == num_cols - 1) {
                    work_queue.push(make_pair(i, j));
                }
                if (i == 0 || j == 0) {
                    reachable[i][j].first = true;
                }
                if (i == num_rows - 1 || j == num_cols - 1) {
                    reachable[i][j].second = true;
                }
            }
        }
        vector<pair<int, int>> directions = {{0,  1},
                                             {0,  -1},
                                             {1,  0},
                                             {-1, 0}};
        while (!work_queue.empty()) {
            int curr_cell_row = work_queue.front().first;
            int curr_cell_col = work_queue.front().second;
            work_queue.pop();
            bool curr_cell_reachable_from_pacific = reachable[curr_cell_row][curr_cell_col].first;
            bool curr_cell_reachable_from_atlantic = reachable[curr_cell_row][curr_cell_col].second;
            int curr_cell_height = heights[curr_cell_row][curr_cell_col];

            // We need to add cells that are strictly uphill from us.
            for (pair<int, int> direction: directions) {
                int new_cell_row = curr_cell_row + direction.first;
                int new_cell_col = curr_cell_col + direction.second;
                if (new_cell_row < 0 || new_cell_row >= num_rows) continue;
                if (new_cell_col < 0 || new_cell_col >= num_cols) continue;
                int new_cell_height = heights[new_cell_row][new_cell_col];
                if (curr_cell_height > new_cell_height) continue;
                bool add_new_to_queue = false;
                if (curr_cell_reachable_from_pacific && !reachable[new_cell_row][new_cell_col].first) {
                    reachable[new_cell_row][new_cell_col].first = true;
                    add_new_to_queue = true;
                }
                if (curr_cell_reachable_from_atlantic && !reachable[new_cell_row][new_cell_col].second) {
                    reachable[new_cell_row][new_cell_col].second = true;
                    add_new_to_queue = true;
                }

                /*
                 * Remember to only push to the work queue if we made an update.
                 */
                if (add_new_to_queue) work_queue.push(make_pair(new_cell_row, new_cell_col));
            }
        }

        // Once BFS terminates, iterate through reachable and collect all the
        // cells that are reachable by both oceans.
        vector<vector<int>> reachable_by_both;
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (reachable[i][j].first && reachable[i][j].second) {
                    reachable_by_both.push_back({i, j});
                }
            }
        }
        return reachable_by_both;
    }
};

int main() {
    vector<vector<int>> input1 = {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
    };
    vector<vector<int>> output1 = Solution::pacificAtlantic(input1);
}