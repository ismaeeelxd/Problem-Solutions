/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        queue<Node*> q;
        bool vis[101] = {0};
        q.push(node);
        Node* firstNode = new Node(node->val);
        unordered_map<int,Node*> newNodes;
        newNodes[1] = firstNode;

        while(!q.empty()){
            Node* a = q.front(); q.pop();
            if(vis[a->val]) continue;
            vis[a->val] = 1;
            Node* newNode = newNodes[a->val];
            int neighborSize = a->neighbors.size();

            for(int i = 0; i < neighborSize; ++i){
                if(!newNodes.count(a->neighbors[i]->val)){
                    Node* newN = new Node(a->neighbors[i]->val);
                    newNodes[a->neighbors[i]->val] = newN;
                }
                newNode->neighbors.push_back(newNodes[a->neighbors[i]->val]);
                q.push(a->neighbors[i]);
            }
        }
        return firstNode;
    }
};
