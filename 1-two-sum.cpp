#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSumNaive(vector<int> &nums, int target) {
        // Maintain two iterators
        // How do I do this in less than O(n^2)?
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                if (nums[i] + nums[j] == target) return {i, j};
            }
        }

        // We can assume that each input has exactly one solution, but I am
        // principled.
        return {};
    }

    vector<int> twoSumHashTable(vector<int> &nums, int target) {

        // The key is the number and the value is its index.
        unordered_map<int, int> indexes_of_nums;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (indexes_of_nums.find(complement) != indexes_of_nums.end()) {
                return {i, indexes_of_nums[complement]};
            }
            indexes_of_nums[nums[i]] = i;
        }

        // A solution is guaranteed to exist, but still.
        return {};
    }
};