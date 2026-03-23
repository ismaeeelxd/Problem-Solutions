class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& memo) {
        if(i >= nums.size()) return 0;
        auto &ret = memo[i];
        if(ret != -1) return ret;
        int take = solve(i+2, nums, memo) + nums[i];
        int leave = solve(i+1, nums, memo);
        return ret = max(take, leave);

    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(0, nums, memo);
    }
};
