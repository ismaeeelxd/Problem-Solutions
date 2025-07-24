class Solution {
public:
    int countKeyChanges(string s) {
        int changes = 0;
        for(auto &c : s) c = tolower(c);
        for(int i = 1; i < s.size(); ++i){
            if(s[i] != s[i-1]) changes++;
        }
        return changes;
    }
};
