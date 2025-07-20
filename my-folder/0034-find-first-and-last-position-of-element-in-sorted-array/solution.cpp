class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> ans = {-1 , -1};
        int idx = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                right = mid - 1;
                idx = mid;
            } 
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        ans[0] = idx;
        left = 0;
        right = n - 1;
        idx = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left = mid + 1;
                idx = mid;
            } 
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        ans[1] = idx;
        return ans;
    }
};
