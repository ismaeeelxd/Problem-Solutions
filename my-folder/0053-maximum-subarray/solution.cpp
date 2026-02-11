class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = INT_MIN;
        int curSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            curSum+=nums[i];
            maxSoFar = max(curSum, maxSoFar);
            if(curSum < 0) curSum = 0;
        }
        return maxSoFar;
    }
};
