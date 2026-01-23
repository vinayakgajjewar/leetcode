/*
 * 79-word-search.cpp
 *
 * https://leetcode.com/problems/word-search/
 */

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // this is what tripped me up: you need to erase the current cell from the visited set!
    // also: this is cool that you can use lambda captures "[&]" to capture all the variables
    // also: it is necessary to implement the optimization to reverse the word if
    // the end letter is less common than the first letter to get this to pass
    // on leetcode.
    bool exist(vector<vector<char>> &board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        unordered_set<string> visited;
        auto dfs = [&](int r, int c, int i, auto &dfs) -> bool {
            if (i == word.length()) return true;
            if (r < 0 || r >= rows) return false;
            if (c < 0 || c >= cols) return false;
            if (visited.contains(to_string(r) + "," + to_string(c))) return false;
            if (board[r][c] != word.at(i)) return false;
            visited.insert(to_string(r) + "," + to_string(c));
            if (dfs(r + 1, c, i + 1, dfs)) return true;
            if (dfs(r - 1, c, i + 1, dfs)) return true;
            if (dfs(r, c + 1, i + 1, dfs)) return true;
            if (dfs(r, c - 1, i + 1, dfs)) return true;
            // this is necessary for backtracking!!!!
            visited.erase(to_string(r) + "," + to_string(c));
            return false;
        };

        unordered_map<char, int> count;
        for (char c: word) {
            count[c]++;
        }

        if (count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0, dfs)) return true;
            }
        }
        return false;
    }
};