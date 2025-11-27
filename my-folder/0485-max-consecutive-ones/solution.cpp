class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ = 0;
        int cur = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1) cur++;
            else cur = 0;
            max_ = max(cur,max_);
        }
        return max_;
    }
};
