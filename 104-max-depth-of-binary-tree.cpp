#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        int maxDepthLeft;
        int maxDepthRight;
        if (!root)
            return 0;
        if (root->left)
        {
            maxDepthLeft = maxDepth(root->left);
        }
        else
        {
            maxDepthLeft = 0;
        }
        if (root->right)
        {
            maxDepthRight = maxDepth(root->right);
        }
        else
        {
            maxDepthRight = 0;
        }
        return std::max(maxDepthLeft, maxDepthRight) + 1;
    }

    // This is my attempt from 2026/10/07. The runtime complexity is O(N), where
    // N is the number of nodes in the tree because we visit each node only
    // once. The space complexity is a bit more complicated because we are using
    // recursion, so each recursive call occupies space on the call stack. The
    // maximum number of simultaneous calls is equal to the tree's height, so if
    // it's a balanced tree it is O(log N) but if it is a chain it is O(N).
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!(root->left) && !(root->right))
            return 1;
        int left_max = 0;
        if (root->left)
            left_max = maxDepth(root->left);
        int right_max = 0;
        if (root->right)
            right_max = maxDepth(root->right);
        int max_depth = max(left_max, right_max) + 1;
        return max_depth;
    }
};