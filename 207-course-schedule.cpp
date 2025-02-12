#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        /*
         * This problem is equivalent to finding a cycle in a directed graph.
         */

        // adjacency[node] stores the neighbors of node.
        vector<vector<int>> adjacency(numCourses);
        vector<int> indegree(numCourses, 0);

        // Populate the adjacency vector and the indegree vector.
        for (vector<int> prerequisite: prerequisites) {
            int source = prerequisite[1];
            int destination = prerequisite[0];
            adjacency[destination].push_back(source);
            ++indegree[source];
        }

        /*
         * Use a queue to traverse the graph, starting at the leaf nodes, which
         * are the nodes with an indegree of 0.
         */
        queue<int> to_visit;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) to_visit.push(i);
        }

        vector<int> visited;
        while (!to_visit.empty()) {
            int curr_node = to_visit.front();
            visited.push_back(curr_node);
            to_visit.pop();
            for (int neighbor: adjacency[curr_node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0) {
                    to_visit.push(neighbor);
                }
            }
        }

        /*
         * Our success condition is if the number of courses that we visited is
         * equal to the number of courses provided. If so, there are no cycles.
         */
        if (visited.size() == numCourses) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> input1 = {{1, 0}};
    bool output1 = Solution::canFinish(2, input1);
    assert(output1 == true);

    vector<vector<int>> input2 = {{1, 0},
                                  {0, 1}};
    bool output2 = Solution::canFinish(2, input2);
    assert(output2 == false);
}