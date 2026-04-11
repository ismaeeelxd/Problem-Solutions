class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int minIdx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(min(nums[i], nums[minIdx]) == nums[i]) minIdx = i;
        }
        int minNumberBeforeIdx = INT_MAX;
        for(int i = 0; i < minIdx; ++i){
            minNumberBeforeIdx = min(minNumberBeforeIdx, nums[i]);
            if(i > 0) {
                if(nums[i] < nums[i-1]) return -1;
            }
        } 

        for(int i = minIdx; i < nums.size(); ++i){
            if(nums[i] > minNumberBeforeIdx) return -1;            
            if(i > 0) {
                if(nums[i] < nums[i-1] && i != minIdx) return -1;
            }

        } 

        return (nums.size() - minIdx) % nums.size();

    }
};
