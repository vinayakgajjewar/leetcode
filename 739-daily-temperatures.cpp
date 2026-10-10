#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // i think the intuition to have here is that when you traverse the days
        // from right to left, when you encounter a hotter day, all the other
        // days become irrelevant. but, when you encounter a cooler day, you
        // have to hang on to both the hotter and cooler day somehow because
        // they might both be relevant. that's why this is a monotonic stack
        // problem. i'm pretty sure that we need the monotonic stack to have the
        // coolest day at the top and warmer days at the bottom when we
        // encounter a day cooler than the top of the stack, we know that the
        // next hottest day is the index at the top of the stack when we
        // encounter a day hotter than the top of the stack, pop from the top
        // until we find a day that's hotter, then we can both calculate the
        // wait and push the new day onto the stack
        vector<int> ans(temperatures.size(), 0);
        vector<int> stack;
        int n = temperatures.size();
        for (int i = n - 1; i >= 0; i--)
        {
            // 1. Pop from the stack until either the top of the stack is hotter
            //    or the stack is empty.
            // 2. Calculate the wait for the current day.
            // 3. Push the current day onto the stack.

            int curr_temp = temperatures.at(i);
            while (!stack.empty() && temperatures[stack.back()] <= curr_temp)
            {
                stack.pop_back();
            }
            if (!stack.empty())
                ans[i] = stack.back() - i;
            stack.push_back(i);
        }
        return ans;
    }
};