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
    
    unordered_map<int,int> mp;
    void traverse(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        int largest = 0;
        for(auto [num,count]:mp){
            if(count > largest) largest = count;
        }
        vector<int> f;
        for(auto[num,count]:mp){
            if(count == largest) f.push_back(num);
        }

        return f;
    }
};
