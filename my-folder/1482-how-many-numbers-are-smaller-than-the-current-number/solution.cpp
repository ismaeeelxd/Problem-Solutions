class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> count(101,0);
        for(int i = 0; i < n; ++i) {
            count[nums[i]]++;
        }

        vector<int> prefix(101,0);
        prefix[0] = 0;
        for(int i = 1; i < 101; ++i) {
            prefix[i] = prefix[i-1] + count[i-1];
        }

        for(int i = 0; i < n; ++i) {
            res[i] = prefix[nums[i]];
        }

        return res;        
    }
};
