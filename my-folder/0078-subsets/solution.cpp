class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& nums, int idx, vector<int> v) {
        if(idx >= nums.size()) {
            ans.push_back(v);
            return;
        }

        v.push_back(nums[idx]);
        generate(nums,idx+1,v);
        v.pop_back();
        generate(nums,idx+1,v);
        
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        generate(nums,0,{});
        return ans;
    }
};
