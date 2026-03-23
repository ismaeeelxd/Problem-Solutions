class Solution {
public:
    
    int getMin(int i, vector<int>& cost, vector<int>& memo) {
        if(i == cost.size()) return 0;
        else if(i > cost.size()) return 1e8;
        auto &ret = memo[i];
        if(ret != -1) return memo[i];
        int opt1 = getMin(i+1, cost, memo) + cost[i];
        int opt2 = getMin(i+2, cost, memo) + cost[i];
        return ret = min(opt1, opt2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        return min(getMin(0, cost, memo), getMin(1, cost, memo));
    }
};
