class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int i = 0;
        int j = 1;
        for(; j < s.size(); ++j){
            if(s[i] == s[j]) continue;
            else{
                if(j  - i >= 3){
                    ans.push_back({i , j - 1});
                }
                i = j;
            }
        }

        if(j - i >= 3){
            ans.push_back({i , j - 1});
        }
        return ans;
    }
};
