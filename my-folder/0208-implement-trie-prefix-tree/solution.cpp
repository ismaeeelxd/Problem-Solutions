struct Node {
    char val;
    bool terminal;
    Node* children[26];
    Node(char val_, bool terminal_){
        val = val_;
        terminal = terminal_;
        for(int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        Node* root_ = new Node('*',false);
        this->root = root_;
    }
    
    void insert(string word) {
        Node* trav = this->root;
        for(int i = 0; i < word.size(); ++i){
            char w = word[i];
            if(!trav->children[w - 'a']){
                trav->children[w - 'a'] = new Node(w, false);
            }
            trav = trav->children[w-'a'];
            if(i == word.size() - 1) trav->terminal = true;
        }
    }
    
    bool search(string word) {
        Node* trav = this->root;
        for(int i = 0; i < word.size(); ++i){
            char w = word[i];

            if(!trav->children[w - 'a']){
                return false;
            }
            trav = trav->children[w - 'a'];
        }

        return trav->terminal;
    }
    
    bool startsWith(string prefix) {
        Node* trav = this->root;
        for(int i = 0; i < prefix.size(); ++i){
            char w = prefix[i];

            if(!trav->children[w - 'a']){
                return false;
            }
            trav = trav->children[w - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
