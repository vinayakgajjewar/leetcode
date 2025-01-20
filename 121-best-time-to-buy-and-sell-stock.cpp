#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // We could iterate through the loop and keep track of the cheapest
        // price we've seen so far.
        int cheapest_price = INT_MAX;
        int max_profit = 0;
        for (int i: prices) {

            // Check if this is the cheapest price we've seen.
            if (i < cheapest_price) cheapest_price = i;

            // Check if this price gives us the best profit against the cheapest
            // price we've seen.
            if (i - cheapest_price > max_profit) {
                max_profit = i - cheapest_price;
            }
        }
        return max_profit;
    }
};