class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int sum = 0;
        if (nums[0] >= 0) {
            if(nums[0] == 0) k = 0;
            if(k%2==0) k = 0;
            if(k) nums[0] = -nums[0];
            for (const auto& num : nums)
                sum += num;
            return sum;
        }

        while (i < nums.size() && nums[i] < 0 && k) {
            nums[i] = -nums[i];
            k--;
            ++i;
        }
        if(i == nums.size()) i--;
        if (k % 2 == 0 || nums[i] == 0) {
            for (int j = 0; j < nums.size(); ++j)
                sum += nums[j];
            return sum;
        }
        
        if (nums[i] > nums[i - 1]) {
            nums[i - 1] = -nums[i - 1];
            for (int j = 0; j < nums.size(); ++j)
                sum += nums[j];
            return sum;
        } else {
            nums[i] = -nums[i];
            for (int j = 0; j < nums.size(); ++j)
                sum += nums[j];
            return sum;
        }
    }
};
