class Solution {
public:
    string makeFancyString(string s) {
        string b = "";
        int count = 0;
        for(int i = 0; i < s.size(); ++i){
            if(!b.empty() && count == 2 && s[i] == b.back()) continue;
            if(!b.empty() && s[i] != b.back()) count = 0;
            b.push_back(s[i]);
            count++;
        }
        return b;
    }
};
