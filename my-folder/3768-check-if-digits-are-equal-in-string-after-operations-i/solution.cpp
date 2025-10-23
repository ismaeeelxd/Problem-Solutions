class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2) {
            string a;
            int i = 0;
            int j = 1;
            while(i < s.size() && j < s.size()) {
                int num = (s[i] + s[j]) % 10;
                a.push_back(num - '0');
                i++;
                j++;
            }
            s = a;
        }
        if(s[0] == s[1]) return true;
        return false;
    }
};
