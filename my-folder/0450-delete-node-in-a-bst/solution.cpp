class Solution {
public:
    pair<TreeNode*, TreeNode*> findNodeAndParent(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        
        while (curr && curr->val != key) {
            parent = curr;
            if (key < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return {curr, parent};
    }

    pair<TreeNode*, TreeNode*> findMostLeftAndParent(TreeNode* node, TreeNode* parent) {
        TreeNode* curr = node;
        TreeNode* p = parent;
        
        while (curr && curr->left) {
            p = curr;
            curr = curr->left;
        }
        return {curr, p};
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        auto [node, parent] = findNodeAndParent(root, key);

        if (!node) return root;

        if (!node->left || !node->right) {
            TreeNode* child = node->left ? node->left : node->right;


            if (!parent) {
                delete node;   
                return child;  
            }

            if (parent->left == node) {
                parent->left = child;
            } else {
                parent->right = child;
            }

            delete node;
        } 
        
        else {

            auto [successor, succParent] = findMostLeftAndParent(node->right, node);

            node->val = successor->val;


            if (succParent->left == successor) {
                succParent->left = successor->right;
            } else {
                succParent->right = successor->right; 
            }

            delete successor;
        }

        return root;
    }
};
