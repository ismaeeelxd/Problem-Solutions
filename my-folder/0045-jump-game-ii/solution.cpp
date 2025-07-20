class Solution {
public:
    int memo[10001];
    int dp(int i, vector<int>&nums){
        if(i >= nums.size()) return 1e5;
        if(i == nums.size()-1) return 0;
        auto &ret = memo[i];
        if(ret != -1) return ret; 
        int n = nums.size();
        int min_ = 1e5;
        for(int j = 1; j <= nums[i]; ++j){
            if(i + j >= n) continue;
            min_ = min(dp(i + j, nums) + 1 , min_);
        }
        return ret = min_;
    }
    int jump(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return dp(0,nums);
    }
};
