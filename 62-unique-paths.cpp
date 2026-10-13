#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        // at each cell, you have 2 choices: go down, or go right, respecting
        // grid constraints. its only when you can do both that you actually
        // have a choice. if you're at a cell that can do both, add them up. if
        // you're at a cell that can only do one, just propagate that number.
        // observation: if a cell is on the bottom or right edges, it will
        // always be 1! this soln is O(M*N) time and space complexity.

        // todo: apparently there is a way to optimize the space complexity
        // because you only need the current row and the row below you.

        // uniq_paths[m-1][n-1] = 1. fill in dp table from bottom right (2
        // loops, O(m*n)). return [0][0].

        // trivial: if we get past this, m>=2 and n>=2
        if (m == 1 || n == 1)
            return 1;

        // todo look up cpp vector initialization shortcut
        vector<vector<int>> uniq_paths(m, vector<int>(n, 1));

        // only looping through non-trivial (non-1) cells
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                uniq_paths[i][j] = uniq_paths[i][j + 1] + uniq_paths[i + 1][j];
            }
        }
        return uniq_paths[0][0];
    }
};