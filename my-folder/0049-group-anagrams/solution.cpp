class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapz;
        for(int i = 0;i<strs.size();++i){
            string sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            mapz[sorted].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto i : mapz){
            ans.push_back(i.second);
        }
        return ans;
    }
};
