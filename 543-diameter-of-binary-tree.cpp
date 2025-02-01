#include <algorithm>

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
    int diameterOfBinaryTree(TreeNode *root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    int height(TreeNode *node, int &diameter) {

        // Base case.
        if (!node) return 0;

        // Recursive case.
        int left_height = height(node->left, diameter);
        int right_height = height(node->right, diameter);

        // Update the shared diameter param if left_height + right_height
        // is larger.
        diameter = max(diameter, left_height + right_height);

        // Return the height of the current node.
        return 1 + max(left_height, right_height);
    }
};

class n_squared_solution {
public:
    int diameter_of_binary_tree(TreeNode *root) {
        if (!root) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        int left_diameter = diameter_of_binary_tree(root->left);
        int right_diameter = diameter_of_binary_tree(root->right);
        return max(left_height + right_height, max(left_diameter, right_diameter));
    }

private:
    int height(TreeNode *node) {
        if (!node) return 0;
        int left_height = height(node->left);
        int right_height = height(node->right);
        return 1 + max(left_height, right_height);
    }
};