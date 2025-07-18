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
    int getMin(TreeNode* root){
        if(!root) return 0;
        if(!root->left) return getMin(root->right) + 1;
        if(!root->right) return getMin(root->left) + 1;

        int leftSide = getMin(root->left) + 1;
        int rightSide = getMin(root->right) + 1;
        return min(leftSide, rightSide);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return getMin(root);
    }
};
