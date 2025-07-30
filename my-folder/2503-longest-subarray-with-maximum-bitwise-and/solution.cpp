class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN;
        for(int i = 0; i < n; ++i) largest=max(nums[i],largest);
        int maxSoFar = 0;
        int ls = 0;
        nums.push_back(INT_MIN);
        n++;
        for(int i = 0; i < n; ++i){
            if(nums[i] == largest) ls++;
            else{
                maxSoFar = max(maxSoFar,ls);
                ls = 0;
            } 
        }

        
        return maxSoFar;
    }
};
