class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int pairs = nums.size()/2;
        int i = 0;
        int sum = 0;
        while(pairs){
            sum+=nums[i];
            i+=2;
            pairs--;
        }
        return sum;
    }
};
