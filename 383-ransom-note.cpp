#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        /*
         * For the magazine, we only care about the letters it uses and the
         * frequencies of those letters. Iterate through the magazine and
         * populate a hash table (std::unordered_map) of letters and
         * frequencies. Do the same for the ransom note. Iterate through each
         * key for the ransom note and check if the frequency in the magazine is
         * greater than or equal to the frequency in the note.
         */

        unordered_map<char, int> ransom_note_frequencies;
        for (char c: ransomNote) {
            ++ransom_note_frequencies[c];
        }

        unordered_map<char, int> magazine_frequencies;
        for (char c: magazine) {
            ++magazine_frequencies[c];
        }

        /*
         * We need to be using C++ 17 or greater for this to work.
         */
        for (const auto &[letter, ransom_frequency]: ransom_note_frequencies) {

            /*
             * If the letter doesn't exist in the magazine, this still works.
             */
            if (ransom_frequency > magazine_frequencies[letter]) return false;
        }
        return true;
    }
};