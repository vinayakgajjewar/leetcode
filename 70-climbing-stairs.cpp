#include <unordered_map>

using namespace std;

class Solution {
public:
    int climb_stairs_impl(int n, unordered_map<int, int> &cache) {

        // First, let's check the cache and see if we have already computed the
        // solution for this value of n before.

        if (cache.find(n) != cache.end()) return cache[n];

        // These are the bases cases. There is only one way to climb up 0 stairs
        // and only one way to climb up one stair.

        if (n == 0 || n == 1) return 1;
        cache[n] = climb_stairs_impl(n - 1, cache) + climb_stairs_impl(n - 2, cache);
        return cache[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> cache;
        return climb_stairs_impl(n, cache);
    }
};