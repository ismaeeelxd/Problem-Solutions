class Solution {
public:
    int memo[1001][1001];
    int dp(int i, int j, string &s1,string &s2){
        // sea 
        // sat
        if(i == s1.size()){
            int totalRem = 0;
            for(int k = j; k < s2.size(); ++k) totalRem += s2[k];
            return totalRem;
        }
        if(j == s2.size()){
            int totalRem = 0;
            for(int k = i; k < s1.size(); ++k) totalRem += s1[k];
            return totalRem;
        }
        auto &ret = memo[i][j];
        if(ret != -1) return ret;
        if(s1[i] == s2[j]){
            return ret = dp(i+1,j+1,s1,s2);
        }
        int d1 = dp(i+1,j,s1,s2) + s1[i];
        int d2 = dp(i,j+1,s1,s2) + s2[j];
        return ret = min(d1,d2);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(memo,-1,sizeof(memo));
        return dp(0,0,s1,s2);      
    }
};
