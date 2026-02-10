class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int max_ = 0;
        for(int i = 0; i < s.size(); ++i) {
            int c = s[i];
            if(!mp.count(c)) {
                mp[c] = i;
                int sz = mp.size();
                max_ = max(sz, max_);
            }
            else {
                int oldIndex = mp[c]; // 0
                vector<int> toBeDeleted;
                for(auto &[character, index] : mp) {
                    if(index <= oldIndex) toBeDeleted.push_back(character);
                } 
                for(auto character : toBeDeleted) {
                    mp.erase(character);
                }
                mp[c] = i;
                int sz = mp.size();
                max_ = max(sz, max_);
            }  
        }

        return max_;

    }
};
