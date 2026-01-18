/*
 * 128-longest-consecutive-sequence.cpp
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 */

#include <set>
#include <vector>

using namespace std;

class Solution {
public:

    /*
     * This is the naive solution that runs in O(N log N) because it uses a
     * sorting algorithm.
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
};