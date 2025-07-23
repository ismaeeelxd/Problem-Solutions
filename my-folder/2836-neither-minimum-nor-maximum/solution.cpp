class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {

        int min_ = INT_MAX;
        int max_ = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            min_ = min(min_,nums[i]);
            max_ = max(max_,nums[i]);
        }
        cout<< min_;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == min_ || nums[i] == max_) continue;
            else return nums[i];
        }
        return -1;
    }
};
