#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};

        /*
         * Construct our adjacency list and find the degree of each node.
         */
        vector<vector<int>> adjacency_list(n);
        vector<int> degree(n, 0);
        for (vector<int> edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
            ++degree[u];
            ++degree[v];
        }

        /*
         * Any node with a degree of 1 is a leaf node.
         */
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) leaves.push(i);
        }

        /*
         * Until there are one or two nodes left, keep trimming leaf nodes from
         * the tree.
         */
        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            int leaves_count = static_cast<int>(leaves.size());
            remaining_nodes -= leaves_count;
            for (int i = 0; i < leaves_count; ++i) {
                int leaf = leaves.front();
                leaves.pop();

                /*
                 * Trimming a leaf node may cause another node to become a leaf
                 * node.
                 */
                for (int neighbor: adjacency_list[leaf]) {
                    --degree[neighbor];
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        /*
         * The last nodes(s) to become a leaf node is the answer.
         */
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};

int main() {

}