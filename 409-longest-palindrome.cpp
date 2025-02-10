#include <string>

using namespace std;

class Solution {
public:
    static int longestPalindrome(string &s) {

        /*
         * In order to build palindromes with length longer than 1, we need to
         * find pairs of identical characters. We can build a hash table of
         * character frequencies. Add even-length character frequencies directly
         * to the length of our longest palindrome. Subtract 1 from odd
         * character frequencies and add them to the length. If we see at least
         * 1 odd frequency, we can put that character in the middle to create
         * an odd-length palindrome.
         */

        /*
         * Handle the trivial case.
         */
        if (s.size() == 1) return 1;

        std::unordered_map<char, int> char_freqs;
        for (char c: s) {
            ++char_freqs[c];
        }

        bool odd_length_palindrome = false;
        int max_length = 0;
        for (auto &[c, freq]: char_freqs) {
            if (freq % 2 == 0) {
                max_length += freq;
            } else {
                max_length += freq - 1;
                odd_length_palindrome = true;
            }
        }
        if (odd_length_palindrome) ++max_length;
        return max_length;
    }
};

int main() {
    string input1 = "abccccdd";
    int output1 = Solution::longestPalindrome(input1);
    assert(output1 == 7);
}