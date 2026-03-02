class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& candidates, int target, int idx,  vector<int> &v, int sum) {
        if(idx >= candidates.size()) {
            if(target == sum) {
                ans.push_back(v);
            }
            return;
        }
        if(sum > target) return;
        v.push_back(candidates[idx]);
        generate(candidates,target,idx+1,v,sum+candidates[idx]);
        v.pop_back();
        int next_idx = idx + 1;
        while (next_idx < candidates.size() && candidates[next_idx] == candidates[idx]) {
            next_idx++;
        }
        generate(candidates,target,next_idx,v,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v = {};
        generate(candidates, target, 0, v, 0);
        return ans;
    }
};
