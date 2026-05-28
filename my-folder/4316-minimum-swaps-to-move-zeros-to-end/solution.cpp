class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(j >= 0 && nums[j] == 0) j--;
        int ops = 0;
        while(i < j) {
            if(nums[i] == 0) {
                swap(nums[i], nums[j]);
                ops++;
            } else {
                ++i;
                continue;
            }
            ++i;
            j--;
            while(j >= 0 && nums[j] == 0) j--;
        }
        return ops;
    }
};
