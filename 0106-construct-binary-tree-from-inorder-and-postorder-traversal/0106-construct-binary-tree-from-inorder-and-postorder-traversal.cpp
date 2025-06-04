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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1, inmap);
    }
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
                        vector<int>& postorder, int postStart, int postEnd,
                        map<int, int>& inmap) {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inmap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(inorder, inStart, inRoot - 1, postorder,
                               postStart, postStart + numsLeft - 1, inmap);
        root->right = buildTree(inorder, inRoot + 1, inEnd, postorder,
                                 postStart + numsLeft, postEnd - 1, inmap);
        return root;
    }
};