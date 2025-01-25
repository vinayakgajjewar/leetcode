#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> productExceptSelf(vector<int> &nums) {

        /*
         * Maintain additional data structures to cache the results of various
         * multiplications. One array will hold the products of all elements
         * before a given index. Another array will hold the products of all
         * elements after a given index. Then, we can just multiply the elements
         * at each index.
         */

        int n = static_cast<int>(nums.size());

        vector<int> products_before_index(n);
        int product_before_index = 1;
        for (int i = 0; i < n; ++i) {
            products_before_index[i] = product_before_index;
            product_before_index *= nums[i];
        }

        vector<int> products_after_index(n);
        int product_after_index = 1;
        for (int i = n - 1; i >= 0; --i) {
            products_after_index[i] = product_after_index;
            product_after_index *= nums[i];
        }

        vector<int> product_except_self(n);
        for (int i = 0; i < n; ++i) {
            product_except_self[i] = products_before_index[i] * products_after_index[i];
        }
        return product_except_self;
    }
};

void run_test(vector<int> &input) {
    vector<int> answer = Solution::productExceptSelf(input);
    for (int elem: answer) cout << elem << " ";
    cout << endl;
}

int main() {

    /*
     * Expected output: 24 12 8 6
     */
    vector<int> input1 = {1, 2, 3, 4};
    run_test(input1);

    /*
     * Expected output: 0 0 9 0 0
     */
    vector<int> input2 = {-1, 1, 0, -3, 3};
    run_test(input2);
}