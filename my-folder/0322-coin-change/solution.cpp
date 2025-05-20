class Solution {
public:
    int amount;
    int memo[1000][10010];

    int coinChange(vector<int>& coins, int amount) {
        memset(this->memo,-1,sizeof(this->memo));
        this->amount = amount;
        int ans = solve(coins, 0, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }


int solve(vector<int>& coins, int idx, int amount_) {
    if (amount_ == 0)
        return 0;

    if (amount_ < 0 || idx == coins.size())
        return INT_MAX;

    auto &ret = this->memo[idx][amount_];
    if(ret != -1)
        return ret;

    int choice1 = solve(coins, idx, amount_- coins[idx]);
    if (choice1 != INT_MAX)
        choice1 += 1;

    int choice2 = solve(coins, idx + 1, amount_);

    return ret = min(choice1, choice2);
}
};
