#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
    // This is my old solution.
    int lengthOfLongestSubstring(string s)
    {
        // We are only asked to find the LENGTH of the longest substring. Idea:
        // at each index of the string, find the longest substring ending at
        // that index that includes that index. Keep track of the length of the
        // longest substring we've seen so far.

        // Handle trivial cases.
        if (s.size() == 0 || s.size() == 1)
            return s.size();

        int longest_seen_so_far = 0;

        // At each index i, find the longest substring that ends at i.
        for (int i = 0; i < s.size(); ++i)
        {
            vector<char> seen_chars;

            // Construct the longest non-repeating substring that ends at i.
            for (int j = i; j >= 0; j--)
            {
                if (find(seen_chars.begin(), seen_chars.end(), s[j]) == seen_chars.end())
                {
                    seen_chars.push_back(s[j]);
                }
                else
                {
                    break;
                }
            }
            longest_seen_so_far = max(static_cast<int>(seen_chars.size()), longest_seen_so_far);
        }
        return longest_seen_so_far;
    }

    // This is my new solution from 2026/10/05. The idea is that the window
    // always contains some substring without repeating characters. I believe
    // the runtime complexity is O(n) with a hash table and O(n^2) if you scan
    // the window. With a hash table, the space complexity is contant because
    // there is a constant number of unique characters to consider.
    int lengthOfLongestSubstringV2(string s)
    {
        if (s.empty())
            return 0;
        if (s.size() == 1)
            return 1;
        int start = 0;
        int end = 0;
        unordered_set<char> window;
        window.insert(s.at(start));
        int max_len = 1;
        while (end < s.size())
        {
            if (start == end && end < s.size() - 1 && s.at(end + 1) == s.at(end))
            {
                start++;
                end++;
            }
            else if (end < s.size() - 1 && !window.contains(s.at(end + 1)))
            {
                end++;
                window.insert(s.at(end));
                max_len = max({max_len, end - start + 1});
            }
            else if (start < end)
            {
                window.erase(s.at(start));
                start++;
            }
            else
            {
                return max_len;
            }
        }
        return max_len;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution sol;
    int res = sol.lengthOfLongestSubstringV2(s);
    std::cout << res << std::endl;
}