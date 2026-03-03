class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& nums,  vector<int> &v, vector<bool> &visited) {
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        } else if(v.size() > nums.size()) return;


        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
                if(visited[i]) continue;
                v.push_back(num);
                visited[i] = true;
                generate(nums,v,visited);
                visited[i] = false;
                v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<bool> visited(nums.size(),0);
        generate(nums, v, visited);
        return ans;
    }
};
