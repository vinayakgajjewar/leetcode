/*
 * 213-house-robber-ii.cpp
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * This is essentially the same logic as #198: House Robber, but you need to
 * explicitly account for the fact that you can't rob both the first and the
 * last house. My original idea was to add a "ghost" house at the start, but
 * that ended up being more complex.
 *
 * Lessons:
 * - Don't forget about trivial cases!
 * - If it doesn't pass a test case, work out on pen/paper what your code would
 *   actually compute
 */

#include <vector>

using namespace std;

class Solution {
public:
    int calc_max_at_house(int i, const vector<int> &vals, const vector<int> &maxes) {
        if (i == 0) return vals[0];
        if (i == 1) return max(vals[1], maxes[0]);
        int max_if_robbed = vals[i] + maxes[i - 2];
        int max_if_spared = maxes[i - 1];
        int max_at_house = max(max_if_robbed, max_if_spared);
        return max_at_house;
    }

    int rob_helper(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> max_at_house(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            max_at_house[i] = calc_max_at_house(i, nums, max_at_house);
        }
        return max_at_house[nums.size() - 1];
    }

    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> without_last_house(nums.begin(), nums.end() - 1);
        vector<int> without_first_house(nums.begin() + 1, nums.end());
        return max(rob_helper(without_last_house), rob_helper(without_first_house));
    }
};