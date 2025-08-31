/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode* current = root;
        unordered_map<int,TreeNode*> parents;
        parents[root->val] = nullptr;
        int p_level = 0;
        while(current) {
            if(p->val > current->val) {
                parents[current->right->val] = current;
                current = current->right;
            }
            else if(p->val < current->val) {
                parents[current->left->val] = current;
                current = current->left;
            } else {
                break;
            } 
            p_level++;
        }

        TreeNode* current_ = root;
        int q_level = 0;
        while(current_) {
            if(q->val > current_->val) {
                parents[current_->right->val] = current_;
                current_ = current_->right;
            }
            else if(q->val < current_->val) {
                parents[current_->left->val] = current_;
                current_ = current_->left;
            } else {
                break;
            } 
            q_level++;
        }
        TreeNode* p_ptr = p;
        TreeNode* q_ptr = q;
        if(q_level > p_level) {
            TreeNode* curr = q;
            while(curr && q_level != p_level){
                curr = parents[curr->val];
                q_level--;
            }
            q_ptr = curr;
        } else if (p_level > q_level) {
            TreeNode* curr = p;
            while(curr && q_level != p_level){
                curr = parents[curr->val];
                p_level--;
            }
            p_ptr = curr;
        }

        while(p_ptr != q_ptr) {
            p_ptr = parents[p_ptr->val];
            q_ptr = parents[q_ptr->val];
        }

        return p_ptr;
    }
};
