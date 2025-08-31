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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> levels;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz - 1; ++i){
                TreeNode* x = q.front();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                q.pop();
            }
            TreeNode* a = q.front();
            levels.push_back(a->val);
            if(a->left) q.push(a->left);
            if(a->right) q.push(a->right);
            q.pop();
        }
        return levels;
    }
};
