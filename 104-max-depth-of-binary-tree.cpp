#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
};