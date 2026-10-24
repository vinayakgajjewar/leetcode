#include <vector>

using namespace std;

// todo: i do not understand this solution well enough to do it again.
class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        // because each value in the array is a valid index into the array, we
        // can treat it like a  linked list. because there is 1 duplicate, there
        // will be a cycle in the linked list. we can use the fast and slow
        // pointer technique to find that cycle. todo: i do not understand the
        // second part of this algorithm

        // these will store the index it is currently at.
        int slow = 0;
        int fast = 0;

        // todo: why can't i do while (slow != fast) ?
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        int slow2 = 0;
        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2)
                return slow;
        }
    }
};