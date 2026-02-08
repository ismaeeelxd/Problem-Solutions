class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size(), 1);
        vector<int> prefix(nums.size(), 1);

        for(int i = 1, j = nums.size() - 2; i < nums.size(); ++i, j--) {
            prefix[i]*=(nums[i-1] * prefix[i-1]);
            suffix[j]*=(nums[j+1] * suffix[j+1]);

        }

        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) res.push_back(suffix[i] * prefix[i]);
        return res;
    }   
};
