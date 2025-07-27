class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // i is a hill if the two different numbers than it are smaller than nums[i]
        // i is a part of a vallery if the two different numbers than it are larger than nums[i]

        int left = 0;
        int right = 2;
        int count = 0;
        int n = nums.size();
        for(int i = 1; i < n - 1; ++i){
            while(right < n && nums[right] == nums[i]) right++;
            // 2 4 1
            // 2 4 1 1 6 5
            // 
            if(right < n && nums[left] < nums[i] && nums[right] < nums[i]) count++;
            if(right < n && nums[left] > nums[i] && nums[right] > nums[i]) count++;
            left = i;
            i = right-1;
        }
        return count;
    }
};
