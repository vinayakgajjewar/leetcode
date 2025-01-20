#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        // It's a good idea to pull these values out at the very start.
        int m = mat.size();
        int n = mat[0].size();
        
        // Do BFS starting from all the 0 cells. The pair data structure is useful for storing coordinates.
        queue<pair<int, int>> cellsToVisit = {};

        // This is a cool way to initialize a vector with default values. We have to set it to INT_MAX because we're minimizing these values.
        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));

        // Loop through the matrix and set the distance of each 0 value to 0. Also add the 0 cells to our queue.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    distances[i][j] = 0;
                    cellsToVisit.push({i, j});
                }
            }
        }

        // Define directions of travel.
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Do breadth-first search.
        while (!cellsToVisit.empty())
        {

            // Gotta remember that this is two steps.
            pair<int, int> currentCell = cellsToVisit.front();
            cellsToVisit.pop();

            // Look at each cell that borders this one.
            for (pair<int, int> direction : directions)
            {
                pair<int, int> newCell = {currentCell.first + direction.first, currentCell.second + direction.second};

                // Check that we aren't off the edge. Remember that m and n and sizes, so we have to check if the coordinates are >= to them.
                if (newCell.first < 0 || newCell.first >= m)
                    continue;
                if (newCell.second < 0 || newCell.second >= n)
                    continue;

                if (distances[newCell.first][newCell.second] > distances[currentCell.first][currentCell.second] + 1)
                {
                    distances[newCell.first][newCell.second] = distances[currentCell.first][currentCell.second] + 1;
                    cellsToVisit.push(newCell);
                }
            }
        }

        // When the work queue is empty, return our answer.
        return distances;
    }
};