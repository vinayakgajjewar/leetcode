#include <vector>

using namespace std;

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // [m-1][n-1] is 1 unless it is an obstacle. cannot just fill in bottom
        // and right edges with 1; might be 0. can treat cells to top and left
        // of obstacle like they are boundary cells for each (non-obstacle)
        // cell, there are 4 cases:
        // - both bottom and right are possible (add them together)
        // - only bottom is possible (obstacle or edge) (propagate right val)
        // - only right is possible (obstacle or edge) (propagate bottom val)
        // - neither bottom or right are possible

        // trivial
        if (obstacleGrid[0][0] == 1)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        // it shouldnt matter what we initialize this to bc be handle all cases.
        // for this problem, it has to be unsigned long longs, not ints because
        // of the magnitudes involved.
        vector<vector<unsigned long long>> paths(m, vector<unsigned long long>(n, 1));
        paths[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {

                // silly coding bug: forgot to preserve the 1 in the ending
                // position even though you technically cannt go anywhere from
                // there!
                if (i == m - 1 && j == n - 1)
                    continue;

                // handle case where you cant go down or right
                if ((i == m - 1 || obstacleGrid[i + 1][j] == 1) && (j == n - 1 || obstacleGrid[i][j + 1] == 1))
                {
                    paths[i][j] = 0;
                    continue;
                }

                // handle case where you cannot go down but you can go right.
                if (i == m - 1 || obstacleGrid[i + 1][j] == 1)
                {
                    paths[i][j] = paths[i][j + 1];
                    continue;
                }

                // handle case where you cant go right but you can go down.
                if (j == n - 1 || obstacleGrid[i][j + 1] == 1)
                {
                    paths[i][j] = paths[i + 1][j];
                    continue;
                }

                // handle case where you can go either.
                paths[i][j] = paths[i + 1][j] + paths[i][j + 1];
            }
        }
        return paths[0][0];
    }
};