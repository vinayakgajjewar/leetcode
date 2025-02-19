#include <vector>

using namespace std;

class Solution {
public:
    static int canCompleteCircuitEfficient(vector<int> &gas, vector<int> &cost) {
        /*
         * This is a weird one. I don't think I fully understand this solution.
         */
        int total_gas = 0;
        int total_cost = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
        }

        /*
         * We know that a full trip is impossible if the total gas we get is
         * less than the total gas we have to spend.
         */
        if (total_gas < total_cost) return -1;
        int current_gas = 0;
        int start_index = 0;
        for (int i = 0; i < gas.size(); ++i) {
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {
                current_gas = 0;
                start_index = i + 1;
            }
        }
        return start_index;
    }

    static int canCompleteCircuitNaive(vector<int> &gas, vector<int> &cost) {
        /*
         * The naive solution is to simulate trying to travel around the circle
         * starting at each station. We can optimize this slightly by only
         * trying to start at stations that don't give less gas than they
         * require to get to the next one.
         */
        int n = static_cast<int>(gas.size());
        vector<int> possible_starts;
        if (n == 1 && gas[0] >= cost[0]) return 0;
        for (int i = 0; i < n; ++i) {
            if (gas[i] <= cost[i]) continue;
            possible_starts.push_back(i);
        }

        for (int possible_start: possible_starts) {
            int gas_left = 0;
            int curr_station = possible_start;
            /*
             * At each station, we need to check if our gas left + the gas at
             * that station covers the trip to the next one. If it doesn't, our
             * trip is over.
             */
            while (gas_left + gas[curr_station] >= cost[curr_station]) {
                gas_left += gas[curr_station];
                gas_left -= cost[curr_station];
                curr_station = (curr_station + 1) % n;

                /*
                 * If we find ourselves at the same station we started at, we
                 * have successfully completed the loop.
                 */
                if (curr_station == possible_start) return possible_start;
            }
        }
        return -1;
    }
};


