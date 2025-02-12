#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {

        /*
         * The simple solution to this problem is to insert the new interval at
         * the end, and then sort them with respect to start times. Then, we
         * have to go through and merge overlapping intervals.
         */
        intervals.push_back(newInterval);

        /*
         * This will sort the intervals by start time.
         */
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> current_interval = intervals[i];
            if (current_interval[0] <= result.back()[1]) {

                /*
                 * There is an overlap, and we need to compare end times to
                 * determine what to do.
                 */
                if (current_interval[1] > result.back()[1]) {
                    result.back()[1] = current_interval[1];
                }
            } else {
                result.push_back(current_interval);
            }
        }
        return result;
    }
};