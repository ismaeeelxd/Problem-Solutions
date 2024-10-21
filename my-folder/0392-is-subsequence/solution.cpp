class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t found = 0;
        for(int i = 0;i<s.size();++i){
            found = t.find(s[i],found);
            if(found == string::npos){
                return false;
            }
            found++;
        }
        return true;
    }
};
