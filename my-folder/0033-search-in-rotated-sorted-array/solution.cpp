class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // 4 5 6 7 | 0 1 2
        int left = nums[0]; // 4
        int right = nums[n-1]; // 2

        // 0
        if(target > left) {
            // start searching from left
            int low = 0;
            int high = n - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int num = nums[mid];
                if(num < left) {
                    high = mid - 1;
                    continue;
                }

                if(num < target) {
                    low = mid + 1;
                } else if(num > target) high = mid - 1;
                else return mid;
            }



        } else if (target < left) {
            // start searching from right
            if(target == right) return n-1;

            int low = 0;
            int high = n - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int num = nums[mid];
                if(num > right) {
                    low = mid + 1;
                    continue;
                }

                if(num < target) {
                    low = mid + 1;
                } else if(num > target) high = mid - 1;
                else return mid;
            }

        } else {
            return 0;
        }
        return -1;
    }
};
