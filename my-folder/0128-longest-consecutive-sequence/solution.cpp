class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int max_seq = 1;
        int counter = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == (nums[i-1]+1)) {
                counter++;
                max_seq = max(counter + 1, max_seq);
            } else if(nums[i] == nums[i-1]) continue; 
            else {
                counter = 0;
            }
        }
        return max_seq;
    }
};
