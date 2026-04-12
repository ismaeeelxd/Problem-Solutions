/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    vector<Node*> arr[6002];
    void push(Node* root, int level) {
        if(!root) return;
        arr[level].push_back(root);
        push(root->left, level + 1);
        push(root->right, level + 1);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        push(root, 0);
        for(int i = 0; i < 6002; i++) {
            if(arr[i].size() > 0) {
                int j = 0;
                int k = 1;
                while(k < arr[i].size()) {
                    arr[i][j++]->next = arr[i][k++];
                }
                arr[i][j]->next = nullptr;
            }
        }
        return root;
    }
};
