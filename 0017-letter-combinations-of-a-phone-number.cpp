#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    // according to neetcode, the time complexity is O(N * 4^N) where N is the
    // length of digits, but I do not quite understand why. Maybe because it is
    // some sort of decision tree?
    vector<string> letterCombinations(string digits)
    {

        // trivial case
        if (digits.empty())
            return {};

        // the index is the digit and the value is the set of possible letters.
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> letter_combos;
        backtrack(0, digits, "", map, letter_combos);
        return letter_combos;
    }
    void backtrack(int i, const string &digits, const string &curr_str, const vector<string> &map,
                   vector<string> &letter_combos)
    {
        if (curr_str.size() == digits.size())
        {
            letter_combos.push_back(curr_str);
        }
        else
        {
            // note how i convert from char to num easily
            for (const char &c : map.at(digits.at(i) - '0'))
            {

                // todo: can i append a char to a string like this?
                string new_str = curr_str + c;
                backtrack(i + 1, digits, new_str, map, letter_combos);
            }
        }
    }

    // This is the iterative version of the solution. Note how this solution
    // uses a temp list to generate all possible strings. I guess this solution
    // also makes it easier to see why the runtime complexity could be O(N *
    // 4^N). I definitely need to practice this pattern a lot more.
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // need to start with empty string!
        vector<string> combos = {""};
        for (char digit : digits)
        {
            vector<string> temp;
            for (string &s : combos)
            {
                for (char c : map.at(digit - '0'))
                {
                    temp.push_back(s + c);
                }
            }
            combos = temp;
        }
        return combos;
    }

    vector<string> letterCombinations(string digits)
    {
        // im going to attempt to do this the iterative way, which apparently
        // has a runtime complexity of O(n * 4^n). the gist of the solution is
        // to, for each digit in digits, for each current combination, append
        // each possible letter for that digit. you can use a temp list to do
        // this cleanly. apparently the key to understanding the time complexity
        // is to realize that the number of combinations grows exponentially as
        // you add more digits.
        if (digits.empty())
            return {};

        // note the initial string
        vector<string> combos = {""};

        // clever way of mapping where the key is the index into the vector
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // this is the loop that's O(n)
        for (char digit : digits)
        {
            vector<string> temp;

            // populate the temp vector using the current set of combos
            for (string combo : combos)
            {
                for (char c : mapping[digit - '0'])
                {
                    temp.push_back(combo + c);
                }
            }
            combos = temp;
        }
        return combos;
    }
};