class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 10);
        unordered_map<int,int> freq_map;
            
        for(int i = 0; i < nums.size(); ++i) {
            freq_map[nums[i]]++;
        }

        for(auto &[key, value] : freq_map) {
            buckets[value].push_back(key);
        }

        vector<int> res;
        for(int i = buckets.size() - 1; i >=0 && res.size() != k; --i) {
            if(buckets[i].size() > 0) {
                for(int j = 0; j < buckets[i].size() && res.size() != k; ++j) {
                    res.push_back(buckets[i][j]);
                }
            }
        }
        return res;
    }
};
