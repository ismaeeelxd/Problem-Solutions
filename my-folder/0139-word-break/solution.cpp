class Solution {
public:
    int memo[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(memo,-1,sizeof(memo));
        return solve(s,wordDict,0);
    }

    bool solve(string &s, vector<string>&wordDict, int i){
        if(i == s.size()) return true;
        if(memo[i] != -1) return memo[i];
        for(const auto &word: wordDict){
            if(i + word.size() > s.size()) continue;
            bool match = true;
            int k = i;
            for (int j = 0; j < word.size(); ++j,++k){
                if(s[k] != word[j]){
                    match = false;
                    break;
                } 
            }
            if(match && solve(s,wordDict,i+word.size())){
                return memo[i] = true;
            }
        }
        return memo[i] = false;
    }
};
