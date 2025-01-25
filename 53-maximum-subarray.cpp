#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxSubArray(vector<int> &nums) {

        /*
         * Keep track of the maximum subarray that ends at the current index. At
         * each step, update the current maximum based on whether adding the
         * current number improves the subarray sum.
         */
        int current_max_sum = 0;
        int best_max_sum = INT_MIN;
        for (int curr_num: nums) {
            current_max_sum = max(curr_num, current_max_sum + curr_num);
            best_max_sum = max(best_max_sum, current_max_sum);
            cout << "Current element: " << curr_num << endl;
            cout << "\tCurrent maximum sum: " << current_max_sum << endl;
            cout << "\tBest maximum sum: " << best_max_sum << endl;
        }
        cout << "Done looping, returning " << best_max_sum << endl;
        return best_max_sum;
    }
};

int main() {
    vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = Solution::maxSubArray(array);
    cout << "Maximum subarray sum: " << max_sum << endl;
}