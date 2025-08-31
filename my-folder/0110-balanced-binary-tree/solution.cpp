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
    bool isBalanced(TreeNode* root) {
        if(rec(root) >= 1e5) {
            return false;
        } else return true;
    }

    int rec(TreeNode* root) {
        if(!root) return 0;
        int right = rec(root->right) + 1;
        int left = rec(root->left) + 1;
        if(abs(right-left) > 1) return 1e5;
        return max(right,left);
    }
};
