#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    /*
     * The intuition here is to construct an unordered map where the keys are the
     * sorted versions of strings and the values are all the permutations of that
     * key that appear in the input.
     *
     * Notice how to sort a string in C++!
     */
    static vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string &s: strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].push_back(s);
        }
        vector<vector<string>> grouped_anagrams;
        grouped_anagrams.reserve(anagrams.size());
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