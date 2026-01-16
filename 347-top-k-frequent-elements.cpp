/*
 * 347-top-k-frequent-elements.cpp
 *
 * https://leetcode.com/problems/top-k-frequent-elements/
 *
 * One of the ways to do this problem is to create a frequency table of all the
 * elements in the vector. Then, push them all onto a priority queue and then
 * pop off only the top K elements.
 *
 * C++ quirk to remember: when you make a priority queue with a custom
 * comparator, you also need to specify the backing store (vector, in this case)
 * as well for some reason.
 *
 * Don't forget to double-check the order of the comparator function! If we want
 * the largest frequencies, we need to do (a < b), not (a > b).
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> topKFrequent(vector<int> &nums, int k) {

        unordered_map<int, int> frequencies;
        for (int num: nums) {
            frequencies[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> largest_frequencies;
        for (auto &[num, freq]: frequencies) {
            largest_frequencies.emplace(num, freq);
        }

        vector<int> k_most_frequent;
        for (int i = 0; i < k; ++i) {
            k_most_frequent.push_back(largest_frequencies.top().first);
            largest_frequencies.pop();
        }
        return k_most_frequent;
    }

private:

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