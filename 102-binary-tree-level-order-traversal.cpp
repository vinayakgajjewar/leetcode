#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {

        /*
         * Traverse the tree using BFS (with a queue.) Store the level of the
         * node in the queue as well so that we know which inner vector to add
         * its value to. If we process a node with level k, add its children to
         * the queue with level k+1.
         */

        if (!root) return {};

        int num_levels = this->max_depth(root);
        vector<vector<int>> level_order(num_levels);

        queue<pair<TreeNode *, int>> queue;
        queue.push(make_pair(root, 0));
        while (!queue.empty()) {
            TreeNode *curr = queue.front().first;
            int level = queue.front().second;
            queue.pop();
            level_order[level].push_back(curr->val);
            if (curr->left) queue.push(make_pair(curr->left, level + 1));
            if (curr->right) queue.push(make_pair(curr->right, level + 1));
        }

        return level_order;
    }

    int max_depth(TreeNode *root) {
        if (!root) return 0;
        return max(max_depth(root->left), max_depth(root->right)) + 1;
    }
};