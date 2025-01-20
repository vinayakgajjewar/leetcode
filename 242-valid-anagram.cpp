#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Anagrams have the same frequencies of the same letters.
        // Loop through each string and count the frequencies of each letter.
        // Store it in a hash table (unordered_map) for fast lookup.
        // Then, compare the hash tables.

        unordered_map<char, int> s_letter_frequencies;
        for (char c: s) {
            ++s_letter_frequencies[c];
        }

        unordered_map<char, int> t_letter_frequencies;
        for (char c: t) {
            ++t_letter_frequencies[c];
        }

        if (s_letter_frequencies == t_letter_frequencies) return true;
        else return false;
    }
};