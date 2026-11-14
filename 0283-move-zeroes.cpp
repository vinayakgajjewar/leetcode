// this is my solution from 2026-11-13. it has a time complexity of O(n) and a space complexity of O(n).
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // go through the array once, collecting all the nonzeroes in another vector while clearing nums to 0
        // go through nums again, adding all the nonzero elements back
        // this is O(n) time complexity and O(n) space complexity

        vector<int> nonzeroes;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums.at(i) != 0) {
                nonzeroes.push_back(nums.at(i));
                nums[i] = 0;
            }
        }

        for (int i = 0; i < nonzeroes.size(); i++) {
            nums[i] = nonzeroes[i];
        }

        // you could do this in O(1) space complexity by swapping 0s and nonzeroes in-place.
    }
};

// this is the solution i think they are looking for, which uses O(1) space but i don't quite have my head around the intuition for this.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // we will use a two-pointer approach where one pointer searches for nonzero elements and the other points to the location where they should be moved to.

        int n = nums.size();
        if (n == 0 || n == 1) return;

        // this will track the first zero element to the left of right
        int left = 0;

        // this will iterate through all the nonzero elements of nums.

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) continue;
            while (left < n && nums.at(left) != 0) {
                left++;
            }
            if (left >= right) {
                left = right;
                continue;
            }

            nums[left] = nums[right];
            nums[right] = 0;
        }
    }
};