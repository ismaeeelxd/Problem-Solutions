class Solution {
public:
int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int curMax = prices[0];
        int diff = 0;
        for(size_t i = 1;i<prices.size();++i){
            if(prices[i] < curMin){
                if(curMax - curMin > diff)
                    diff = curMax - curMin;
                curMax = -1;
                curMin = prices[i];
            } else {
                if(prices[i] > curMax)
                    curMax = prices[i];
            }
        }

        if(curMax - curMin > diff)
            diff = curMax - curMin;

        return diff;
}};
