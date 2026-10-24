#include <string>
#include <vector>

using namespace std;

// first did this on 19 oct 2026. this is a tough one! and i don't think i quite
// understand it fully yet.
class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {

        // todo: we can optimize this using memoization so we dont have to
        // repeatedly check if a substring is a palindrome

        // trivial cases
        if (s.empty())
            return {{}};
        if (s.size() == 1)
            return {{s}};

        vector<vector<string>> ret;
        vector<string> part;
        dfs(0, 0, s, part, ret);
        return ret;
    }

    void dfs(int start, int end, const string &s, vector<string> &part, vector<vector<string>> &ret)
    {

        // base case: we're done building the current partition, so add it to
        // the result.
        if (start == end && end == s.size())
        {
            ret.push_back(part);
            return;
        }

        // base case: if end falls off the end the string, end this recursion
        // branch.
        if (end == s.size())
        {
            return;
        }

        // if the current substring is a palindrome, do dfs on the remaining
        // string with part = part + {palindrome}.
        if (is_palindrome(s, start, end))
        {
            // note that substr takes a starting position and a count
            part.push_back(s.substr(start, end - start + 1));
            dfs(end + 1, end + 1, s, part, ret);

            // still not quite sure why we need to do this
            part.pop_back();
        }
        dfs(start, end + 1, s, part, ret);
    }

    bool is_palindrome(const string &s, int start, int end)
    {
        int l = start;
        int r = end;
        while (l < r)
        {
            if (s.at(l) != s.at(r))
                return false;
            l++;
            r--;
        }
        return true;
    }
};

// did this on 2026-10-20. i still don't quite have a complete intuition for
// this answer, and i still have not coded up the memoization optimization, but
// we're getting closer!
class Solution2
{
  public:
    vector<vector<string>> partition(string s)
    {
        // we can treat the string as a decision tree and use depth-first search
        // to explore all possible partitionings.
        vector<vector<string>> all_partitions;
        vector<string> curr_partition;
        recurse(s, 0, 0, curr_partition, all_partitions);
        return all_partitions;
    }

    void recurse(const string &s, int start, int end, vector<string> &curr_partition,
                 vector<vector<string>> &all_partitions)
    {

        // base case: if start and end are off the end of s, the current
        // partition is done, so add it to the answer.
        if (start == end && end == s.size())
        {
            all_partitions.push_back(curr_partition);
            return;
        }

        // base case: if end is off the end of s, end this recursive chain
        if (end == s.size())
            return;

        // if start and end define a palindrome, start a new recursive chain
        // with it temporarily added to the current partition
        if (palindrome(s, start, end))
        {
            curr_partition.push_back(s.substr(start, end - start + 1));
            recurse(s, end + 1, end + 1, curr_partition, all_partitions);
            curr_partition.pop_back();
        }

        // explore the case where we expand end.
        recurse(s, start, end + 1, curr_partition, all_partitions);
    }

    // start and end are inclusive and we'll assume the bounds are valid. it's
    // bad practice to modify parameters but whatever.
    bool palindrome(const string &s, int start, int end)
    {
        while (start < end)
        {
            if (s.at(start) != s.at(end))
                return false;
            start++;
            end--;
        }
        return true;
    }
};