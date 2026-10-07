#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    static int search(vector<int> &nums, int target)
    {

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
        do
        {

            /*
             * We must check the values at the bounds first.
             */
            if (nums[lower_bound_index] == target)
                return lower_bound_index;
            if (nums[upper_bound_index] == target)
                return upper_bound_index;

            /*
             * Integer division will take care of even-length vectors.
             */
            int middle_index = (lower_bound_index + upper_bound_index) / 2;
            int middle_value = nums[middle_index];
            if (middle_value == target)
                return middle_index;
            else if (middle_value < target)
                lower_bound_index = middle_index;
            else
                upper_bound_index = middle_index;
        } while (upper_bound_index - lower_bound_index > 1);
        return -1;
    }

    // This is my attempt from 2026/10/06. Note that in this one, I explicitly
    // take care of the case where the computed midpoint is either start or end.
    // Doing it this way is a clean way of making sure that we're handling
    // corner cases.
    int searchV2(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return 0;
            return -1;
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] == target)
                return start;
            if (nums[end] == target)
                return end;
            int midpoint = (start + end + 1) / 2; // why +1?
            if (midpoint == start || midpoint == end)
                return -1; // why ad
            // todo: handle case with 2 elems?
            if (nums[midpoint] == target)
                return midpoint;
            if (nums[midpoint] > target)
            {
                end = midpoint;
            }
            if (nums[midpoint] < target)
            {
                start = midpoint;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << s.search(nums, target) << endl;
    target = 2;
    cout << s.search(nums, target) << endl;
}