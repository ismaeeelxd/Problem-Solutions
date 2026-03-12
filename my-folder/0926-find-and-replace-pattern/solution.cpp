class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for(string word : words) {
            int n = word.size();
            bool found = true;
            map<char,char> mp;
            map<char,char> rev;
            for(int i = 0; i < n; ++i) {
                if(!mp.contains(pattern[i]) && !rev.contains(word[i])) {
                    mp[pattern[i]] = word[i];
                    rev[word[i]] = pattern[i];
                } else {
                    if(mp[pattern[i]] != word[i] || rev[word[i]] != pattern[i]){
                        found = false;
                        break;
                    } 
                }
            }
            if(found) ret.push_back(word);
        }
        return ret;
    }
};
