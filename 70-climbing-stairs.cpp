#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> distinct_climbs;

    int climbStairs(int n) {

        /*
         * This is a recursive problem, but if we solve it the naive way, we'll
         * exceed the time limit. To solve this one, we have to maintain an
         * extra data structure to "remember" the results of previous
         * computations.
         */

        /*
         * Base cases.
         */
        if (n == 1) return 1;
        if (n == 2) return 2;

        /*
         * Recursive case.
         */
        if (distinct_climbs[n] != 0) {
            int num_climbs = distinct_climbs[n];
            return num_climbs;
        }
        int num_climbs = climbStairs(n - 1) + climbStairs(n - 2);
        distinct_climbs[n] = num_climbs;
        return num_climbs;
    }
};