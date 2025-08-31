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
    vector<int> kber;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        rec(root);
        for(int i = kber.size() - 1; i > 0; --i) {
            if(kber[i] <= kber[i-1]) return false;
        }
        return true;
    }
    void rec(TreeNode* root) {
        if(!root) return;
        rec(root->left);
        kber.push_back(root->val);
        rec(root->right);
    }
};
