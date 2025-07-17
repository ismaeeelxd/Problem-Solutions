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
    bool traverse(TreeNode* root, int targetSum){
        if(!root) return 0;
        if(!root->right && !root->left) return targetSum == root->val;
        ;
        

        return traverse(root->left,targetSum-root->val) || traverse(root->right,targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root,targetSum);
    }
};
