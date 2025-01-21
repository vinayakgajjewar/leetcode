#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_window_size = 0;

        /*
         * Iterate through each possible character and, for each one, use the
         * sliding window technique.
         */
        for (char c = 'A'; c <= 'Z'; ++c) {
            int left = 0;
            int right = 0;
            int num_replaced = 0;
            while (right < s.size()) {

                /*
                 * If the character at the right is our current character, we
                 * can make the window bigger.
                 */
                if (s[right] == c) ++right;

                    /*
                     * If it doesn't match our current character, but we still have
                     * some replacements left, we can make the window bigger by
                     * using a replacement.
                     */
                else if (num_replaced < k) {
                    ++right;
                    ++num_replaced;
                }

                    /*
                     * If we're all out of replacements but the leftmost character
                     * in our window is a replacement, kick it out of our window,
                     * giving us an extra replacement.
                     */
                else if (s[left] != c) {
                    ++left;
                    --num_replaced;
                }

                    /*
                     * If all else fails, make progress by kicking a matching
                     * character out of our window.
                     */
                else {
                    ++left;
                }

                /*
                 * Keep track of the biggest window we've made.
                 */
                max_window_size = max(max_window_size, right - left);
            }
        }
        return max_window_size;
    }
};