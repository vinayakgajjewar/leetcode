#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> topKFrequent(vector<int> &nums, int k) {
        /*
         * First, we need to create a hash table (unordered map) of frequencies.
         * Then, we can iterate through the map and populate a heap (priority
         * queue).
         */

        unordered_map<int, int> frequencies;
        for (int num: nums) {
            ++frequencies[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> largest_frequencies;
        for (auto &[num, freq]: frequencies) {
            largest_frequencies.push(make_pair(num, freq));
        }

        vector<int> k_most_frequent;
        for (int i = 0; i < k; ++i) {
            k_most_frequent.push_back(largest_frequencies.top().first);
            largest_frequencies.pop();
        }
        return k_most_frequent;
    }

private:

    /*
     * We have to make a custom compare operation because we are comparing pairs
     * where the first element is the number and the second element is the
     * frequency, and we only want to compare frequencies.
     */
    struct compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };
};

void run_test_case(vector<int> input, int k) {
    vector<int> output = Solution::topKFrequent(input, k);
    for (int num: output) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> input1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    run_test_case(input1, k1);

    vector<int> input2 = {1};
    int k2 = 1;
    run_test_case(input2, k2);
}