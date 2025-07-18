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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i = 0; i < size; ++i){
                TreeNode* n = q.front();
                q.pop();
                sum+=n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            ans.push_back((double)sum/size);
        }

        return ans;

        return ans;
    }
};
