class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumAllDouble = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] / 10 != 0) sumAllDouble+=nums[i];
            sum+=nums[i];
        }
        int single = sum - sumAllDouble;
        if(sumAllDouble > single || single > sumAllDouble) return true;
        return false;
    }
};
