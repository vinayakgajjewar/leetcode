/*
 * 128-longest-consecutive-sequence.cpp
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 */

#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    /*
     * This is the naive solution that runs in O(N log N) because it uses a
     * sorting algorithm. This solution does give us the basic pattern for finding
     * the length of the longest consecutive sequence once we have a sorted unique
     * vector, though.
     */
    int longestConsecutive_naive(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 0) return 0;

        set<int> unique_set(nums.begin(), nums.end());
        vector<int> unique(unique_set.begin(), unique_set.end());
        sort(unique.begin(), unique.end());
        vector<int> counts;
        int count = 0;
        for (int i = 0; i < unique.size(); i++) {
            count++;
            counts.push_back(count);
            if (i == unique.size() - 1) break;
            if (unique[i + 1] != unique[i] + 1) count = 0;
        }
        int max_count = 0;
        for (int c: counts) {
            max_count = max(c, max_count);
        }
        return max_count;
    }

    /*
     * This is the better solution that runs in O(N) because the input array does
     * not need to be sorted. The intuition here is that we improve upon the naive
     * solution by, for each unique number that is the start of a new sequence,
     * keep looking for the number that is 1 greater, then 2 greater, and so on.
     * This solution also does not need to store an entire array of count values
     * and just keeps track of the longest one seen so far.
     */
    int longestConsecutive_better(vector<int> &nums) {
        int n = (int) nums.size();
        if (n == 0) return 0;
        unordered_set<int> unique(nums.begin(), nums.end());
        int count = 0;
        int longest_count = 0;
        for (int num: unique) {
            if (unique.contains(num - 1)) continue;
            count = 0;
            while (unique.contains(num + count)) {
                count++;
            }
            if (longest_count < count) longest_count = count;
        }
        return longest_count;
    }
};