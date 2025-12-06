class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(auto&num : nums) sum+=num;
        int res = 0;
        int cumu = 0;
        for(int i = 0; i < nums.size() - 1; ++i) {
            cumu+= nums[i];
            sum-= nums[i];
            if((cumu - sum) % 2 == 0) res++;
        }
        return res;
    }
};
