class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> mp;
        vector<string> ret;
        string a = "";
        for(int i = 0;i < s.size(); ++i){
            a.push_back(s[i]);
            if(!mp.contains(a)){
                mp.insert(a);
                ret.push_back(a);
                a.clear();
            }
        }

        return ret;
    }
};
