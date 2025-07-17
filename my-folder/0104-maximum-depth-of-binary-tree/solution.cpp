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
    int traverse(TreeNode* root){
        if(!root) return 0;
        int leftDepth = traverse(root->left) + 1;
        int rightDepth = traverse(root->right) + 1;
        return max(leftDepth, rightDepth);
    }
    int maxDepth(TreeNode* root) {
        return traverse(root);
    }
};
