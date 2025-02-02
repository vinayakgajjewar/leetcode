#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    static bool containsDuplicate(vector<int> &nums) {

        /*
         * Use an unordered map (hash table) to store values that we've seen
         * before.
         */
        unordered_map<int, int> freqs;
        for (int num: nums) {
            ++freqs[num];
            if (freqs[num] > 1) return true;
        }
        return false;
    }
};

int main() {
    vector<int> input1 = {1, 2, 3, 1};
    bool output1 = Solution::containsDuplicate(input1);
    assert(output1 == true);

    vector<int> input2 = {1, 2, 3, 4};
    bool output2 = Solution::containsDuplicate(input2);
    assert(output2 == false);

    vector<int> input3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    bool output3 = Solution::containsDuplicate(input3);
    assert(output3 == true);
}