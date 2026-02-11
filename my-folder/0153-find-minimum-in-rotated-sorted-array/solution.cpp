class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n - 1]) return nums[0];
        int low = 0;
        int high = n - 1;
        int right = nums[high];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int num = nums[mid];
            if(num < right) {
                high = mid - 1;
            } else if (num > right) low = mid + 1;
            else break;
        }

        return nums[low];
    }
};
