/*
 * 198-house-robber.cpp
 *
 * https://leetcode.com/problems/house-robber/
 *
 * This is a dynamic programming problem. We iterate through each house from
 * left to right. At each house, we calculate the maximum profit that we can
 * make at that house, by calculating (1) the max profit we make if we do rob
 * the house and (2) the max profit we make if we do NOT rob the house. The max
 * profit of the rightmost house is the solution to the problem.
 *
 * TODO
 * There is an optimization to be made here, where you don't need to store the
 * entire array of max values. You only need the max values of the previous two
 * houses.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int rob_impl(vector<int> &max_at_house, int house, const vector<int> &house_values) {
        if (house == 0)
            return house_values.at(0);

        if (house == 1) {
            return max(house_values[0], house_values[1]);
        }

        int max_if_robbed = house_values[house] + max_at_house[house - 2];
        int max_if_not_robbed = max_at_house[house - 1];
        return max(max_if_robbed, max_if_not_robbed);
    }

    int rob(vector<int> &nums) {

        vector<int> max_at_house(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            max_at_house[i] = rob_impl(max_at_house, i, nums);
        }
        return max_at_house[nums.size() - 1];
    }
};