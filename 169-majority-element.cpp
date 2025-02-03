#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {

        /*
         * Use an unordered map (hash table) to track element frequencies.
         */
        unordered_map<int, int> freqs;
        int majority = nums.size() / 2;
        for (int num: nums) {
            ++freqs[num];
            if (freqs[num] > majority) return num;
        }

        /*
         * We should never get here.
         */
        return -1;
    }
};