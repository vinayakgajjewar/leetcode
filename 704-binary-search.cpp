#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int search(vector<int> &nums, int target) {

        /*
         * Maintain pointers to the first and last element of the array. If the
         * middle element is greater than the target, that element becomes the
         * new last pointer. If the middle element is less than the target, that
         * element becomes the new first pointer. If it is the target, just
         * return its index. Then rinse and repeat until they point to the same
         * element, in which case return -1.
         */

        int lower_bound_index = 0;
        int upper_bound_index = static_cast<int>(nums.size()) - 1;

        /*
         * This has to be a do-while loop because of the case where the vector
         * only has a single element.
         */
        do {

            /*
             * We must check the values at the bounds first.
             */
            if (nums[lower_bound_index] == target) return lower_bound_index;
            if (nums[upper_bound_index] == target) return upper_bound_index;

            /*
             * Integer division will take care of even-length vectors.
             */
            int middle_index = (lower_bound_index + upper_bound_index) / 2;
            int middle_value = nums[middle_index];
            if (middle_value == target) return middle_index;
            else if (middle_value < target) lower_bound_index = middle_index;
            else upper_bound_index = middle_index;
        } while (upper_bound_index - lower_bound_index > 1);
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << s.search(nums, target) << endl;
    target = 2;
    cout << s.search(nums, target) << endl;
}