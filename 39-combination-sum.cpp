/*
 * 39-combination-sum.cpp
 *
 * https://leetcode.com/problems/combination-sum/description/
 */

#include <vector>

using namespace std;

/*
 * This solution is a bit slower because we recompute the sum of the current
 * combination from scratch each time, but it is easier to understand.
 *
 * Note that the first recursive call corresponds to trying to add the same number
 * again, and the second recursive call corresponds to trying to add the next
 * candidate number.
 */
class Solution_slower {
public:
    int sum(vector<int> &combo) {
        int sum = 0;
        for (int val: combo) {
            sum += val;
        }
        return sum;
    }

    void make_combos(const vector<int> &candidates, int target, vector<int> curr_combo, int curr_index,
                     vector<vector<int>> &curr_result) {
        int curr_total = sum(curr_combo);
        if (curr_total == target) {
            curr_result.push_back(curr_combo);
            return;
        }
        if (curr_total > target) return;
        if (curr_index >= candidates.size()) return;

        int curr_num = candidates[curr_index];
        curr_combo.push_back(curr_num);
        make_combos(candidates, target, curr_combo, curr_index, curr_result);
        curr_combo.pop_back();
        make_combos(candidates, target, curr_combo, curr_index + 1, curr_result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> curr_result;
        vector<int> curr_combo;
        int curr_index = 0;
        make_combos(candidates, target, curr_combo, curr_index, curr_result);
        return curr_result;
    }
};

/*
 * Base cases:
 * - The current total is equal to the target
 * - The current total is greater than the target
 * - We've reached the end of the candidate array
 *
 * Note that we could recalculate the current total each time, but passing it in
 * as a parameter is more efficient.
 */
class Solution {
public:
    void make_combination(vector<int> &candidates, int target, int curr_idx, vector<int> &combination, int total,
                          vector<vector<int>> &result) {
        if (total == target) {
            result.push_back(combination);
            return;
        }
        if (total > target || curr_idx >= candidates.size()) {
            return;
        }

        int curr_num = candidates[curr_idx];
        combination.push_back(curr_num);
        make_combination(candidates, target, curr_idx, combination, total + curr_num, result);
        combination.pop_back();
        make_combination(candidates, target, curr_idx + 1, combination, total, result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        int curr_total = 0;
        int curr_idx = 0;
        vector<int> combination;
        make_combination(candidates, target, curr_idx, combination, curr_total, result);
        return result;
    }
};