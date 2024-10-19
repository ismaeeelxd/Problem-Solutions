class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(),strs.end());
        string frst = strs[0];
        string lst = strs[strs.size()-1];
        for(size_t i = 0;i<min(frst.size(),lst.size());++i){
            if(frst[i] != lst[i])
                return ans;
            ans+=lst[i];
        }
        return ans;
    }
};
