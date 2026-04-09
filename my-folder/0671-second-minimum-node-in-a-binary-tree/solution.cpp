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
    set<int> nodes;
    void getMin(TreeNode* root) {
        if(!root) return;   
        nodes.insert(root->val);
        getMin(root->left);
        getMin(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        this->getMin(root);
        if(nodes.size() == 1) return -1;
        auto it = next(nodes.begin(), 1);
        return *it; 

    }
};
