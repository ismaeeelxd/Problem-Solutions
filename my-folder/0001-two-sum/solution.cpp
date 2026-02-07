class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); ++i) mp[nums[i]] = i + 1;

        for(int i = 0; i < nums.size(); ++i) if(mp[target - nums[i]]) {
            if((i + 1) == mp[target - nums[i]]) continue;
            return { i, mp[target - nums[i]] - 1 };
        }

        return {};
    }
};
