class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int memo[5001][2][2];
        memset(memo,-1,sizeof(memo));
        return solve(0,1,0,prices, memo);
    }
    int solve(int day,int canBuy,int cooldown, vector<int>&prices,int (&memo)[5001][2][2]){
        if(day >= prices.size())
            return 0;
        auto &ret = memo[day][canBuy][cooldown];
        if(ret != -1){
            return ret;
        }
        if(cooldown){
            return ret = solve(day+1,1,0,prices, memo);
        }
        if(canBuy){
            int buy = -prices[day] + solve(day+1,0,0,prices,memo);
            int skip = solve(day+1,1,0,prices, memo);
            return ret = max(buy,skip);
        } else {
            int sell = prices[day] + solve(day+1,0,1,prices,memo);
            int skip = solve(day+1,0,0,prices,memo);
            return ret = max(sell,skip);
        }
    }
};
