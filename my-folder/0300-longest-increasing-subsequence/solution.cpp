class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int memo[2501][2501];
        memset(memo,-1,sizeof(memo));
        return LIS(0,-1,nums, memo);
    }
    int LIS(int idx, int prevIdx,vector<int>&nums, int (&memo)[2501][2501]){
        if(idx == nums.size())
            return 0;
        auto &ret = memo[idx][prevIdx + 1];
        if(ret!= -1)
            return ret;
        
        int take = -1e9;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1 + LIS(idx+1,idx,nums, memo);
        }
        int leave = LIS(idx+1,prevIdx,nums, memo);
        return ret = max(take,leave);
    }
};
