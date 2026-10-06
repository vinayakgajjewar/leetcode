#include <vector>

using namespace std;

class Solution
{
  public:
    static vector<vector<int>> threeSum(vector<int> &nums)
    {

        /*
         * I initially thought that the solution to this problem was to use an
         * unordered map, but this is really a two pointer problem. The time
         * complexity of this solution is O(n^2).
         */

        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size - 2; ++i)
        {

            /*
             * Keep incrementing i until we hit a different value to avoid
             * duplicates.
             */
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = size - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    ++j;

                    /*
                     * Keep incrementing j until we hit a different value to
                     * avoid duplicates.
                     */
                    while (nums[j] == nums[j - 1] && j < k)
                    {
                        ++j;
                    }
                }
                else if (sum < 0)
                {
                    /*
                     * If the sum is less than 0, we can get closer by
                     * incrementing j.
                     */
                    ++j;
                }
                else
                {
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
    // Attempt from 2026/10/06. The best thing to do is to sort the input array
    // and use a 3-pointer approach. Fix an i pointer and set j and k pointers.
    // Then, bump j if the sum is too small. Decrement k if the sum is too
    // large. Once i and j meet, go to a next i. In order to avoid duplicates,
    // bump pointers until you reach a new value. The time complexity of this is
    // O(N^2).

    // Maybe you could still do it the two-sum approach, but the thing you would
    // need to store in the hash table is the sum of two numbers (as the key)
    // and the value would be the pair of indices? Need to investigate further.
    vector<vector<int>> threeSumV2(vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue; // forgot this
            int j = i + 1;
            int k = arr.size() - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0)
                {
                    triplets.push_back({arr[i], arr[j], arr[k]}); // messed this up
                    j++;
                    while (arr[j] == arr[j - 1] && j < k)
                        j++;
                }
                else if (sum < 0)
                {
                    j++;
                    while (arr[j] == arr[j - 1] && (j < k))
                    {
                        j++;
                    }
                }
                else
                {
                    k--;
                    while (arr[k] == arr[k + 1] && (k > j))
                    {
                        k--;
                    }
                }
            }
        }
        return triplets;
    }
};