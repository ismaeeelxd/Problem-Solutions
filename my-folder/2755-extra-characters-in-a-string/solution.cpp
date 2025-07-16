class Solution {
public:
    int memo[51];
    int dp(int i, string &s, vector<string>&dict){
        if(s.size() == i) return 0;
        if(memo[i] != -1) return memo[i];
        int res = dp(i+1, s , dict) + 1;
        for(int j = i; j < s.size(); ++j){
            string sub = s.substr(i, j - i + 1);
            for(const auto &w : dict) if(w == sub) res = min(res, dp(j + 1, s,dict));
        }

        return memo[i] = res;


    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(memo,-1,sizeof(memo));
        return dp(0,s,dictionary);      
    }
};
