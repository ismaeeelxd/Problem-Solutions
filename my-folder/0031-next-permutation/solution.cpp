class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(!nums.size() || nums.size() == 1) return;
        bool isMax = true;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i-1]) isMax = false; 
        }
        if(isMax) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int ptr = nums.size() - 1;
        while(nums[ptr-1] >= nums[ptr]) ptr--;
        
    
        int target = nums[ptr-1];
        int ptr_2 = nums.size() - 1;
        while(nums[ptr_2] <= target) ptr_2--;
        swap(nums[ptr_2], nums[ptr-1]);

        // sort from ptr_2 till nums.size()

        int lastptr = nums.size() - 1;
        int newptr = ptr;
        while(newptr < lastptr) {
            swap(nums[newptr++], nums[lastptr--]);
        }
        return;
    }
};
