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
    void invert(TreeNode* root){
        if(root == nullptr) return;
        invert(root->left);
        invert(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        invert(root);
        return root;
    }
};
