/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBstH(TreeNode* root, long minval, long maxval) {
        if (!root)
            return true;
        if (root->val >= maxval || root->val <= minval)
            return false;
        return isValidBstH(root->left, minval, root->val) &&
               isValidBstH(root->right, root->val, maxval);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBstH(root, LONG_MIN, LONG_MAX);
    }
};