class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // 2 sorted parts 2 3 0 1 rotates
        // sorted bl 3aks 1 0 3 2 reverse then rotate
        // already sorted
        // needs reverse only
        int ops = 0;
        bool sorted = true;
        bool reverseSorted = true;

        for(int i = 0; i < n - 1; ++i) {
           if(nums[i] > nums[i + 1]) sorted = false;
            if(nums[i] < nums[i + 1]) reverseSorted = false; 
        }
        if(sorted) return ops;
        if(reverseSorted) return 1;
        int i = 0;
        while(i < n - 1 && nums[i + 1] - nums[i] == 1) {
            ++i;
        }
        int k = i + 1;
        while(k < n - 1 && nums[k + 1] - nums[k] == 1) {
            ++k;
        }
        ops = 1e9;
        if(i == 0 && k == n - 1) ops = min(ops,1);
        if(k == n - 1 && i == n - 2) ops=min(ops,3);
        
        if(k == n - 1) {
            ops = min(ops,i + 1);
            ops = min(ops, n - (i + 1) + 2);
            return ops;
        }

        i = 0;
        while(i < n - 1 && nums[i] - nums[i + 1] == 1) ++i;
        k = i + 1;
        while(k < n - 1 && nums[k] - nums[k + 1] == 1) ++k;
        if(i == 0 && k == n - 1) return 2;
        if(i == n - 2 && k == n - 1) return 2;
        int nums1 = i + 1;
        int nums2 = n - (i + 1);
        
        if(k == n - 1) {
            return min(1 + nums2, nums1 + 1);
        }


        
        return -1;
    }
};
