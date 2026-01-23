/*
 * 79-word-search.cpp
 *
 * https://leetcode.com/problems/word-search/
 */

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*
 * This is the tricky part of this problem: you need to erase the current cell
 * from the visited set after you do DFS on all the neighbors. This is the essence
 * of backtracking!
 *
 * Note also that it is necessary to reverse the word if the last letter of the
 * word is less common than the first letter of the word. LeetCode will give you
 * a "Time Limit Exceeded" otherwise.
 *
 * Also note how the lambda capture is used here to avoid making another function
 * with a bunch of parameters to pass in.
 */
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int rows = (int) board.size();
        int cols = (int) board[0].size();
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