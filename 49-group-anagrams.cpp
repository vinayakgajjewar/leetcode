#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<string>> groupAnagrams(vector<string> &strs) {
        /*
         * Making a vector of frequency tables is the wrong approach here. We
         * can make a hash table where keys are the sorted versions of anagrams
         * and the values are the unsorted versions we've seen.
         */
        unordered_map<string, vector<string>> anagrams;
        for (string &s: strs) {
            string sorted = s;

            /*
             * This is a nifty way to sort the characters in a string! std::sort
             * runs in O(n log_2 n).
             */
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].push_back(s);
        }
        vector<vector<string>> grouped_anagrams;
        for (auto &[key, value]: anagrams) {
            grouped_anagrams.push_back(value);
        }
        return grouped_anagrams;
    }
};

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> output = Solution::groupAnagrams(input);
    for (vector<string> &group: output) {
        for (string &str: group) cout << str << " ";
        cout << endl;
    }
}