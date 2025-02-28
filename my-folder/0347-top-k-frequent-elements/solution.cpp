class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapz;
        for(int i = 0;i<nums.size();++i){
            mapz[nums[i]]++;
        }

        std::vector<std::pair<int, int>> vec(mapz.begin(), mapz.end());

        std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;  // Change `<` to `>`
        });
        vector<int>ans;
        for(int i = 0;i< vec.size() && k ; ++i){
            ans.push_back(vec[i].first);
            k--;
        }
        return ans;
    }
};
