class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto str: strs) {
            string orig = str;
            sort(str.begin(), str.end());
            mp[str].push_back(orig);
        }
        vector<vector<string>> res;
        for(auto [key, value] : mp) {
            res.push_back(value);
        }
        return res;
    }
};
