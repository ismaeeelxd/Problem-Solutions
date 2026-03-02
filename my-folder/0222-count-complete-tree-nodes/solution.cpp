/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count(TreeNode* root) {
        if(!root) return 0;
        int rightNodes = count(root->right) + 1;
        int leftNodes = count(root->left) + 1;
        return rightNodes + leftNodes - 1;
    }
    int countNodes(TreeNode* root) {
        return count(root);
    }
};
