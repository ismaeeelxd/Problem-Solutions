class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        bool arr[10002];
        int j = 0;
        int maxSum = -1;
        int curSum = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(arr[nums[i]]){
                while(j < nums.size() && nums[j] != nums[i]){
                    arr[nums[j]] = 0;
                    curSum-=nums[j];
                    j++;
                }
                arr[nums[j]] = 0;
                curSum-=nums[j];
                j++; 
            }
            arr[nums[i]] = 1;
            curSum+=nums[i];
            maxSum = max(maxSum , curSum);

        }
        return maxSum;
    }
};
