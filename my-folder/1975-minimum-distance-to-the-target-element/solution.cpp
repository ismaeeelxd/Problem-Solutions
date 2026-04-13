class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_ = 1e9;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == target) {
                min_ = min(min_, abs(i - start));
            }
        }
        return min_;
    }
};
