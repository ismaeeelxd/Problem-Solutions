class Solution {
public:
    int minOperations(string s) {
        string s1 = "";
        string s2 = "";
        for(int i = 0; i < s.size(); ++i) {
            if(i % 2 == 0) {
                s1.push_back('0');
                s2.push_back('1');
            } else {
                s1.push_back('1');
                s2.push_back('0');
            }
        }

        int ret = 0;
        int ret2 = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != s1[i]) ret++;
            if(s[i] != s2[i]) ret2++;
        }
        return min(ret,ret2);
    }
};
