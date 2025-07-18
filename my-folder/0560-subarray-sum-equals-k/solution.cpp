class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int currentSum = 0;
        int count = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            currentSum+=nums[i];
            if(mp.count(currentSum - k)) count+=mp[currentSum-k];
            mp[currentSum]++;
        }
        return count;
    }
};
