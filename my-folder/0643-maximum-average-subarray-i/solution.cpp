class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int totalSum = 0;
        for(int i = 0; i < k; ++i){
            totalSum+=nums[i];
        }
        int maxS = totalSum;
        for(int i = k; i < nums.size(); ++i){
            totalSum-=nums[i - k];
            totalSum+=nums[i];
            maxS = max(totalSum,maxS);
        }

        return (double)maxS / k;
    }
};
