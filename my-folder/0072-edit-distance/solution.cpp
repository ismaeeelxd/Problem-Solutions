class Solution {
public:
    int memo[501][501];
    int dp(int index_1,int index_2, string &word1, string &word2){
        if(index_1 == word1.size()){
            return word2.size() - index_2;
        }
        if(index_2 == word2.size()){
            return word1.size() - index_1;
        }
        auto &ret = memo[index_1][index_2];
        if(ret != -1) return ret;
        if(word1[index_1] == word2[index_2]){
            return ret = dp(index_1+1,index_2+1,word1,word2);
        }
        int delete_ = dp(index_1+1,index_2,word1,word2) + 1;
        int delete_2 = dp(index_1,index_2+1,word1,word2) + 1;
        int replace = dp(index_1+1,index_2+1,word1,word2) + 1;
        //try to replace
        return ret = min(min(delete_,delete_2),replace);
    }
    int minDistance(string word1, string word2) {
        memset(memo,-1,sizeof(memo));  
        return dp(0,0,word1,word2);    
    }
};
