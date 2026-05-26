class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int min_ = 1e9;
        for(int i = 0; i < nums.size(); ++i) {
            int acc = nums[i];
            if(acc >= k) {
                min_ = 1;
                continue;
            }
            for(int j = i + 1; j < nums.size(); ++j) {
                acc|=nums[j];
                if(acc >= k) {
                    min_ = min(j - i + 1, min_);
                }
            }
        }
        return min_ == 1e9 ? -1 : min_;
    }
};
