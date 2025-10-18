class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> s;
        int last_placed = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            int candidate = max(last_placed + 1, nums[i] - k);
            if(candidate <= nums[i] + k) {
                last_placed = candidate;
                s.insert(last_placed);
            }
        }
        return s.size();
    }
};
