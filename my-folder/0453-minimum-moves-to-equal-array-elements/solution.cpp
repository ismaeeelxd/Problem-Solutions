class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_ = nums[0];
        for(auto num : nums) {
            min_ = min(num, min_);
        }
        int sum = 0;
        for(auto num : nums) {
            sum+=(num - min_);
        }

        return sum;

    }
};
