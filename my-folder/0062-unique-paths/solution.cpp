class Solution {
public:
    int dp[101][101];

    int solve(int m, int n){
        if(m == 0|| n == 0)
            return 1;
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        dp[m][n] = solve(m-1,n) + solve(m,n-1);
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        for(int i = 0;i<101;++i){
            for(int j =0;j<101;++j){
                dp[i][j] = -1;
            }
        }

       return solve(m-1,n-1);
    }
};
