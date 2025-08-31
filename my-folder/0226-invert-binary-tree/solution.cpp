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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        rec(root);
        return root;
    }

    void rec(TreeNode* root) {
        if(!root) return;
        if(root->right && root->left) swap(root->right,root->left);
        else if(root->right) {
            root->left = root->right;
            root->right = nullptr;
        } 
        else if(root->left){
            root->right = root->left;
            root->left = nullptr;
        }
        rec(root->right);
        rec(root->left);
    }
};
