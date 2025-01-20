#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
        {
            return image;
        }
        int startingColor = image[sr][sc];
        vector<vector<int>> visitedCoordinates;
        vector<vector<int>> toVisit = {};
        toVisit.push_back({sr, sc});
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!toVisit.empty())
        {
            vector<int> currentCoords = toVisit.back();
            toVisit.pop_back();
            int currentRow = currentCoords[0];
            int currentCol = currentCoords[1];

            // Change the color
            image[currentRow][currentCol] = color;

            visitedCoordinates.push_back({currentRow, currentCol});

            // Populate the toVisit list
            for (vector<int> direction : directions)
            {
                int newRow = currentRow + direction[0];
                int newColumn = currentCol + direction[1];

                // Check if we're going off the sides
                if (newRow >= image.size() || newRow < 0)
                    continue;
                if (newColumn >= image[0].size() || newColumn < 0)
                    continue;

                if (image[newRow][newColumn] != startingColor)
                    continue;

                // Check that we aren't visiting a square twice
                int visited = 0;
                for (auto it = visitedCoordinates.begin(); it != visitedCoordinates.end(); it++)
                {
                    if ((*it)[0] == newRow && (*it)[1] == newColumn)
                        visited = 1;
                    break;
                }
                if (!visited)
                {
                    toVisit.push_back({newRow, newColumn});
                }
            }
        }
        return image;
    }
};