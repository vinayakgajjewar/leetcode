#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static string longestPalindrome(string s) {
        /*
         * TODO
         * There is a way to do this problem with dynamic programming. For
         * completeness, I should know that solution.
         */

        /*
         * For strings. length() and size() are the same thing.
         */
        if (s.size() <= 1) return s;

        string longest_palindrome;
        for (int i = 0; i < s.size(); ++i) {
            string odd_len = Solution::expand_from_center(s, i, i);

            /*
             * We don't have to worry about (i + 1) going out of bounds because
             * expand_from_center() takes care of that.
             */
            string even_len = Solution::expand_from_center(s, i, i + 1);
            if (odd_len.size() > longest_palindrome.size()) longest_palindrome = odd_len;
            if (even_len.size() > longest_palindrome.size()) longest_palindrome = even_len;
        }
        return longest_palindrome;
    }

private:
    static string expand_from_center(string s, int left_index, int right_index) {
        int curr_left = left_index;
        int curr_right = right_index;
        while (curr_left >= 0 && curr_right < s.size()) {
            if (s[curr_left] != s[curr_right]) break;
            --curr_left;
            ++curr_right;
        }
        /*
         * The characters at the ends don't match, so we have to strip them out
         * in our substring calculation.
         */
        return s.substr(curr_left + 1, curr_right - curr_left - 1);
    }
};

int main() {
    string test1 = "babad";
    string output1 = Solution::longestPalindrome(test1);
    cout << output1 << endl;
    string test2 = "cbbd";
    string output2 = Solution::longestPalindrome(test2);
    cout << output2 << endl;
}