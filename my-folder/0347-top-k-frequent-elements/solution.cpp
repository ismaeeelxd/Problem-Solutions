class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> t;
        for(auto const &a : nums){
            t[a]++;
        }
        vector<vector<int>> arr(nums.size()+1);
        for(auto const &c : t){
            arr[c.second].push_back(c.first);
        }
        int cnt= 0;
        vector<int> res{};
        for(size_t i = arr.size()-1;i>=0 and res.size()<k;--i){
            for(auto const &a : arr[i]){
                res.push_back(a);
                if(res.size()==k)
                    return res;
            }
        }
        return res;

    }
};
