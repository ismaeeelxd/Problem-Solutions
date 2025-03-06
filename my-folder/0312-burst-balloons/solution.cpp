class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            new_nums[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int length = 1; length <= n; ++length) {
            for (int i = 1; i <= n - length + 1; ++i) {
                int j = i + length - 1;
                for (int k = i; k <= j; ++k) {
                    int coins = dp[i][k - 1] + dp[k + 1][j] + new_nums[i - 1] * new_nums[k] * new_nums[j + 1];
                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }
        
        return dp[1][n];
    }

};
