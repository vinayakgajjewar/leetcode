#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Check for an empty input.
        if (rows == 0 || cols == 0)
            return {};

        int currentTop = 0;
        int currentBottom = rows - 1;
        int currentLeft = 0;
        int currentRight = cols - 1;

        vector<int> spiralOrder;

        while (currentTop <= currentBottom && currentLeft <= currentRight)
        {

            // Go right along the top row.
            for (int col = currentLeft; col <= currentRight; col++)
            {
                spiralOrder.push_back(matrix[currentTop][col]);
            }
            currentTop++;

            // Go down along the right column.
            for (int row = currentTop; row <= currentBottom; row++)
            {
                spiralOrder.push_back(matrix[row][currentRight]);
            }
            currentRight--;

            // Check that we aren't done.
            if (currentTop > currentBottom)
                break;

            // Go left along the bottom row.
            for (int col = currentRight; col >= currentLeft; col--)
            {
                spiralOrder.push_back(matrix[currentBottom][col]);
            }
            currentBottom--;

            // Check again that we aren't done.
            if (currentLeft > currentRight)
                break;

            // Go up along the left column.
            for (int row = currentBottom; row >= currentTop; row--)
            {
                spiralOrder.push_back(matrix[row][currentLeft]);
            }
            currentLeft++;
        }

        // Return our result.
        return spiralOrder;
    }
};