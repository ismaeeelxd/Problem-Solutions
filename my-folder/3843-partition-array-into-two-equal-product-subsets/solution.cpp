class Solution {
public: 
    bool solve(int i, long long currentTarget, long long& target, vector<int>& nums) {
        if(currentTarget == 1) return true;
        if(i >= nums.size()) return false;
        bool take = false;
        if(currentTarget % nums[i] == 0) {
            take = solve(i + 1, currentTarget / nums[i], target, nums);
        }
        bool leave = solve(i+1, currentTarget, target, nums);
        return take || leave;

    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        unsigned long long total = 1;
        unsigned long long prd = (unsigned long long)target * target;
        for(int i = 0; i < nums.size(); ++i) total*=nums[i];
        if(total != prd) return false;
        return solve(0, target, target, nums);
    }
};
