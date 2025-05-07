class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i<nums.size();++i)
            sum+= nums[i];
        if(sum % 2 != 0) return false;
        int memo[205][20005];
        for(int i = 0;i<205;++i){
            for(int j = 0;j<20005;++j)
                memo[i][j] = -1;
        }
        bool answer  = partition(nums,sum/2,0,0, memo);
        return answer;
    }


    bool partition(vector<int>&nums, int target, int idx, int prevSum, int memo[205][20005]){
        if(nums.size() == idx){
            return false;
        }
        
        if(prevSum + nums[idx] == target)
            return true;

        if(memo[idx][prevSum] != -1){
            return memo[idx][prevSum];
        }
        bool take = partition(nums,target,idx+1,prevSum + nums[idx] , memo);
        bool leave = partition(nums,target,idx+1, prevSum, memo);
        if(take == false && leave == false){
            memo[idx][prevSum] = 0;
            return false;
        }
        memo[idx][prevSum] = 1;
        return true;
        
    }
};
