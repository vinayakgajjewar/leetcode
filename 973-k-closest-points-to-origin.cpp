#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {

        /*
         * This is nifty! We can initialize a priority queue with the elements
         * in a vector.
         */
        priority_queue<vector<int>, vector<vector<int>>, compare> min_heap(points.begin(), points.end());
        vector<vector<int>> k_closest;
        for (int i = 0; i < k; ++i) {
            k_closest.push_back(min_heap.top());
            min_heap.pop();
        }
        return k_closest;
    }

private:

    /*
     * I guess this is how we overload the comparison operator for priority
     * queues.
     */
    struct compare {
        bool operator()(vector<int> &point1, vector<int> &point2) {
            return pow(point1[0], 2) + pow(point1[1], 2) > pow(point2[0], 2) + pow(point2[1], 2);
        }
    };
};

void run_test_case(vector<vector<int>> &points, int k) {
    vector<vector<int>> k_closest = Solution::kClosest(points, k);
    for (vector<int> &point: k_closest) {
        cout << "(" << point[0] << ", " << point[1] << ") ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> input1 = {{1,  3},
                                  {-2, 2}};
    int k1 = 1;
    run_test_case(input1, k1);

    vector<vector<int>> input2 = {{3,  3},
                                  {5,  -1},
                                  {-2, 4}};
    int k2 = 2;
    run_test_case(input2, k2);
}