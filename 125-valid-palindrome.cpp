#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // First we have to make everything lowercase and remove all non-alphanumeric characters.
        // Then, we have to check if the resulting string is a palindrome.
        // Maintain pointers to the very first and the very last character.
        // Check if the characters are the same and then move them towards the middle.
        // We're done when the indexes are the same or when left index > right index.

        string processed_string;
        for (char c: s) {
            if (isalnum(c)) {
                processed_string += tolower(c);
            }
        }

        int left_index = 0;
        int right_index = processed_string.size() - 1;
        while (left_index < right_index) {
            if (processed_string[left_index] != processed_string[right_index]) return false;
            ++left_index;
            --right_index;
        }
        return true;
    }
};