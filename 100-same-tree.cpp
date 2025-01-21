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
    bool isSameTree(TreeNode *p, TreeNode *q) {

        /*
         * We can use recursion for this. The base case is if we're at a leaf
         * node. If the values don't match, or if the other node is not a leaf
         * node, return false. Recursive case: return true if both of my
         * subtrees are identical and my value is identical.
         */

        /*
         * Base case.
         */
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        /*
         * Recursive case.
         */
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};