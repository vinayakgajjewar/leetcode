#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int> &nums) {

        /*
         * I initially thought that the solution to this problem was to use an
         * unordered map, but this is really a two pointer problem. The time
         * complexity of this solution is O(n^2).
         */

        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size - 2; ++i) {

            /*
             * Keep incrementing i until we hit a different value to avoid
             * duplicates.
             */
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = size - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    ++j;

                    /*
                     * Keep incrementing j until we hit a different value to
                     * avoid duplicates.
                     */
                    while (nums[j] == nums[j - 1] && j < k) {
                        ++j;
                    }
                } else if (sum < 0) {
                    /*
                     * If the sum is less than 0, we can get closer by
                     * incrementing j.
                     */
                    ++j;
                } else {
                    /*
                     * If the sum is greater than 0, we can get closer by
                     * decrementing k.
                     */
                    --k;
                }
            }
        }
        return triplets;
    }
};