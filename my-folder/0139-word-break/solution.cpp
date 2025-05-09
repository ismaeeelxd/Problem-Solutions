class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int memo[301];
        memset(memo,-1,sizeof(memo));
        return solve(s,wordDict,0,memo);
    }

    bool solve(string &s, vector<string> &wordDict,  int i, int(&memo)[301]){
        if(i == s.size())
            return true;
        auto &ret = memo[i];
        if(ret != -1)
            return ret;
        for(const auto &word : wordDict){
            bool match = true;
            if (i + word.size() > s.size()) continue; 
            for(int j = 0;j<word.size();++j){
                if(word[j] != s[i + j]){
                    match = false;
                    break;
                }
            }
            if(match){
                bool choice = solve(s,wordDict,i+word.size(),memo);
                if(choice)
                    return ret = true;
            }
        }
        return ret = false;
    }

};
