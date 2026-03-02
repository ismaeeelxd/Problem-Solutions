class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& candidates, int target, int idx, vector<int> v, int sum) {
        if(idx >= candidates.size()) {
            if(sum == target) ans.push_back(v);
            return;
        }

        if(sum > target) return;

        v.push_back(candidates[idx]);
        sum+=candidates[idx];
        generate(candidates, target, idx, v, sum);
        // generate(candidates,target,idx+1,v,sum);
        sum-=candidates[idx];
        v.pop_back();
        generate(candidates,target,idx+1,v,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        generate(candidates,target,0,{},0);
        return ans;
    }
};
