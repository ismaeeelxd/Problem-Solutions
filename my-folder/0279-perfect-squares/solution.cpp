class Solution {
public:
    vector<vector<int>> memo;

    int dp(int i, int curSum, int &n, vector<int> &p) {
        if (curSum == n) return 0;
        if (i >= p.size() || curSum > n) return 1e9;

        if (memo[i][curSum] != -1) return memo[i][curSum];

        int take = dp(i, curSum + p[i], n, p) + 1;
        int leave = dp(i + 1, curSum, n, p);

        return memo[i][curSum] = min(take, leave);
    }

    int numSquares(int n) {
        int i = 1;
        vector<int> perfectSquares;
        while (i * i <= n) perfectSquares.push_back(i * i++);
        // Initialize memo with dimensions: number of perfect squares x (n+1)
        memo.assign(perfectSquares.size(), vector<int>(n + 1, -1));
        return dp(0, 0, n, perfectSquares);
    }
};

