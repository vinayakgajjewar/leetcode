#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // We are only asked to find the LENGTH of the longest substring.
        // Idea: at each index of the string, find the longest substring ending at that index that includes that index.
        // Keep track of the length of the longest substring we've seen so far.

        // Handle trivial cases.
        if (s.size() == 0 || s.size() == 1) return s.size();

        int longest_seen_so_far = 0;

        // At each index i, find the longest substring that ends at i.
        for (int i = 0; i < s.size(); ++i) {
            vector<char> seen_chars;

            // Construct the longest non-repeating substring that ends at i.
            for (int j = i; j >= 0; j--) {
                if (find(seen_chars.begin(), seen_chars.end(), s[j]) == seen_chars.end()) {
                    seen_chars.push_back(s[j]);
                } else {
                    break;
                }
            }
            longest_seen_so_far = max(static_cast<int>(seen_chars.size()), longest_seen_so_far);
        }
        return longest_seen_so_far;
    }
};