class Solution {
public:
    int minDistance(string word1, string word2) {
        int memo[501][501];
        memset(memo,-1,sizeof(memo));
        return solve(0,0,word1,word2,memo);
    }
    
    int solve(int idx1, int idx2,string &word1, string &word2,int(&memo)[501][501]){
        if(idx1 == word1.size()){
            return word2.size() - idx2;
        }

        if(idx2 == word2.size()){
            return word1.size() - idx1;
        }
        auto &ret = memo[idx1][idx2];
        if(ret != -1)
            return ret;
        if(word1[idx1] == word2[idx2]){
            return ret = solve(idx1+1,idx2+1,word1,word2,memo);
        }

        int change = 1 + solve(idx1+1,idx2+1,word1,word2,memo);
        int insert_ = 1 + solve(idx1,idx2 +1,word1,word2,memo);
        int delete_ = 1 + solve(idx1+1,idx2,word1,word2,memo);

        return ret = min(min(change,insert_),delete_);
    }
};
