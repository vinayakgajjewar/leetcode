#include <vector>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        // We could iterate through the loop and keep track of the cheapest
        // price we've seen so far.
        int cheapest_price = INT_MAX;
        int max_profit = 0;
        for (int i : prices)
        {

            // Check if this is the cheapest price we've seen.
            if (i < cheapest_price)
                cheapest_price = i;

            // Check if this price gives us the best profit against the cheapest
            // price we've seen.
            if (i - cheapest_price > max_profit)
            {
                max_profit = i - cheapest_price;
            }
        }
        return max_profit;
    }

    // 2026/10/05. This is basically the same as above. The key idea is to, for
    // each possible sell price, figure out the max profit obtainable when you
    // sell at that sell price. The naive way to calculate this is to have
    // another loop that finds the minimum value before that sell price, but you
    // can just maintain the minimum price seen so far as a variable. Note that
    // you might attempt to calculate, for each day, the maximum profit if you
    // buy, not sell, on that day, but that would require another loop and thus
    // be O(n^2). You just have to remember that it is easier to look back in
    // time and not forward in time.
    int maxProfitV2(vector<int> &prices)
    {
        int cheapest_buy_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices)
        {
            cheapest_buy_price = min(cheapest_buy_price, price);
            int curr_profit = price - cheapest_buy_price;
            max_profit = max(max_profit, curr_profit);
        }
        return max_profit;
    }
};