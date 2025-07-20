class Solution {
public:
    int memo[10001];
    bool dp(int i, vector<int>&nums){
        if(i >= nums.size()) return false;
        if(i == nums.size() - 1) return true;
        auto &ret = memo[i];
        if(ret != -1) return ret;
        for(int j = 1; j <= nums[i]; ++j){
            bool canReach = dp(i+j,nums);
            if(!canReach) continue;
            else return ret = true;
        }
        return ret = false;
    }
    bool canJump(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return dp(0,nums);
    }
};
