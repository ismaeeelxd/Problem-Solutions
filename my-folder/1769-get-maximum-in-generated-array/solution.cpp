class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1);
        if(n == 0){
            return 0;
        }
        nums[0] = 0;
        nums[1] = 1;
        int i = 1;
        int maxNumber = 1;
        while(i < n + 1){
            if(2*i >= 2 && 2*i <= n){
                nums[2*i] = nums[i];
                maxNumber = max(nums[2*i] , maxNumber);
            } 
            if(2*i+1 >=2 && 2*i+1 <=n){
                nums[2*i+1] = nums[i] + nums[i+1];
                maxNumber = max(nums[2*i+1],maxNumber);
            } 
            ++i;
        }
        return maxNumber;
    }
};
