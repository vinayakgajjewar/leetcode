#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {

        /*
         * My initial idea to sort the array first was dead wrong.
         */

        int lower_bound_index = 0;
        int upper_bound_index = nums.size() - 1;
        while (lower_bound_index <= upper_bound_index) {
            int middle_index = (lower_bound_index + upper_bound_index) / 2;
            if (nums[lower_bound_index] == target) return lower_bound_index;
            if (nums[middle_index] == target) return middle_index;
            if (nums[lower_bound_index] > nums[middle_index]) {

                /*
                 * If our lower bound is greater than our middle value, our
                 * range contains the pivot point, and we have to make progress
                 * by incrementing our lower bound.
                 */
                ++lower_bound_index;
            } else if (nums[middle_index] < target) {

                /*
                 * This part is just like normal binary search.
                 */
                lower_bound_index = middle_index + 1;
            } else if (nums[lower_bound_index] < target) {

                /*
                 * If our lower bound is less than the target and the middle
                 * index is greater than the target, we know that our window
                 * doesn't contain the pivot point, so we can safely cut the
                 * window in half.
                 */
                upper_bound_index = middle_index - 1;
            } else {

                /*
                 * Same logic as above, but in the other direction.
                 */
                lower_bound_index = middle_index + 1;
            }
        }
        return -1;
    }
};