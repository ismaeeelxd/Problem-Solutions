class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int memo[100001][2];
        memset(memo,-1,sizeof(memo));
        return solve(0,1,prices,memo);
    }

    int solve(int day ,bool canBuy,vector<int>&prices,int memo[][2]){
        if(day == prices.size()){
            return 0;
        }

        if(memo[day][canBuy] != -1)
            return memo[day][canBuy];

        if(canBuy){
            int buy = -prices[day] + solve(day+1,0,prices,memo);
            int skip = solve(day+1,1,prices,memo);
            return memo[day][canBuy] =  max(buy,skip);
        } else {
            int skip = solve(day+1,0,prices,memo);
            
            return memo[day][canBuy] =  max(prices[day],skip);
        }
    }
};
