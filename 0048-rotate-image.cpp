#include <vector>

using namespace std;

// This is my solution from 2026-11-15. Note that you can do a lot of different
// combinations of rotate-and-transpose, but you have to realize that
// transposing by flipping i and j is the easiest to implement, which requires
// flipping vertically first. The time complexity is O(n^2) and the space
// complexity is O(1).
class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        int m = matrix.size();    // num rows
        int n = matrix[0].size(); // num cols

        // step 1: flip vertically. you only have to iterate through the top
        // half of the matrix to do this. note how you have to divide by 2.0 to
        // force double division because it will do integer division if you just
        // divide by 2.
        for (int i = 0; i < (m - 1) / 2.0; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // swap (i, j) with (m-1-i, j)
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m - i - 1][j];
                matrix[m - 1 - i][j] = temp;
            }
        }

        // step 2: transpose. to transpose, you just need to swap i and j. you
        // should only iterate through the upper-right triangle of the matrix to
        // do this, which corresponds to all the coordinates where i < j.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= j)
                    continue;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};