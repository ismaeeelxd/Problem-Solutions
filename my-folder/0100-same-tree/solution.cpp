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
    vector<int> path;
    void traverse(TreeNode* p){
        if(!p) {
         path.push_back(1e8);
         return;   
        }
        path.push_back(p->val);
        traverse(p->left);
        traverse(p->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(p);
        vector<int> path_1 = path;
        path.clear();
        traverse(q);
        vector<int> path_2 = path;
        if(path_1 == path_2){
            return true;
        } 
        return false;

    }
};
