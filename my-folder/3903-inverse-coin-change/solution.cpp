class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> coins;

        for (int i = 0; i < numWays.size(); ++i) {
            int target = i + 1;

            vector<int> dp(target + 1, 0);
            dp[0] = 1;

            for (int c : coins) {
                for (int j = c; j <= target; ++j) {
                    dp[j] += dp[j - c];
                }
            }

            int ways = dp[target];
            if (numWays[i] == ways + 1) {
                coins.push_back(target);
            } else if (numWays[i] != ways) {
                return {}; 
            }
        }

        return coins;
    }
};

