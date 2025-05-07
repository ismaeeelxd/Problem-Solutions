class Solution {
public:
    string str1;
    string str2;
    int longestCommonSubsequence(string text1, string text2) {
        this->str1 = text1;
        this->str2 = text2;
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        // for(int i = 0;i<1001;++i){
        //     for(int j = 0;j<1001;++j){
        //         if(i == str1.size() || j == str2.size()){
        //             dp[i][j] = 0;
        //         }
        //     }
        // }

        for(int i = str1.size()-1; i>=0;--i){
            for(int j = str2.size() - 1; j>=0 ; --j){
                if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    int choice1= dp[i+1][j];
                    int choice2= dp[i][j+1];
                    dp[i][j] = max(choice1,choice2);
                }
            }
        }

        return dp[0][0];
    }

    int LCS(int idx1,int idx2){
        // base case
        if(idx1 == str1.size() || idx2 == str2.size())
            return 0;
        
        if(str1[idx1] == str2[idx2]){
            return LCS(idx1+1, idx2+1) + 1;
        } else {
            int choice1 = LCS(idx1+1,idx2);
            int choice2 = LCS(idx1,idx2+1);
            return max(choice1,choice2);
        }
    }

};
